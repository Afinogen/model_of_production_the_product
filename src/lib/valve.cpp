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
//привязка канала к клапану
void Valve::setChannel(Channel *channel)
{
    control_channel_ = channel;
}
//привязка канала к клапану
Channel *Valve::GetChannel() const
{
    return control_channel_;
}
//получение состояние канала
bool Valve::GetStateChannel() const
{
    if (control_channel_->GetRequest() != NULL) return true;
    else return false;
}
