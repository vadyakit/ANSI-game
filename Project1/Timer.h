#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <ctime>
#include <Thread>
#include "Event.h"
#pragma once

class Timer;
class TimerEventArgs;
class TimerController;

class TimerEventArgs : public shittEvent::EventArgs {
public:
	TimerEventArgs(Timer& timer);
	const Timer& timerObject() const;
};

class Timer
{
public:
	std::string name;
	unsigned duration;
	bool isCircle;
	Timer(std::string name, unsigned duration, bool isCircle = false);
	Timer(const Timer& timer);
	bool operator > (const Timer& t) const;
	bool operator < (const Timer& t) const;
};

class TimerController
{
	shittEvent::EventHandler OnTime;
	std::vector<Timer> timers;
	bool finish;

	TimerController(std::function<void(Timer timer)> TimerCallback);
	void AddTimer(Timer timer);
	void RemoveTimer(std::string name);
	void RemoveAllTimers();
	void StartTimer();
};
