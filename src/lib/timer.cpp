/*
 * timer.cpp
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#include "timer.h"

Timer::Timer()
{
    time_ = 0;
}

Timer::Timer(const int time)
{
    time_ = time;
}

Timer::~Timer()
{

}
//инкримент времени
void Timer::IncTime()
{
    ++time_;
}
//декримент времени
void Timer::DecTime()
{
    --time_;
}
//получение времени
int Timer::GetTime() const
{
    return time_;
}
//установка времени
void Timer::setTime(const int time)
{
    time_ = time;
}

