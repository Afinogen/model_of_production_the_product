/*
 * random.h
 *
 *  Created on: 16.03.2013
 *      Author: Afinogen
 */

#ifndef RANDOM_H_
#define RANDOM_H_

#include <time.h>
#include <stdlib.h>

class Random
{
    public:
        Random();
        ~Random();
        static double GetRand();
        static double GetRand(const int a, const int b);
    private:
};

#endif /* RANDOM_H_ */
