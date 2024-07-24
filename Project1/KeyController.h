#include <functional>
#include "Event.h"
#pragma once

using namespace shittEvent;

class KeyController
{
	bool stop;
	

public:
	KeyController();

	void StartKeyMonitoring1();
	//void StartKeyMonitoring2();s
	void StopKeyMonitoring();
	//~KeyController();

	EventHandler OnKeyDown;
	EventHandler OnKeyUp;
};

