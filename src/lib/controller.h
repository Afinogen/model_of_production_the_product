/*
 * controller.h
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#ifndef SRC_LIB_CONTROLLER_H_
#define SRC_LIB_CONTROLLER_H_

#include <vector>
#include "channel.h"
#include "valve.h"

using std::vector;

class Controller
{
    public:
        Controller();
        ~Controller();
        void CreateChannel(const int count_channel);
        void CreateValve(const int count_valve);
        Channel *GetChannel(const int idx) const;
        Valve *GetValve(const int idx) const;
        void DecTimeAllChannel();
    private:
        vector<Channel*> array_channel_;
        vector<Valve*> array_valve_;
};

#endif  // SRC_LIB_CONTROLLER_H_
