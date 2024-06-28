#include <vector>
#include <string>
#include <queue>
#pragma once

enum EventType
{
	Timer,
	KeyDown,
	KeyUp,
	Collision
};

class Event
{
	void AddParam(void* param);
	void AddParams(std::vector<void*> params);
	EventType eventType;
	time_t eventTime;
	std::vector<void*> params;
};

//queue with max size size
template <typename T>
class AQueue
{
	std::queue<T> queue;
	unsigned const max_size = 100;

public:
	AQueue() : max_size;
	void push(const T& elem);
	void pop();
	T front() const;
	T back() const;
};

class EventController 
{
    
};