#include "Timer.h"

TimerEvent::TimerEvent(double duration, std::function<void()>& TimerCallback)
{
	id++;
	this->duration = duration;
	this->TimerCallback = TimerCallback;
}

bool TimerEvent::operator < (const TimerEvent& x)
{
	return duration < x.duration;
}

bool TimerEvent::operator > (const TimerEvent& x)
{
	return duration > x.duration;
}

void Timer::StartTimerThread()
{
	finish = false;
	thr = std::thread(&Timer::StartTimer, this, time_events, std::ref(finish));
}

void Timer::StartTimer(std::vector<TimerEvent> time_events, bool& finish)
{
	std::sort(time_events.begin(), time_events.end());
	std::vector<double> total_times(time_events.size());
	double current_time;

	while (!finish)
	{
		current_time = clock();
		for (int i = 0; i < time_events.size(); i++)
		{
			if (current_time - total_times[i] >= time_events[i].duration)
			{
				time_events[i].TimerCallback();
				total_times[i] = current_time;
			}
		}
	}
}

void Timer::FinishTimerThread() { finish = true; }

void Timer::AddTimer(TimerEvent t_event)
{
	FinishTimerThread();
	time_events.push_back(t_event);
	StartTimerThread();
}

void Timer::RemoveTimer(int id)
{
	FinishTimerThread();
	auto id_iter = std::find_if(time_events.begin(), time_events.end(), [id](const TimerEvent& x) {return x.id == id;});
	if (id_iter == time_events.end()) throw "attempt to remove an existing timer id";
	time_events.erase(id_iter);
	StartTimerThread();
}
