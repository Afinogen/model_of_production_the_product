/*
 * queue.h
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#ifndef SRC_LIB_QUEUE_H_
#define SRC_LIB_QUEUE_H_

#include "container.h"
#include "request.h"

class Queue: public Container
{
    public:
        Queue();
        ~Queue();
        int GetCountRequestFromType(const int type) const;
        void DeleteRequestFromType(const int type);
    private:

};

#endif  // SRC_LIB_QUEUE_H_
