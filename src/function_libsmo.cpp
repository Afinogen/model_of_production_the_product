/*
 * function_libsmo_init.cpp
 *
 *  Created on: 16.03.2013
 *      Author: Afinogen
 */

#include "function_libsmo.h"

Source *g_source_a;  //Генератор заявок типа А
Source *g_source_b;  //Генератор заявок типа В
Source *g_source_c;  //Генератор заявок типа С

Timer *g_system_timer;  //Системное время

Queue *g_queue1;
Queue *g_queue2;
Queue *g_queue3;
Queue *g_queue4;
Queue *g_queue5;
Queue *g_queue6;

Controller *g_controller;

Collector *g_collector;

int g_count_piece;

void InitValveVsChannel()
{
    g_controller->CreateChannel(5);
    g_controller->CreateValve(5);
    g_controller->GetValve(0)->setChannel(g_controller->GetChannel(0));
    g_controller->GetValve(1)->setChannel(g_controller->GetChannel(1));
    g_controller->GetValve(2)->setChannel(g_controller->GetChannel(2));
    g_controller->GetValve(3)->setChannel(g_controller->GetChannel(3));
    g_controller->GetValve(4)->setChannel(g_controller->GetChannel(4));
}

void InitSMO(const int count_piece)
{
    g_source_a = new Source(10, 20, 0);
    g_source_b = new Source(4, 8, 1);
    g_source_c = new Source(7, 13, 2);
    g_system_timer = new Timer();
    g_queue1 = new Queue();
    g_queue2 = new Queue();
    g_queue3 = new Queue();
    g_queue4 = new Queue();
    g_queue5 = new Queue();
    g_queue6 = new Queue();
    g_controller = new Controller();
    InitValveVsChannel();
    g_collector = new Collector();

    g_count_piece = count_piece;
}

void ClearSMO()
{
    delete g_source_a;
    delete g_source_b;
    delete g_source_c;
    delete g_system_timer;
    delete g_queue1;
    delete g_queue2;
    delete g_queue3;
    delete g_queue4;
    delete g_queue5;
    delete g_queue6;
    delete g_controller;
    delete g_collector;
}

void StepEmulation()
{
    g_system_timer->IncTime();
    g_source_a->DecTime();
    g_source_b->DecTime();
    g_source_c->DecTime();
    g_controller->DecTimeAllChannel();
}

bool CheckEndEmulation()
{

}

//Перевод из char* в int
int CharToInt(const char *str)
{
    return atoi(str);
}
