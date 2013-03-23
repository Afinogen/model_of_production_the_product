/*
 * form_control.h
 *
 *  Created on: 19.03.2013
 *      Author: Afinogen
 */

#ifndef FORM_CONTROL_H_
#define FORM_CONTROL_H_

#include <windows.h>

extern HWND g_hwnd_form;               //hwnd окна
extern HWND g_hwnd_edit_request_count;        //поле редактирования кол-ва зявок
extern HWND g_hwnd_edit_work_count;         //поле редактирования кол-ва рабочих
extern HWND g_hwnd_button_start_pause;               //кнопка старт/пауза
extern HWND g_hwnd_button_stop;               //кнопка стоп
extern HWND g_hwnd_time_gen_sourse;  //вывод генерации времени заявок в источниках
extern HWND g_hwnd_count_gen_request;            //вывод кол-ва созданных заявок
extern HWND g_hwnd_sys_time;               //вывод модельного времени
extern HWND g_hwnd_redy_queue;               //вывод готовности очередей
extern HWND g_hwnd_count_request_queue;          //вывод кол-ва заявок в очереди
extern HWND g_hwnd_all_request_info;          //вывод кол-ва заявок каждого типа
extern HWND g_hwnd_channel_info;               //вывод состояния каналов
extern HWND g_hwnd_channel_time;      //вывод времени обработки заявок в каналах
extern HWND g_hwnd_count_request_collection;    //вывод кол-ва заявок в сборщике
extern HINSTANCE g_instance;

//создание формы
void CreateForm(HINSTANCE hInstance);
//создание полей ввода
void CreateEdit();
//создание текста
void CreateLabel();
//создание кнопок
void CreateButton();

#endif  // FORM_CONTROL_H_
