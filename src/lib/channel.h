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

class Channel: public Timer
{
    public:
        Channel();
        Channel(const int rand_a, const int rand_b);
        ~Channel();
        void setRequest(Request *request);
        void DeleteRequest();
        void GenTime();
        Request *GetRequest() const;
        void setRandomTime(const int rand_a, const int rand_b);
    private:
        Request *processes_request_;
        int rand_a_;
        int rand_b_;
};

#endif  // SRC_LIB_CHANNEL_H_
