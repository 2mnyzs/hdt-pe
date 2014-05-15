#pragma once

#include <cstdlib>
#include <cstdio>

#include <typeinfo>

#include <memory>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cassert>
#include <atomic>

#include <unordered_set>
#include <unordered_map>

#include "log.h"
#include "inisetting.h"
#include "exception.h"
	
#define PLUGIN_NAME "hdtPhysicsExtensions"

extern Logger *g_Log;

template <class T, int maxsize>
class Queue : public Lockable
{
public:

	Queue(){ _front = _back = 0; }

	T& operator[](int idx) { return _buffer[(_front+idx)%maxsize]; }
	void pushBack(const T& a) { _buffer[_back++] = a; _back%=maxsize; }
	void popFront() { _front = (_front+1)%maxsize; }

	T& front(){ return _buffer[_front]; }
	T& back(){ return _buffer[_back]; }

	bool isFull(){ return (_back+1)%maxsize == _front; }
	bool isEmpty(){ return _back==_front; }

	UINT size(){ return (_back+maxsize-_front)%maxsize; }

private:

	T _buffer[maxsize];
	UINT _front;
	UINT _back;
};