/*
 * main.cpp
 *
 *  Created on: 14.03.2013
 *      Author: Afinogen
 */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "form_control.h"
#include "function_libsmo.h"
#include "function.h"

using namespace std;

UINT_PTR hTimer = NULL;     //указатель на таймер
bool pause = false;

//Функция таймера
VOID CALLBACK TimerProc(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime)
{
    if (pause) return;
    if (g_system_timer->GetTime() == 1 && isConsole())
    {
        system("cls");  //При первом запуске бывает абракадабра на экране, необходима полная очистка
        setCursosPosition(0, 0);
    }
    StepEmulation();  //шаг эмуляции
    PrintTimer();  //вывод модельного времени
    PrintSourceState();  //вывод состояния источников
    PrintQueueState();  //вывод состояния очередей
    PrintChannelState();  //вывод состояния каналов
    PrintCollectorState();  //вывод состояния сборщика

    if (CheckEndEmulation())  //проверка завершения эмуляции
    {
        KillTimer(hWnd, hTimer);  //остановка таймера
        hTimer = NULL;
        ClearSMO();  //очистка системы
        pause = false;
        SetWindowText(g_hwnd_button_start_pause, "Старт");
    }
}

//Главная функция
int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance,
        LPSTR lpszArgument, int nFunsterStil)
{
    MSG messages; /* Here messages to the application are saved */

    g_instance = hThisInstance;

    if (!isConsole()) FreeConsole();
    else
    {
        system("cls");
        setCursosPosition(0, 0);
    }
    CreateForm(hThisInstance);  //создание формы
    CreateLabel();  //создание текста на фоме
    CreateEdit();  //создание поей ввода
    CreateButton();  //создание кнопок
    ShowWindow(g_hwnd_form, nFunsterStil);  //вывод формы

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage(&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam,
        LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc;
    char str_request_count[255] = {'\0'};
    char str_work_count[255] = {'\0'};

    switch (message)
    /* handle the messages */
    {
        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);

            EndPaint(hwnd, &ps);
        break;
        case WM_COMMAND:
            if ((HWND) lParam == g_hwnd_button_start_pause && hTimer == NULL)  //Обработка нажатия кнопки старт
            {
                GetWindowText(g_hwnd_edit_request_count, str_request_count,
                        255);
                GetWindowText(g_hwnd_edit_work_count, str_work_count, 255);
                InitSMO(CharToInt(str_request_count),
                        CharToInt(str_work_count));
                hTimer = SetTimer(hwnd, 1, 100, &TimerProc);
                SetWindowText(g_hwnd_button_start_pause, "Пауза");
            }
            else if ((HWND) lParam == g_hwnd_button_start_pause&& hTimer!=NULL)  //обработка нажатия кнопки пауза
            {
                if (pause)
                {
                    pause = false;
                    SetWindowText(g_hwnd_button_start_pause, "Пауза");
                }
                else
                {
                    pause = true;
                    SetWindowText(g_hwnd_button_start_pause, "Продолжить");
                }

            }
            if ((HWND) lParam == g_hwnd_button_stop)  //обработка нажатия кнопки стоп
            {
                if (hTimer != NULL)
                {
                    KillTimer(hwnd, hTimer);
                    hTimer = NULL;
                    ClearSMO();
                    pause = false;
                }
                SetWindowText(g_hwnd_button_start_pause, "Старт");
            }
        break;
        case WM_KEYDOWN:
            if (wParam == VK_SPACE && hTimer != NULL)
            {
                if (pause)
                {
                    pause = false;
                    SetWindowText(g_hwnd_button_start_pause, "Пауза");
                }
                else
                {
                    pause = true;
                    SetWindowText(g_hwnd_button_start_pause, "Продолжить");
                }
            }
        break;
        case WM_CLOSE:
            if (hTimer != NULL)
            {
                KillTimer(hwnd, hTimer);
                //hTimer = NULL;
                //ClearSMO();
            }
            PostQuitMessage(0);
        break;
        case WM_DESTROY:
            if (hTimer != NULL)
            {
                KillTimer(hwnd, hTimer);
                //hTimer = NULL;
                //ClearSMO();
            }

            PostQuitMessage(0); /* send a WM_QUIT to the message queue */
        break;
        default: /* for messages that we don't deal with */
            return DefWindowProc(hwnd, message, wParam, lParam);
    }

    return 0;
}

