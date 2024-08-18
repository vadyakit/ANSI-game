#include "Timer.h"


Timer::Timer(unsigned duration, std::string name, bool isCircle) : name(name), duration(duration), isCircle(isCircle), id(last_id++)
{
}

timerId Timer::getId()
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
bool Timer::operator < (const Timer& t) const{
	return duration < t.duration;
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
				OnTimer(TimerEventArgs(timers[i]));
				total_times[i] = current_time;
				if (!timers[i].isCircle) { timers.erase(timers.begin() + i); i--; }
			}
		}
		Sleep(minStepOfTimerCheck);
	}
}

void TimerController::AddTimer(Timer timer)
{
	timers.push_back(timer);
}

void TimerController::RemoveTimer(std::string name)
{
	timers.erase( std::remove_if(timers.begin(), timers.end(), [name](const Timer& x) {return x.name == name;}) );
	if (timers.size() == 0) finish = true;
}

void TimerController::RemoveTimer(timerId id)
{
	timers.erase(std::remove_if(timers.begin(), timers.end(), [id](const Timer& x) {return x.id == id; }) );
	if (timers.size() == 0) finish = true;
}

void TimerController::RemoveAllTimers()
{
	finish = true;
	timers.clear();
}

TimerEventArgs::TimerEventArgs(Timer& timer)
{
	args.push_back(static_cast<void*>(&timer));
}

const Timer& TimerEventArgs::timerObject() const
{
	return *static_cast<Timer*>(args[0]);
}
