/*
 * valve.h
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#ifndef SRC_LIB_VALVE_H_
#define SRC_LIB_VALVE_H_

#include <stdlib.h>
#include "channel.h"

//Класс клапана
class Valve
{
    public:
        Valve();
        Valve(Channel *channel);
        ~Valve();
        void setChannel(Channel *channel);  //привязка канала к клапану
        Channel *GetChannel() const;  //привязка канала к клапану
        bool GetStateChannel() const;  //получение состояние канала
    private:
        Channel *control_channel_;  //канала которым управляет клапан
};

#endif  // SRC_LIB_VALVE_H_
