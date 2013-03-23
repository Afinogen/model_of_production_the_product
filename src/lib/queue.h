/*
 * queue.h
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#ifndef SRC_LIB_QUEUE_H_
#define SRC_LIB_QUEUE_H_

#include "container.h"
#include "request.h"

//Класс очередь
class Queue: public Container
{
    public:
        Queue();
        ~Queue();
        int GetCountRequestFromType(const int type) const;  //Получение кол-ва заявок заданного типа
        void DeleteRequestFromType(const int type);  //Удаление заявки заданного типа
    private:

};

#endif  // SRC_LIB_QUEUE_H_
