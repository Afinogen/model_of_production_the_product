/*
 * source.h
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#ifndef SRC_LIB_SOURCE_H_
#define SRC_LIB_SOURCE_H_

#include "random.h"
#include "request.h"
#include "timer.h"

//Класс источника (генератор)
class Source: public Timer
{
    public:
        Source(const int rand_a, const int rand_b, const int type);
        ~Source();
        bool GetState() const;  //Получение состояние источника
        Request *GetNewRequest(const int time_gen);  //Генерация новой заявки
        void GenTime();  //Генерация времени создания следущей заявки
        int GetCountGenRequest() const;  //Кол-во созданных заявок
    private:
        int rand_a_;  //Границы радома
        int rand_b_;
        int type_;  //тип создаваемых заявок
        int count_gen_request_;  //кол-во созданных заявок
};

#endif  // SRC_LIB_SOURCE_H_
