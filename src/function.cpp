/*
 * function.cpp
 *
 *  Created on: 16.03.2013
 *      Author: Afinogen
 */
#include "function.h"

//Функция руссификации текста для консоли
char *Rus(const char *text)
{
    char buffer[256] = {'\0'};//new char[strlen(text) + 1];
    //if (NULL == buffer) return "";
    AnsiToOem(text, buffer);
    return buffer;
}

