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

UINT_PTR hTimer = NULL;     //��������� �� ������
bool pause = false;

//������� �������
VOID CALLBACK TimerProc(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime)
{
    if (pause) return;
    if (g_system_timer->GetTime() == 1) system("cls");  //��� ������ ������� ������ ����������� �� ������, ���������� ������ �������
    setCursosPosition(0, 0);
    StepEmulation();
    PrintTimer();
    PrintSourceState();
    PrintQueueState();
    PrintChannelState();
    PrintCollectorState();

    if (CheckEndEmulation())
    {
        KillTimer(hWnd, hTimer);
        hTimer = NULL;
        ClearSMO();
        pause = false;
        SetWindowText(g_hwnd_button_start_pause, "�����");
        PostQuitMessage(0);
    }
}

//������� �������
int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance,
        LPSTR lpszArgument, int nFunsterStil)
{
    MSG messages; /* Here messages to the application are saved */

    CONSOLE_SCREEN_BUFFER_INFO info;  // ��� ��������� ������� ������� �������

    g_instance = hThisInstance;

    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);  // ��������� ������ ������
    GetConsoleScreenBufferInfo(hCon, &info);  // �������� ���������� � ������� �������

    if (info.dwCursorPosition.Y == 0) FreeConsole();
    else
    {
        system("cls");
        setCursosPosition(0, 0);
    }
    CreateForm(hThisInstance);
    CreateLabel();
    CreateEdit();
    CreateButton();
    ShowWindow(g_hwnd_form, nFunsterStil);

    //char buf[10] = {'\0'};
    //printf("%s\n",buf);
    //scanf("%s", buf);

    //InitSMO(50, 2);    //CharToInt(buf));
    //PostQuitMessage(0);
    //hTimer = SetTimer(NULL, 0, 100, &TimerProc);  //������ �������

    //for(int i=0;i<10;i++)
    //printf("%f\n", Random::GetRand(1,5));
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
            if ((HWND) lParam == g_hwnd_button_start_pause && hTimer == NULL)
            {
                GetWindowText(g_hwnd_edit_request_count, str_request_count,
                        255);
                GetWindowText(g_hwnd_edit_work_count, str_work_count, 255);
                InitSMO(CharToInt(str_request_count),
                        CharToInt(str_work_count));
                hTimer = SetTimer(NULL, 0, 100, &TimerProc);
                SetWindowText(g_hwnd_button_start_pause, "�����");
            }
            else if ((HWND) lParam == g_hwnd_button_start_pause&& hTimer!=NULL)
            {
                if (pause)
                {
                    pause = false;
                    SetWindowText(g_hwnd_button_start_pause, "�����");
                }
                else
                {
                    pause = true;
                    SetWindowText(g_hwnd_button_start_pause, "����������");
                }

            }
            if ((HWND) lParam == g_hwnd_button_stop)
            {
                if (hTimer != NULL)
                {
                    KillTimer(hwnd, hTimer);
                    Sleep(100);
                    hTimer = NULL;
                    ClearSMO();
                    pause = false;
                }
                SetWindowText(g_hwnd_button_start_pause, "�����");
            }
        break;
        case WM_KEYDOWN:
            if (wParam == VK_SPACE && hTimer != NULL)
            {
                if (pause)
                {
                    pause = false;
                    SetWindowText(g_hwnd_button_start_pause, "�����");
                }
                else
                {
                    pause = true;
                    SetWindowText(g_hwnd_button_start_pause, "����������");
                }
            }
        break;
        case WM_CLOSE:
            if (hTimer != NULL)
            {
                KillTimer(hwnd, hTimer);
                ClearSMO();
            }
            PostQuitMessage(0);
        break;
        case WM_DESTROY:
            if (hTimer != NULL)
            {
                KillTimer(hwnd, hTimer);
                ClearSMO();
            }

            PostQuitMessage(0); /* send a WM_QUIT to the message queue */
        break;
        default: /* for messages that we don't deal with */
            return DefWindowProc(hwnd, message, wParam, lParam);
    }

    return 0;
}

