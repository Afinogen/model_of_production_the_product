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
}

Channel::~Channel()
{

}

void Channel::setRequest(Request *request)
{
    if (request == NULL) return;

    processes_request_ = request;
}

void Channel::DeleteRequest()
{
    processes_request_ = NULL;
}

Request *Channel::GetRequest() const
{
    return processes_request_;
}
