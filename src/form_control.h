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
extern HWND g_hwnd_time_gen_sourse;
extern HWND g_hwnd_time_gen_request;
extern HWND g_hwnd_sys_time;
extern HWND g_hwnd_redy_queue;
extern HWND g_hwnd_count_request_queue;
extern HWND g_hwnd_all_request_info;
extern HWND g_hwnd_channel_info;
extern HWND g_hwnd_channel_time;
extern HWND g_hwnd_count_request_collection;
extern HINSTANCE g_instance;

void CreateForm(HINSTANCE hInstance);
void CreateEdit();
void CreateLabel();
void CreateButton();

#endif  // FORM_CONTROL_H_
