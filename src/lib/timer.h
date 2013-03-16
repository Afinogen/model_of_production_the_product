/*
 * timer.h
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#ifndef SRC_LIB_TIMER_H_
#define SRC_LIB_TIMER_H_

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

#endif  // SRC_LIB_TIMER_H_
