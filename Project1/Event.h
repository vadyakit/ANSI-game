#include <vector>
#include <string>
#include <queue>
#include <list>
#include <functional>
#include <string>
#include <algorithm>
#pragma once

namespace shittEvent {

	class EventArgs;
	template <typename UnusedType> class Delegate;
	template <typename returntype, typename ...argtypes> class Delegate <returntype(argtypes...)>;
	template <typename T> class AQueue;
	class Event;
	class EventHandler;

	using EventArg = void*;
	using callbackType = void(EventArgs);
	using EventQueue = AQueue<Event>;

	enum EventType
	{
		Undefined,
		TimerEvent,
		KeyDownEvent,
		KeyUpEvent,
		KeyPressedEvent,
		CollisionEvent
	};

	//класс для хранения аргументов функции
	class EventArgs
	{
	public:
		EventArgs() = default;
	protected:
		std::vector<EventArg> args;
		EventArgs(const std::vector<EventArg>& pargs);
		size_t size() const;
		EventArg operator [](int i) const;
	};

	template <typename UnusedType>
	class Delegate;

	template <typename returntype, typename ...argtypes>
	class Delegate <returntype(argtypes...)>
	{
		using functype = returntype(*)(argtypes...);
		//std::list<std::function<returntype(argtypes...)>> functions;
		std::list<functype> functions;
	public:
		void operator () (argtypes... args) {
			for (auto f : functions)
				f(args...);
		};
		void operator += (const functype& func) { functions.push_back(func); };
		void operator -= (const functype& func) { functions.erase(std::remove_if(functions.begin(), functions.end(), [&func](auto& f) {return f == func;})); };
	};

	class Event
	{
	public:
		Delegate<callbackType> callbacks;
		EventArgs args;
		EventType eventType;
		Event(const Delegate<callbackType>& callbacks, const EventArgs& args, EventType eventType = EventType::Undefined);
	};

	//очередь с ограниченным размером, если элемент не вмещается то выкидывается последний элемент для освобождения места спереди
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
		bool empty();
		const unsigned max_size;
	};

	//Вызывает коллбэки для события либо кидает событие в очередь событий, это нужно для разделения потоков вызова и обработки 
	class EventHandler : public Delegate<callbackType>
	{
		EventQueue* eventQueue;
	public:
		void set_eventQueue(EventQueue* eventQueue);
		void set_eventQueue(EventQueue& eventQueue);
		void operator () (const EventArgs& args);
	};

	// Вытаскивает события из очереди событий и вызывает соотвествующие коллбэки
	class EventListener
	{
		EventQueue* eventQueue;
		EventListener(const EventQueue& eventQueue);
		EventListener(const EventQueue* eventQueue);

		void Listen();
		void stopListen();

	};
}