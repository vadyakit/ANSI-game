#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <string>
#pragma once

typedef void* EventArg;

	enum EventType
	{
		Timer,
		KeyDown,
		KeyUp,
		KeyPressed,
		Collision
	};

	class EventArgs
	{
	protected:
		const std::vector<EventArg> args;
		EventArgs() = default;
		EventArgs(const std::vector<EventArg>& pargs);
		size_t size() const;
		EventArg operator [](int i) const;
	};

	class Event
	{
		EventArgs args;
		EventType eventType;
	};

	//queue with max size size
	template <typename T>
	class AQueue
	{
		std::queue<T> queue;

	public:
		AQueue(unsigned maxsize);
		void push(const T& elem);
		void pop();
		T front() const;
		T back() const;
		const unsigned max_size;
	};

	class KeyEventArgs : public EventArgs
	{
	public:
		KeyEventArgs(char key);
		char keyValue() const;
	};

	class TimerEventArgs : public EventArgs
	{
	public:
		TimerEventArgs(double duration, std::string name);
		double duration() const;
		std::string name() const;
	};

	typedef std::function<void(EventArgs*)> EventHandler;
