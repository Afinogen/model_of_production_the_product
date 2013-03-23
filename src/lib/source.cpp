/*
 * source.cpp
 *
 *  Created on: 15.03.2013
 *      Author: Afinogen
 */

#include "source.h"

Source::Source(const int rand_a, const int rand_b, const int type)
{
    rand_a_ = rand_a;
    rand_b_ = rand_b;
    type_ = type;
    count_gen_request_ = 0;
    setTime(Random::Rand(rand_a_, rand_b_));
}

Source::~Source()
{

}
//��������� ��������� ���������
bool Source::GetState() const
{
    if (GetTime() == 0) return false;
    else return true;
}
//��������� ����� ������
Request *Source::GetNewRequest(const int time_gen)
{
    return new Request(++count_gen_request_, type_, 0, time_gen);
}
//��������� ������� �������� �������� ������
void Source::GenTime()
{
    setTime(Random::Rand(rand_a_, rand_b_));
}
//���-�� ��������� ������
int Source::GetCountGenRequest() const
{
    return count_gen_request_;
}
