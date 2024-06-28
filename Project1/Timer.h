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
};

class TimerController
{
	//static std::thread thr;
	static std::function<void(struct Timer timer)> TimerCallback;
	static std::vector<struct Timer> timers;
	bool finish;

	TimerController(std::function<void(struct Timer timer)> TimerCallback);
	void AddTimer(struct Timer timer);
	void RemoveTimer(std::string name);
	void RemoveAllTimers();
	void StartTimer();
};
