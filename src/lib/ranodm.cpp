/*
 * ranodm.cpp
 *
 *  Created on: 16.03.2013
 *      Author: Afinogen
 */

#include "random.h"

Random::Random()
{

}

Random::~Random()
{

}

double Random::GetRand()
{
    time_t t;
    t = time(NULL);

    int r = ((rand() * 214013L + 2531011L) >> 16) & t;
    r %= RAND_MAX;

    return r;
}

double Random::GetRand(const int a, const int b)
{
    int r = GetRand();

    r = a + r % (b - a + 1);
    if (r < a) r = a;
    if (r > b) r = b;
    return r;
}
