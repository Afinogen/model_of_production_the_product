/*
 * form_control.cpp
 *
 *  Created on: 19.03.2013
 *      Author: Afinogen
 */

#include "form_control.h"

HWND g_hwnd_form; /* This is the handle for our window */
HWND g_hwnd_edit_request_count;
HWND g_hwnd_edit_work_count;
HWND g_hwnd_button_start_pause;
HWND g_hwnd_button_stop;
HWND g_hwnd_time_gen_sourse;
HWND g_hwnd_time_gen_request;
HWND g_hwnd_sys_time;
HWND g_hwnd_redy_queue;
HWND g_hwnd_count_request_queue;
HWND g_hwnd_all_request_info;
HWND g_hwnd_channel_info;
HWND g_hwnd_channel_time;
HWND g_hwnd_count_request_collection;
HINSTANCE g_instance;

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

void CreateForm(HINSTANCE hInstance)
{
    WNDCLASSEX wincl;
    /* The Window structure */
    wincl.hInstance = hInstance;
    wincl.lpszClassName = "Form";
    wincl.lpfnWndProc = WindowProcedure; /* This function is called by windows */
    wincl.style = CS_DBLCLKS; /* Catch double-clicks */
    wincl.cbSize = sizeof(WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor(NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL; /* No menu */
    wincl.cbClsExtra = 0; /* No extra bytes after the window class */
    wincl.cbWndExtra = 0; /* structure or the window instance */
    /* Use Windows's default color as the background of the window */
    wincl.hbrBackground = (HBRUSH) (COLOR_WINDOW);

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx(&wincl))
    {
        MessageBox(NULL, "Call to RegisterClassEx failed!", "Win32 Guided Tour",
                NULL);

        return;
    }

    /* The class is registered, let's create the program*/
    g_hwnd_form = CreateWindowEx(0, /* Extended possibilites for variation */
    "Form", /* Classname */
    "������� ��������� ������������. ������ ������������ ��������", /* Title Text */
            WS_MINIMIZEBOX | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS
                    | WS_CAPTION | WS_BORDER | WS_SYSMENU | WS_POPUP,
            //WS_OVERLAPPEDWINDOW, /* default window */
            CW_USEDEFAULT, /* Windows decides the position */
            CW_USEDEFAULT, /* where the window ends up on the screen */
            644, /* The programs width */
            640, /* and height in pixels */
            HWND_DESKTOP, /* The window is a child-window to desktop */
            NULL, /* No menu */
            hInstance, /* Program Instance handler */
            NULL /* No Window Creation data */
            );
}

void CreateEdit()
{
    g_hwnd_edit_request_count = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "50",
            ES_LEFT | ES_NUMBER | WS_VISIBLE | WS_CHILD, 230, 10, 40, 20,
            g_hwnd_form, NULL, g_instance, NULL);
    g_hwnd_edit_work_count = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "7",
            ES_LEFT | ES_NUMBER | WS_VISIBLE | WS_CHILD, 270, 40, 40, 20,
            g_hwnd_form, NULL, g_instance, NULL);
}

void CreateLabel()
{
    CreateWindowEx(0, "STATIC", "������� ���-�� ������",
            ES_LEFT | WS_VISIBLE | WS_CHILD, 10, 10, 200, 20, g_hwnd_form, NULL,
            g_instance, NULL);
    CreateWindowEx(0, "STATIC", "������� ���-�� �������",
            ES_LEFT | WS_VISIBLE | WS_CHILD, 10, 40, 240, 20, g_hwnd_form, NULL,
            g_instance, NULL);
    CreateWindowEx(0, "STATIC", "��������� ����� ",
            ES_LEFT | WS_VISIBLE | WS_CHILD, 10, 120, 240, 20, g_hwnd_form,
            NULL, g_instance, NULL);
    g_hwnd_sys_time = CreateWindowEx(0, "STATIC", "0 ���",
            ES_LEFT | WS_VISIBLE | WS_CHILD, 140, 120, 100, 20, g_hwnd_form,
            NULL, g_instance, NULL);
    CreateWindowEx(0, "STATIC", "����������\t�\t�\t�\n����� ���.\t",
            ES_LEFT | WS_VISIBLE | WS_CHILD, 10, 140, 240, 20, g_hwnd_form,
            NULL, g_instance, NULL);
    CreateWindowEx(0, "STATIC", "����� ���.\t", ES_LEFT | WS_VISIBLE | WS_CHILD,
            10, 160, 240, 20, g_hwnd_form, NULL, g_instance, NULL);
    g_hwnd_time_gen_sourse = CreateWindowEx(0, "STATIC", "0\t0\t0",
            ES_LEFT | WS_VISIBLE | WS_CHILD, 120, 160, 240, 20, g_hwnd_form,
            NULL, g_instance, NULL);
    CreateWindowEx(0, "STATIC", "���-�� ������\t",
            ES_LEFT | WS_VISIBLE | WS_CHILD, 10, 180, 240, 20, g_hwnd_form,
            NULL, g_instance, NULL);
    g_hwnd_time_gen_request = CreateWindowEx(0, "STATIC", "0\t0\t0",
            ES_LEFT | WS_VISIBLE | WS_CHILD, 120, 180, 240, 20, g_hwnd_form,
            NULL, g_instance, NULL);
    CreateWindowEx(0, "STATIC", "�������\t1\t2\t3\t4\t5\t6\t7",
            ES_LEFT | WS_VISIBLE | WS_CHILD, 10, 210, 540, 20, g_hwnd_form,
            NULL, g_instance, NULL);
    g_hwnd_redy_queue = CreateWindowEx(0, "STATIC",
            "����������\t0\t0\t0\t0\t0\t0\t0", ES_LEFT | WS_VISIBLE | WS_CHILD,
            10, 230, 540, 20, g_hwnd_form, NULL, g_instance, NULL);
    g_hwnd_count_request_queue = CreateWindowEx(0, "STATIC",
            "���-�� ������\t0\t0\t0\t0\t0\t0\t0",
            ES_LEFT | WS_VISIBLE | WS_CHILD, 10, 250, 540, 20, g_hwnd_form,
            NULL, g_instance, NULL);
    g_hwnd_all_request_info =
            CreateWindowEx(0, "STATIC",
                    "������ A:\t0\n������ B:\t0\n������ C:\t0\n������ D:\t0\n������ E:\t0\n������ F:\t0\n������ G:\t0",
                    ES_LEFT | WS_VISIBLE | WS_CHILD, 10, 270, 150, 120,
                    g_hwnd_form, NULL, g_instance, NULL);
    CreateWindowEx(0, "STATIC", "������\t\t1\t2\t3\t4\t5\t6\t7",
            ES_LEFT | WS_VISIBLE | WS_CHILD, 10, 390, 500, 20, g_hwnd_form,
            NULL, g_instance, NULL);
    g_hwnd_channel_info = CreateWindowEx(0, "STATIC",
            "���������\t0\t0\t0\t0\t0\t0\t0", ES_LEFT | WS_VISIBLE | WS_CHILD,
            10, 410, 500, 20, g_hwnd_form, NULL, g_instance, NULL);
    g_hwnd_channel_time = CreateWindowEx(0, "STATIC",
            "���������\t0\t0\t0\t0\t0\t0\t0", ES_LEFT | WS_VISIBLE | WS_CHILD,
            10, 430, 500, 20, g_hwnd_form, NULL, g_instance, NULL);
    g_hwnd_count_request_collection = CreateWindowEx(0, "STATIC",
            "������ � ��������:\t0", ES_LEFT | WS_VISIBLE | WS_CHILD, 10, 450,
            240, 20, g_hwnd_form, NULL, g_instance, NULL);
}

void CreateButton()
{
    g_hwnd_button_start_pause = CreateWindowEx(0, "BUTTON", "����",
            BS_PUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_TABSTOP, 20, 70, 170, 30,
            g_hwnd_form, NULL, g_instance, NULL);
    g_hwnd_button_stop = CreateWindowEx(0, "BUTTON", "����",
            BS_PUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_TABSTOP, 200, 70, 170,
            30, g_hwnd_form, NULL, g_instance, NULL);
}
