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
// Генерация случайной величины, равномерно распреденной в интервале [0, 1]
double Random::Rand()
{
    time_t t;
    t = time(NULL);

    int r = ((rand() * 214013L + 2531011L) >> 16) & t;
    r %= RAND_MAX;

    return r;
}
// Генерация случайной величины, равномерно распределенной в интервале [a, b]
double Random::Rand(const int a, const int b)
{
    int r = Rand();

    r = a + r % (b - a + 1);
    if (r < a) r = a;
    if (r > b) r = b;
    return r;
}
