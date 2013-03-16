/*
 * timer.h
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#ifndef TIMER_H_
#define TIMER_H_

class Timer
{
    public:
        Timer();
        Timer(const int time);
        ~Timer();
        void IncTime();
        void DecTime();
        void setTime(const int time);
        int GetTime() const;
    private:
        int time_;
};

#endif /* TIMER_H_ */
