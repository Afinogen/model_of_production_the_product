/*
 * request.h
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#ifndef SRC_LIB_REQUEST_H_
#define SRC_LIB_REQUEST_H_

class Request
{
    public:
        Request(const int id, const int type, const int prioritet,
                const int time_gen);
        ~Request();
        int GetId() const
        {
            return id_;
        }
        int GetType() const
        {
            return type_;
        }
        int GetPrioritet() const
        {
            return prioritet_;
        }
        int GetTimeGen() const
        {
            return time_gen_;
        }
        int GetTimeinSystem() const
        {
            return time_in_system_;
        }
        int GetTimeInElement() const
        {
            return time_in_element_;
        }
        void setType(const int type)
        {
            type_ = type;
        }
        void setPrioritet(const int prioritet)
        {
            prioritet_ = prioritet;
        }
        void ClearTimeInElement()
        {
            time_in_element_ = 0;
        }
        void IncTimeInSystem()
        {
            ++time_in_system_;
        }
        void IncTimeInElement()
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
