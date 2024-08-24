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
	inline static timerId last_id;
	timerId id;
	unsigned duration;
public:
	bool isCyclic;
	Timer(unsigned duration, const std::string& name = "", bool isCyclic   = false);
	timerId getId() const;
	std::string getName();
	bool operator > (const Timer& t) const;
	bool operator < (const Timer& t) const;
};

class TimerController
{
public:
	shittEvent::EventHandler OnTimer;
	std::vector<Timer> timers;
	time_t lastCheckTime;
	bool restart{false};
	bool finish{false};
	bool isRun{false};
	//unsigned minDurationStep = 50; //ms
	unsigned minStepOfTimerCheck = 50; //ms

	TimerController(std::function<void(Timer timer)> TimerCallback);
	void addTimer(const Timer& timer);
	void removeTimersByName(std::string name);
	void removeTimerById(timerId id);
	void removeAllTimers();
	void start();
	void stop();
private:

};
