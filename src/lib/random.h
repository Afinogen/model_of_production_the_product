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

//����� �������
class Random
{
    public:
        Random();
        ~Random();
        static double Rand();  //��������� ����� �� 0 �� RAND_MAX
        static double Rand(const int a, const int b);  //��������� ����� �� � �� b
    private:
};

#endif  // SRC_LIB_RANDOM_H_
