/*
 * function.h
 *
 *  Created on: 16.03.2013
 *      Author: Afinogen
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <stdlib.h>
#include <windows.h>

using namespace std;

//������� ������������ ������ ��� �������
char * Rus(const char *text);
//������� �� char* � int
int CharToInt(const char *str);
//��������� ������� ������� � �������
void setCursosPosition(short x, short y);
//������� �� int � char*
char *IntToChar(int num);
//������ ������ ���� �������� ����������
bool isConsole();

#endif /* FUNCTION_H_ */
