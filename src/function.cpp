/*
 * function.cpp
 *
 *  Created on: 16.03.2013
 *      Author: Afinogen
 */
#include "function.h"

//������� ������������ ������ ��� �������
char *Rus(const char *text)
{
    char buffer[256] = {'\0'};  //new char[strlen(text) + 1];
    //if (NULL == buffer) return "";
    AnsiToOem(text, buffer);
    return buffer;
}

//������� �� char* � int
int CharToInt(const char *str)
{
    return atoi(str);
}

//��������� ������� ������� � �������
void setCursosPosition(short x, short y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //��������� ������ �������
    COORD cor = {x, y};       //����������� ������ �� �������
    SetConsoleCursorPosition(hConsole, cor);
}
