/*
 * timer.h
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#ifndef SRC_LIB_TIMER_H_
#define SRC_LIB_TIMER_H_

// ласс таймера
class Timer
{
    public:
        Timer();
        Timer(const int time);
        ~Timer();
        void IncTime();  //инкримент времени
        void DecTime();  //декримент времени
        void setTime(const int time);  //установка времени
        int GetTime() const;  //получение времени
    private:
        int time_;
};

#endif  // SRC_LIB_TIMER_H_
