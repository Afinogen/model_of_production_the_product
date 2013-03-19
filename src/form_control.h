/*
 * form_control.h
 *
 *  Created on: 19.03.2013
 *      Author: Afinogen
 */

#ifndef FORM_CONTROL_H_
#define FORM_CONTROL_H_

#include <windows.h>

extern HWND g_hwnd_form;               /* This is the handle for our window */
extern HWND g_hwnd_edit_request_count;
extern HWND g_hwnd_edit_work_count;
extern HWND g_hwnd_button_start_pause;
extern HWND g_hwnd_button_stop;
extern HINSTANCE g_instance;

void CreateForm(HINSTANCE hInstance);
void CreateEdit();
void CreateLabel();
void CreateButton();

#endif  // FORM_CONTROL_H_
