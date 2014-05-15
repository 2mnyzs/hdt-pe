#include "Thread.h"
#include "log.h"

Thread::Thread(void)
{
	func = 0;
	arglist = 0;
	m_handle = (HANDLE)_beginthreadex(0, 0, wapper, this, 0, 0);
	m_shouldBegin.reset();
	m_finish.set();
	m_shouldExit = false;
}


Thread::~Thread(void)
{
	m_shouldExit = true;
	wait();
}

unsigned __stdcall Thread::wapper(void* arg)
{
	Thread* t = (Thread*)arg;
	do
	{
		t->m_shouldBegin.wait();
		t->m_shouldBegin.reset();
		if(!t->func)
			continue;

		t->func(t->arglist);
		t->m_finish.set();
	}while((!t->m_shouldExit));

	return 0;
}

int Thread::run(int priority)
{
	if(GetThreadPriority(m_handle) != priority)
	{
		SuspendThread(m_handle);
		SetThreadPriority(m_handle, priority);
		ResumeThread(m_handle);
	}
	m_finish.reset();
	m_shouldBegin.set();

	return 0;
}

void Thread::wait()
{
	m_finish.wait();
}

ThreadLoop::ThreadLoop()
{
	m_eResume.set();
	m_eLoopFinish.reset();
	m_thread.func = wrapper;
	m_thread.arglist = this;

	m_uDuration = 1;
	m_bRun = 0;
}

ThreadLoop::~ThreadLoop()
{
	if(m_bRun)
		EndLoop();
}

void ThreadLoop::wrapper(void* p)
{
	auto self = (ThreadLoop*)p;
	LogInfo("ThreadLoop Begin.");

	self->OnThreadBegin();
	
	while(self->m_bRun)
	{
		self->m_eLoopFinish.reset();
		self->Loop();
		self->m_eLoopFinish.set();
		
		self->m_eResume.wait();
		Sleep(self->m_uDuration);
	}

	self->OnThreadEnd();
}

void ThreadLoop::BeginLoop()
{
	m_bRun = 1;
	m_eResume.set();
	m_eLoopFinish.set();
	m_thread.run();
}

void ThreadLoop::EndLoop()
{
	m_bRun = false;
	m_eResume.set();
	m_thread.wait();
}

void ThreadLoop::Suspend()
{
	m_eResume.reset();
	m_eLoopFinish.wait();
	OnSuspend();
}

void ThreadLoop::Resume()
{
	OnResume();
	m_eResume.set();
}
