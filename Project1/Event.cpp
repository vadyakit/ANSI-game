#include "Event.h"

//inline void Event::AddParam(void* arg) { args.push_back(arg); }

//inline void Event::AddParams(std::vector<void*> args) { this->args.insert(this->args.end(), args.begin(), args.end()); }

EventArgs::EventArgs(const std::vector<EventArg>& args) : args{args} {

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

KeyEventArgs::KeyEventArgs(char key) : EventArgs(std::vector<EventArg>{&key}) {

}

char KeyEventArgs::keyValue() const
{
	return *(char*)args[0];
}

inline size_t EventArgs::size() const
{
	return args.size();
}

inline EventArg EventArgs::operator[](int i) const
{
	return args[i];
}
