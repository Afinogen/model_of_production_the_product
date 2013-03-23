/*
 * container.h
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#ifndef SRC_LIB_CONTAINER_H_
#define SRC_LIB_CONTAINER_H_

#include <stdlib.h>
#include <vector>
#include "request.h"

using std::vector;

//Класс контейнера
class Container
{
    public:
        Container();
        ~Container();
        void AddRequest(Request *data);  //Добавление заявки в контейнер
        Request *GetRequest(const int idx) const;  //Получение заявки по id
        int GetSizeContainer() const;  //Получение размера контейнера
        void DeleteRequest(const int idx);  //Удаление заявки из контейнера по id
        void DeleteRequest(const Request *data);  //Удаление заявки из контейнера
        void ClearContainer();  //Очистка контейнера
    private:
        vector<Request*> array_data_;  //вектор заявок
};

#endif  // SRC_LIB_CONTAINER_H_
