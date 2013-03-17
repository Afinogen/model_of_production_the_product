/*
 * function_libsmo_init.h
 *
 *  Created on: 16.03.2013
 *      Author: Afinogen
 */

#ifndef FUNCTION_LIBSMO_H_
#define FUNCTION_LIBSMO_H_

#include <stdio.h>
#include "lib/lib.h"
#include "function.h"

extern Source *g_source_a;  //Генератор заявок типа А
extern Source *g_source_b;  //Генератор заявок типа В
extern Source *g_source_c;  //Генератор заявок типа С
extern Source *g_source_d;  //Генератор заявок типа D
extern Source *g_source_e;  //Генератор заявок типа E
extern Source *g_source_f;  //Генератор заявок типа F
extern Source *g_source_g;  //Генератор заявок типа G
extern Source *g_source_h;  //Генератор заявок типа H

extern Timer *g_system_timer;  //Системное время

extern Queue *g_queue1;  //Очередь 1 (Клапан 1)
extern Queue *g_queue2;
extern Queue *g_queue3;
extern Queue *g_queue4;
extern Queue *g_queue5;
extern Queue *g_queue6;
extern Queue *g_queue7;

extern Controller *g_controller;

extern Collector *g_collector;

extern int g_count_piece;
extern int g_count_work;

void InitValveVsChannel();

void InitSMO(const int count_piece, const int count_work);

void ClearSMO();
//Шаг эмуляции
void StepEmulation();
//Проверка завершения эмуляции
bool CheckEndEmulation();
//Генерация заявок
void GenerationRequests();
//Перемещение заявки из канала в очередь
void MovingRequestFromChannelToQueue();
//Перемещение заявки из очереди в канал
void MovingRequestFromQueueToChannel();
//Проверка очереди 1, в ней должны присутствовать все элементы для передачи в канал
bool Queue1IsReady();
//Проверка очереди 2, в ней должны присутствовать все элементы для передачи в канал
bool Queue2IsReady();
//Проверка очереди 3, в ней должны присутствовать все элементы для передачи в канал
bool Queue3IsReady();
//Проверка очереди 4, в ней должны присутствовать все элементы для передачи в канал
bool Queue4IsReady();
//Проверка очереди 5, в ней должны присутствовать все элементы для передачи в канал
bool Queue5IsReady();
//Проверка очереди 6, в ней должны присутствовать все элементы для передачи в канал
bool Queue6IsReady();
//Проверка очереди 7, в ней должны присутствовать все элементы для передачи в канал
bool Queue7IsReady();
//Вывод на экран состояния генераторов заявок
void PrintSourceState();
//Вывод системного времени
void PrintTimer();

#endif /* FUNCTION_LIBSMO_H_ */
