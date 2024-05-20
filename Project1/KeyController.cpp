#include "KeyController.h"
#include "conio.h"
#include <thread>
#include <windows.h>

KeyController::KeyController()
{
	OnKeyDownCallback = nullptr;
	OnKeyUpCallback = nullptr;
	stop = true;
}

void KeyController::setOnKeyDownCallback(std::function<void(char)> callbackFunc)
{
	OnKeyDownCallback = callbackFunc;
}

void KeyController::setOnKeyUpCallback(std::function<void(char)> callbackFunc)
{
	OnKeyUpCallback = callbackFunc;
}

void KeyController::EventMonitoring(std::function<void(char)> OnKeyDownCallback, std::function<void(char)> OnKeyUpCallback, bool& stop)
{
	char pred = (char)0;
	char buf = (char)0;

	while (true)
	{
		if (_kbhit())
		{
			buf = _getch();

			_ungetch('k');
			while (_getch() != 'k');

			if (buf != pred)
			{
				if (OnKeyDownCallback != nullptr) {
					OnKeyDownCallback(buf);
				}
				pred = buf;
			}
			Sleep(20);
		}
		else
		{
			if (pred != 0) {
				if (OnKeyUpCallback != nullptr) {
					OnKeyUpCallback(buf);
				}
				pred = (char)0;
			}
		}
		if (stop) return;
	}
}

void KeyController::StartEventMonitoring()
{
	stop = false;
	thr = std::thread(&KeyController::EventMonitoring, this, OnKeyDownCallback, OnKeyUpCallback, std::ref(stop));
}

void KeyController::StopEventMonitoring()
{
	stop = true;
}

KeyController::~KeyController()
{
	StopEventMonitoring();
}