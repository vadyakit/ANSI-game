#include "KeyController.h"
#include "conio.h"
#include <thread>
#include <windows.h>

KeyController::KeyController()
{
	stop = true;
}


void KeyController::StartKeyMonitoring1()
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
				OnKeyDown(KeyEventArgs(buf));
				pred = buf;
			}
			Sleep(20);
		}
		else
		{
			if (pred != 0)
			{
				OnKeyUp(KeyEventArgs(buf));
				pred = (char)0;
			}
		}
		if (stop) return;
	}
}

void KeyController::StopKeyMonitoring()
{
	stop = true;
}
