/*
 * channel.cpp
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */
#include "channel.h"

Channel::Channel()
{
    processes_request_ = NULL;
    rand_a_ = 0;
    rand_b_ = 0;
}

Channel::Channel(const int rand_a, const int rand_b)
{
    processes_request_ = NULL;
    rand_a_ = rand_a;
    rand_b_ = rand_b;
}

Channel::~Channel()
{

}
//установка за€вки на обработку
void Channel::setRequest(Request *request)
{
    if (request == NULL) return;

    processes_request_ = request;
    GenTime();
}
//удаление за€вки из канала
void Channel::DeleteRequest()
{
    processes_request_ = NULL;
}
//«а€вка
Request *Channel::GetRequest() const
{
    return processes_request_;
}
//√енераци€ времени обработки
void Channel::GenTime()
{
    setTime(Random::Rand(rand_a_, rand_b_));
}
//”становка границ рандома
void Channel::setRandomTime(const int rand_a, const int rand_b)
{
    rand_a_ = rand_a;
    rand_b_ = rand_b;
}
