/*
 * main.cpp
 *
 *  Created on: 14.03.2013
 *      Author: Afinogen
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "lib\lib.h"

using namespace std;

//Функция таймера
VOID CALLBACK TimerProc(HWND hWnd, UINT nMsg, UINT nIDEvent, DWORD dwTime)
{

}

//Главная функция
int WINAPI WinMain(HINSTANCE hThisInstance, HINSTANCE hPrevInstance,
		LPSTR lpszArgument, int nFunsterStil)
{
	MSG messages; /* Here messages to the application are saved */

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

	switch (message)
	/* handle the messages */
	{
		case WM_PAINT:
			hdc=BeginPaint(hwnd, &ps);

			EndPaint(hwnd, &ps);
		break;
		case WM_COMMAND:
		break;
		case WM_CLOSE:

			PostQuitMessage(0);
		break;
		case WM_DESTROY:

			PostQuitMessage(0); /* send a WM_QUIT to the message queue */
		break;
		default: /* for messages that we don't deal with */
			return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}

