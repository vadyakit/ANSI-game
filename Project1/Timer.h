#include <vector>
#include <functional>
#include <algorithm>
#include <ctime>
#include <Thread>
#pragma once

struct TimerEvent
{
	static inline int id{ 0 };
	double duration;
	std::function<void()> TimerCallback;

	TimerEvent(double duration, std::function<void()>& TimerCallback);

	bool operator < (const TimerEvent& x);
	bool operator > (const TimerEvent& x);
};

class Timer
{
	std::thread thr;
	std::vector<TimerEvent> time_events;
	unsigned const max_threads = 1;
	bool finish;

	void AddTimer(TimerEvent tevent);
	void RemoveTimer(int id);
	void StartTimerThread();
	void StartTimer(std::vector<TimerEvent> time_events, bool& finish);
	void FinishTimerThread();
};

