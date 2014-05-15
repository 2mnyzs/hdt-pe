#pragma once

#include <Windows.h>
#include <process.h>

class Lockable
{
public:
	Lockable(){ InitializeCriticalSectionAndSpinCount(&cs, 4000); }
	~Lockable(){ DeleteCriticalSection(&cs); }

	void lock(){ EnterCriticalSection(&cs); }
	void unlock(){ LeaveCriticalSection(&cs); }
	
	class Locker
	{
	public:
		Locker(Lockable* obj):object(obj){ object->lock(); }
		~Locker(){ if(object)object->unlock(); }

		Locker(Locker&& rhs):object(rhs.object){ rhs.object = 0; }
		void operator =(Locker&& rhs){ std::swap(object, rhs.object); }

	private:
		Locker(const Locker&);
		void operator =(const Locker&);

		Lockable* object;
	};

	Locker SmartLock(){ return this; }
private:

	Lockable(const Lockable&){}
	Lockable& operator =(const Lockable&){}

	CRITICAL_SECTION cs;
};

class Event
{
public:
	Event(bool state = FALSE):handle(CreateEvent(0, TRUE, state, 0)){}
	~Event(){CloseHandle(handle);}
	int wait(){ return WaitForSingleObject(handle, INFINITE); }
	void set(){ SetEvent(handle); }
	void reset(){ ResetEvent(handle); }

	HANDLE GetHandle(){ return handle; }
protected:
	HANDLE handle;
};

class Thread
{
public:
	Thread(void);
	~Thread(void);

	void* arglist;
	void (*func)(void*);

	int run(int priority = THREAD_PRIORITY_NORMAL);
	void wait();
	HANDLE get_handle(){ return m_handle; }
protected:

	HANDLE m_handle;
	Event m_shouldBegin;
	Event m_finish;
	volatile bool m_shouldExit;
	static unsigned __stdcall wapper(void*);
};

class ThreadLoop
{
public:
	ThreadLoop();
	~ThreadLoop();
	
	void BeginLoop();
	void EndLoop();

	void Suspend();
	void Resume();

	UInt32 m_uDuration;

protected:
	
	virtual void OnSuspend(){};
	virtual void OnResume(){};
	virtual void OnThreadBegin(){};
	virtual void OnThreadEnd(){};
	virtual void Loop() = 0;

	volatile bool m_bRun;
	Event m_eResume;
	Event m_eLoopFinish;
	Thread m_thread;

	static void wrapper(void*);
};