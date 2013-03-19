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
    "Система массового обслуживания. Модель производства продукта", /* Title Text */
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
    CreateWindowEx(0, "STATIC", "Введите кол-во частей",
            ES_LEFT | WS_VISIBLE | WS_CHILD, 10, 10, 200, 20, g_hwnd_form, NULL,
            g_instance, NULL);
    CreateWindowEx(0, "STATIC", "Введите кол-во рабочих",
            ES_LEFT | WS_VISIBLE | WS_CHILD, 10, 40, 240, 20, g_hwnd_form, NULL,
            g_instance, NULL);
}

void CreateButton()
{
    g_hwnd_button_start_pause = CreateWindowEx(0, "BUTTON", "Пуск",
            BS_PUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_TABSTOP, 20, 70, 170, 30,
            g_hwnd_form, NULL, g_instance, NULL);
    g_hwnd_button_stop = CreateWindowEx(0, "BUTTON", "Стоп",
                BS_PUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_TABSTOP, 200, 70, 170, 30,
                g_hwnd_form, NULL, g_instance, NULL);
}
