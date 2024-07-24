#include "Event.h"
using namespace shittEvent;

//inline void Event::AddParam(void* arg) { args.push_back(arg); }

//inline void Event::AddParams(std::vector<void*> args) { this->args.insert(this->args.end(), args.begin(), args.end()); }

EventArgs::EventArgs(const std::vector<EventArg>& args) : args(args) {

}

template<typename T>
AQueue<T>::AQueue(unsigned maxsize) : max_size{ maxsize }
{

}

template<typename T>
inline void AQueue<T>::push(const T& elem)
{
	queue.push(elem);
}

template<typename T>
inline void AQueue<T>::pop()
{
	queue.pop();
}

template<typename T>
inline T AQueue<T>::front() const
{
	return queue.front();
}

template<typename T>
inline T AQueue<T>::back() const
{
	return queue.back();
}

template<typename T>
bool AQueue<T>::empty()
{
	return queue.empty();
}

KeyEventArgs::KeyEventArgs(char key) : EventArgs(std::vector<EventArg>{&key}) {

}

char KeyEventArgs::keyValue() const
{
	return *static_cast<char*>(args[0]);
}

inline size_t EventArgs::size() const
{
	return args.size();
}

inline EventArg EventArgs::operator[](int i) const
{
	return args[i];
}

void EventHandler::set_eventQueue(EventQueue* eventQueue)
{
	this->eventQueue = eventQueue;
}

void EventHandler::set_eventQueue(EventQueue& eventQueue)
{
	this->eventQueue = &eventQueue;
}

void EventHandler::operator()(const EventArgs& args)
{
	if (eventQueue == nullptr)
		Delegate<callbackType>(args);
	else
		eventQueue->push(Event(*this, args));
}

Event::Event(const Delegate<callbackType>& callbacks, const EventArgs& args, EventType eventType)
{
	this->callbacks = callbacks;
	this->args = EventArgs(args);
	this->eventType = eventType;
}

void EventListener::Listen()
{
	while (true) {
	
		if (!eventQueue->empty()) {
			eventQueue->front().callbacks(eventQueue->front().args);
			eventQueue->pop();
		}
	}
}
