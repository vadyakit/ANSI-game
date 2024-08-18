#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <ctime>
#include <Thread>
#include <windows.h>
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

using timerId = unsigned long;

class Timer
{
	friend class TimerController;
private:
	std::string name;
	static timerId last_id;
	timerId id;
	unsigned duration;
public:
	bool isCircle;
	Timer(unsigned duration, std::string name = "", bool isCircle = false);
	timerId getId();
	std::string getName();
	bool operator > (const Timer& t) const;
	bool operator < (const Timer& t) const;
};

class TimerController
{
	shittEvent::EventHandler OnTimer;
	std::vector<Timer> timers;
	bool finish;
	unsigned minDurationStep = 50; //ms
	unsigned minStepOfTimerCheck = 50; //ms

	TimerController(std::function<void(Timer timer)> TimerCallback);
	void AddTimer(Timer timer);
	void RemoveTimer(std::string name);
	void RemoveTimer(timerId id);
	void RemoveAllTimers();
	void StartTimer();
};
