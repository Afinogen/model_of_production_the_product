/*
 * timer.cpp
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#include "timer.h"

Timer::Timer()
{
	time_=0;
}

Timer::Timer(const int time)
{
	time_=time;
}

Timer::~Timer()
{

}

void Timer::IncTime()
{
	time_++;
}

void Timer::DecTime()
{
	time_--;
}

int Timer::GetTime() const
{
	return time_;
}

void Timer::setTime(const int time)
{
	time_=time;
}

