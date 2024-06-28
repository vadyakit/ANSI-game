#include "Event.h"

inline void Event::AddParam(void* param) { params.push_back(param); }

inline void Event::AddParams(std::vector<void*> params) { this->params.insert(this->params.end(), params.begin(), params.end()); }

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
