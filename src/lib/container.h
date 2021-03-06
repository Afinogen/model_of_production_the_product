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

//����� ����������
class Container
{
    public:
        Container();
        ~Container();
        void AddRequest(Request *data);  //���������� ������ � ���������
        Request *GetRequest(const int idx) const;  //��������� ������ �� id
        int GetSizeContainer() const;  //��������� ������� ����������
        void DeleteRequest(const int idx);  //�������� ������ �� ���������� �� id
        void DeleteRequest(const Request *data);  //�������� ������ �� ����������
        void ClearContainer();  //������� ����������
    private:
        vector<Request*> array_data_;  //������ ������
};

#endif  // SRC_LIB_CONTAINER_H_
