/*
 * controller.h
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#ifndef SRC_LIB_CONTROLLER_H_
#define SRC_LIB_CONTROLLER_H_

#include <vector>
#include "channel.h"
#include "valve.h"

using std::vector;

//Класс контроллера
class Controller
{
    public:
        Controller();
        Controller(const int count_work_channel);
        ~Controller();
        void CreateChannel(const int count_channel);  //Создание каналов
        void CreateValve(const int count_valve);  //Создание клапанов
        Channel *GetChannel(const int idx) const;  //Получение канала по id
        Valve *GetValve(const int idx) const;  //Получение клапана по id
        void DecTimeAllChannel();  //Уменьшение времени обработки всех каналов
        void setCountWorkChannel(const int count_work_channel);  //Установка одновременно работающих каналов
        int GetCountChannel() const;  //Получение кол-ва каналов
        int GetCountValve() const;  //Получение кол-ва клапанов
        int GetCountBusyChannel() const;  //Получение кол-ва работающих каналов
    private:
        vector<Channel*> array_channel_;  //вектор каналов
        vector<Valve*> array_valve_;  //вектор клапанов
        int count_work_channel_;  //кол-во одновременно работающих каналов
};

#endif  // SRC_LIB_CONTROLLER_H_
