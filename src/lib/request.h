/*
 * request.h
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#ifndef SRC_LIB_REQUEST_H_
#define SRC_LIB_REQUEST_H_

//Класс заявка
class Request
{
    public:
        Request(const int id, const int type, const int prioritet,
                const int time_gen);
        ~Request();
        int GetId() const  //Получение id заявки
        {
            return id_;
        }
        int GetType() const  //Получение типа заявки
        {
            return type_;
        }
        int GetPrioritet() const  //получение приоритета
        {
            return prioritet_;
        }
        int GetTimeGen() const  //получение времени генерации
        {
            return time_gen_;
        }
        int GetTimeinSystem() const  //получение времени нахождения заявки в системе
        {
            return time_in_system_;
        }
        int GetTimeInElement() const  //получение времени нахождения заявки в элементе
        {
            return time_in_element_;
        }
        void setType(const int type)  //установка типа заявки
        {
            type_ = type;
        }
        void setPrioritet(const int prioritet)  //установка приоритета
        {
            prioritet_ = prioritet;
        }
        void ClearTimeInElement()  //очистка времени нахождения заявки в элементе
        {
            time_in_element_ = 0;
        }
        void IncTimeInSystem()  //инкримент времени заявки в системе
        {
            ++time_in_system_;
        }
        void IncTimeInElement()  //инкримент времени заявки в системе
        {
            ++time_in_element_;
        }
    private:
        int id_;  //Id заявки
        int type_;  //тип заявки
        int prioritet_;  //приоритет
        int time_gen_;  //время генерации
        int time_in_system_;  //время проведенное в системе
        int time_in_element_;  //время проведенное в елементе
};

#endif  // SRC_LIB_REQUEST_H_
