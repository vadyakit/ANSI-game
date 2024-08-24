#include "Timer.h"

#include <mutex>


Timer::Timer(unsigned duration, const std::string& name, bool isCyclic)
{
	this->name = name;
	this->duration = duration;
	this->id = last_id++;
	this->isCyclic = isCyclic;
}

timerId Timer::getId() const
{
	return id;
}

std::string Timer::getName()
{
	return name;
}

bool Timer::operator > (const Timer& t) const {
	return duration > t.duration;
}
bool Timer::operator < (const Timer& t) const {
	return duration < t.duration;
}

void TimerController::start()
{
restart:
	restart = false;
	isRun = true;
	finish = false;

	std::sort(timers.begin(), timers.end());

	unsigned currentTime;

	while (1)
	{
		currentTime = clock();
		for (auto i = timers.begin(); i != timers.end(); ++i)
		{
			if (currentTime - lastCheckTime >= (*i).duration)
			{
				OnTimer(TimerEventArgs((*i)));
				if (!(*i).isCyclic)
				{
					timers.erase(i); --i;
				}
			}
		}
		lastCheckTime = currentTime;
		Sleep(minStepOfTimerCheck);
		if (restart) goto restart;
		if (finish) break;
	}
	isRun = false;
	finish = true;
}

void TimerController::stop()
{
	finish = true;
	while (isRun)
		Sleep(1);
}

void TimerController::addTimer(const Timer& timer)
{
	timers.push_back(timer);
	restart = true;
}

void TimerController::removeTimersByName(std::string name) //async
{
	timers.erase(std::remove_if(timers.begin(), timers.end(), [name](const Timer& x) {return x.name == name; }));
	restart = true;
}

void TimerController::removeTimerById(timerId id)
{
	timers.erase(std::remove_if(timers.begin(), timers.end(), [id](const Timer& x) {return x.id == id; }));
	restart = true;
}

void TimerController::removeAllTimers()
{
	stop();
	timers.clear();
	restart = true;
}

TimerEventArgs::TimerEventArgs(Timer& timer)
{
	args.push_back(static_cast<void*>(&timer));
}

const Timer& TimerEventArgs::timerObject() const
{
	return *static_cast<Timer*>(args[0]);
}
