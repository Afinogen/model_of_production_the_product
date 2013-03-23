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

//Функция руссификации текста для консоли
char * Rus(const char *text);
//Перевод из char* в int
int CharToInt(const char *str);
//Установка позиции курсора в консоли
void setCursosPosition(short x, short y);
//Перевод из int в char*
char *IntToChar(int num);
//Узнаем откуда было запушено приложение
bool isConsole();

#endif /* FUNCTION_H_ */
