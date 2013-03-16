/*
 * channel.h
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#ifndef SRC_LIB_CHANNEL_H_
#define SRC_LIB_CHANNEL_H_

#include <stdlib.h>
#include "request.h"
#include "timer.h"

class Channel: public Timer
{
    public:
        Channel();
        ~Channel();
        void setRequest(Request *request);
        void DeleteRequest();
        Request *GetRequest() const;
    private:
        Request *processes_request_;
};

#endif  // SRC_LIB_CHANNEL_H_
