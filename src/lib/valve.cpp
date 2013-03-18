/*
 * valve.cpp
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#include "valve.h"

Valve::Valve()
{
    control_channel_ = NULL;
}

Valve::Valve(Channel *channel)
{
    control_channel_ = channel;
}

Valve::~Valve()
{

}

void Valve::setChannel(Channel *channel)
{
    control_channel_ = channel;
}

Channel *Valve::GetChannel() const
{
    return control_channel_;
}

bool Valve::GetStateChannel() const
{
    if (control_channel_->GetRequest() != NULL) return true;
    else return false;
}
