#include <vector>
#include <string>
#include <functional>
#include <algorithm>
#include <ctime>
#include <Thread>
#pragma once

struct Timer 
{
	std::string name;
	unsigned duration;
	Timer(std::string name, unsigned duration);
	bool operator > (const Timer& t);
	bool operator < (const Timer& t);
};

class TimerController
{
	//static std::thread thr;
	std::function<void(struct Timer timer)> TimerCallback;
	std::vector<struct Timer> timers;
	bool finish;

	TimerController(std::function<void(struct Timer timer)> TimerCallback);
	void AddTimer(struct Timer timer);
	void RemoveTimer(std::string name);
	void RemoveAllTimers();
	void StartTimer();
};
