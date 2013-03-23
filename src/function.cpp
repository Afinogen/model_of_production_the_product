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
//������� �� int � char*
char *IntToChar(int num)
{
    char name[50] = {'\0'};
    itoa(num, name, 10);
    return name;
}
//��������� ������� ������� � �������
void setCursosPosition(short x, short y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //��������� ������ �������
    COORD cor = {x, y};       //����������� ������ �� �������
    SetConsoleCursorPosition(hConsole, cor);
}

//������ ������ ���� �������� ����������
bool isConsole()
{
    CONSOLE_SCREEN_BUFFER_INFO info;  // ��� ��������� ������� ������� �������

    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);  // ��������� ������ ������
    GetConsoleScreenBufferInfo(hCon, &info);  // �������� ���������� � ������� �������

    if (info.dwCursorPosition.Y == 0) return false;
    else return true;
}
