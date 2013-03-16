/*
 * source.h
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#ifndef SRC_LIB_SOURCE_H_
#define SRC_LIB_SOURCE_H_

#include "random.h"
#include "request.h"
#include "timer.h"

class Source: public Timer
{
    public:
        Source(const int rand_a, const int rand_b, const int type);
        ~Source();
        bool GetState() const;
        Request *GetNewRequest(const int time_gen);
        void GenTime();
        int GetCountGenRequest() const;
    private:
        int rand_a_;
        int rand_b_;
        int type_;
        int count_gen_request_;
};

#endif  // SRC_LIB_SOURCE_H_
