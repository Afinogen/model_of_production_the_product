/*
 * controller.cpp
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#include "controller.h"

Controller::Controller()
{

}

Controller::~Controller()
{
    for (unsigned int i = 0; i < array_channel_.size(); i++)
        delete array_channel_[i];
    array_channel_.clear();
    for (unsigned int i = 0; i < array_valve_.size(); i++)
        delete array_valve_[i];
    array_valve_.clear();
}

void Controller::CreateChannel(const int count_channel)
{
    for (int i = 0; i < count_channel; i++)
        array_channel_.push_back(new Channel());
}

void Controller::CreateValve(const int count_valve)
{
    for (int i = 0; i < count_valve; i++)
        array_valve_.push_back(new Valve());
}

Channel *Controller::GetChannel(const int idx) const
{
    if (idx < 0 || idx >= array_channel_.size()) return NULL;
    return array_channel_[idx];
}
Valve *Controller::GetValve(const int idx) const
{
    if (idx < 0 || idx >= array_valve_.size()) return NULL;
    return array_valve_[idx];
}

void Controller::DecTimeAllChannel()
{
    for (unsigned int i = 0; i < array_channel_.size(); i++)
        array_channel_[i]->DecTime();
}
