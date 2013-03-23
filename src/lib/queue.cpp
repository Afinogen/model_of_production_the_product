/*
 * queue.cpp
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#include "queue.h"

Queue::Queue()
{

}

Queue::~Queue()
{

}
//��������� ���-�� ������ ��������� ����
int Queue::GetCountRequestFromType(const int type) const
{
    int count_request = 0;
    for (int i = 0; i < GetSizeContainer(); i++)
        if (GetRequest(i)->GetType() == type) ++count_request;
    return count_request;
}
//�������� ������ ��������� ����
void Queue::DeleteRequestFromType(const int type)
{
    for (int i = 0; i < GetSizeContainer(); i++)
        if (GetRequest(i)->GetType() == type) DeleteRequest(i);
}
