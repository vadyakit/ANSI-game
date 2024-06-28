#include "Timer.h"


Timer::Timer(std::string name, unsigned duration)
{
	this->duration = duration;
	this->name = name;
}

void TimerController::StartTimer()
{
	std::sort(timers.begin(), timers.end());
	std::vector<double> total_times(timers.size());
	unsigned current_time;

	while (!finish)
	{
		current_time = clock();
		for (int i = 0; i < timers.size(); i++)
		{
			if (current_time - total_times[i] >= timers[i].duration)
			{
				TimerCallback(timers[i]);
				total_times[i] = current_time;
			}
		}
	}
}

void TimerController::AddTimer(struct Timer timer)
{
	timers.push_back(timer);
}

void TimerController::RemoveTimer(std::string name)
{
	auto id_iter = std::find_if(timers.begin(), timers.end(), [name](const Timer& x) {return x.name == name;});
	if (id_iter == timers.end()) throw "attempt to remove an existing timer id";
	timers.erase(id_iter);
	if (timers.size() == 0) finish = true;
}

void TimerController::RemoveAllTimers()
{
	finish = true;
	timers.clear();
}
