/*
 * random.h
 *
 *  Created on: 16.03.2013
 *      Author: Afinogen
 */

#ifndef SRC_LIB_RANDOM_H_
#define SRC_LIB_RANDOM_H_

#include <time.h>
#include <stdlib.h>

//Класс рандома
class Random
{
    public:
        Random();
        ~Random();
        static double Rand();  //случайное число от 0 до RAND_MAX
        static double Rand(const int a, const int b);  //Случайное число от а до b
    private:
};

#endif  // SRC_LIB_RANDOM_H_
