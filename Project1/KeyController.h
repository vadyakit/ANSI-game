#include <thread>
#include <functional>
#pragma once
class KeyController
{
	std::thread thr;
	bool stop;
	std::function<void(char)> OnKeyDownCallback;
	std::function<void(char)> OnKeyUpCallback;
	void EventMonitoring(std::function<void(char)>, std::function<void(char)>, bool&);

public:
	KeyController();
	void setOnKeyDownCallback(std::function<void(char)>);
	void setOnKeyUpCallback(std::function<void(char)>);
	void StartEventMonitoring();
	void StopEventMonitoring();
	~KeyController();
};

