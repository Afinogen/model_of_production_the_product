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
    char buffer[256] = {'\0'};  //new char[strlen(text) + 1];
    //if (NULL == buffer) return "";
    AnsiToOem(text, buffer);
    return buffer;
}

//Перевод из char* в int
int CharToInt(const char *str)
{
    return atoi(str);
}
//Перевод из int в char*
char *IntToChar(int num)
{
    char name[50] = {'\0'};
    itoa(num, name, 10);
    return name;
}
//Установка позиции курсора в консоли
void setCursosPosition(short x, short y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //получения хендла консоли
    COORD cor = {x, y};       //коордионаты вывода на консоль
    SetConsoleCursorPosition(hConsole, cor);
}

//Узнаем откуда было запушено приложение
bool isConsole()
{
    CONSOLE_SCREEN_BUFFER_INFO info;  // Для получения текущей позиции курсора

    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);  // получение потока вывода
    GetConsoleScreenBufferInfo(hCon, &info);  // Получаем информацию о позиции курсора

    if (info.dwCursorPosition.Y == 0) return false;
    else return true;
}
