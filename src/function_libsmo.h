/*
 * function_libsmo_init.h
 *
 *  Created on: 16.03.2013
 *      Author: Afinogen
 */

#ifndef FUNCTION_LIBSMO_H_
#define FUNCTION_LIBSMO_H_

#include "lib/lib.h"

extern Source *g_source_a;  //��������� ������ ���� �
extern Source *g_source_b;  //��������� ������ ���� �
extern Source *g_source_c;  //��������� ������ ���� �

extern Timer *g_system_timer;  //��������� �����

extern Queue *g_queue1;  //������� 1 (������ 1)
extern Queue *g_queue2;
extern Queue *g_queue3;
extern Queue *g_queue4;
extern Queue *g_queue5;
extern Queue *g_queue6;

extern Controller *g_controller;

extern Collector *g_collector;

extern int g_count_piece;

void InitValveVsChannel();

void InitSMO(const int count_piece);

void ClearSMO();

void StepEmulation();

bool CheckEndEmulation();

//������� �� char* � int
int CharToInt(const char *str);

#endif /* FUNCTION_LIBSMO_H_ */
