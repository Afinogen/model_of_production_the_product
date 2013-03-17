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

extern Source *g_source_a;  //��������� ������ ���� �
extern Source *g_source_b;  //��������� ������ ���� �
extern Source *g_source_c;  //��������� ������ ���� �
extern Source *g_source_d;  //��������� ������ ���� D
extern Source *g_source_e;  //��������� ������ ���� E
extern Source *g_source_f;  //��������� ������ ���� F
extern Source *g_source_g;  //��������� ������ ���� G
extern Source *g_source_h;  //��������� ������ ���� H

extern Timer *g_system_timer;  //��������� �����

extern Queue *g_queue1;  //������� 1 (������ 1)
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
//��� ��������
void StepEmulation();
//�������� ���������� ��������
bool CheckEndEmulation();
//��������� ������
void GenerationRequests();
//����������� ������ �� ������ � �������
void MovingRequestFromChannelToQueue();
//����������� ������ �� ������� � �����
void MovingRequestFromQueueToChannel();
//�������� ������� 1, � ��� ������ �������������� ��� �������� ��� �������� � �����
bool Queue1IsReady();
//�������� ������� 2, � ��� ������ �������������� ��� �������� ��� �������� � �����
bool Queue2IsReady();
//�������� ������� 3, � ��� ������ �������������� ��� �������� ��� �������� � �����
bool Queue3IsReady();
//�������� ������� 4, � ��� ������ �������������� ��� �������� ��� �������� � �����
bool Queue4IsReady();
//�������� ������� 5, � ��� ������ �������������� ��� �������� ��� �������� � �����
bool Queue5IsReady();
//�������� ������� 6, � ��� ������ �������������� ��� �������� ��� �������� � �����
bool Queue6IsReady();
//�������� ������� 7, � ��� ������ �������������� ��� �������� ��� �������� � �����
bool Queue7IsReady();
//����� �� ����� ��������� ����������� ������
void PrintSourceState();
//����� ���������� �������
void PrintTimer();

#endif /* FUNCTION_LIBSMO_H_ */
