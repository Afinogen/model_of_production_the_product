/*
 * channel.h
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#ifndef SRC_LIB_CHANNEL_H_
#define SRC_LIB_CHANNEL_H_

#include <stdlib.h>
#include "random.h"
#include "request.h"
#include "timer.h"

// ласс канала
class Channel: public Timer
{
    public:
        Channel();
        Channel(const int rand_a, const int rand_b);
        ~Channel();
        void setRequest(Request *request);  //установка за€вки на обработку
        void DeleteRequest();  //удаление за€вки из канала
        void GenTime();  //√енераци€ времени обработки
        Request *GetRequest() const;  //«а€вка
        void setRandomTime(const int rand_a, const int rand_b);  //”становка границ рандома
    private:
        Request *processes_request_;  //«а€вка дл€ обработки
        int rand_a_;  //границы рандома времени обработки
        int rand_b_;
};

#endif  // SRC_LIB_CHANNEL_H_
