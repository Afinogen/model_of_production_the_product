/*
 * request.cpp
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#include "request.h"

Request::Request(const int id, const int type, const int prioritet,
        const int time_gen)
{
    id_=id;
    type_=type;
    prioritet_=prioritet;
    time_gen_=time_gen;
    time_in_system_=0;
    time_in_element_=0;
}

Request::~Request()
{

}

