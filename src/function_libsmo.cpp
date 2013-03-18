/*
 * function_libsmo_init.cpp
 *
 *  Created on: 16.03.2013
 *      Author: Afinogen
 */

#include "function_libsmo.h"

Source *g_source_a;  //��������� ������ ���� �
Source *g_source_b;  //��������� ������ ���� �
Source *g_source_c;  //��������� ������ ���� �
Source *g_source_d;  //��������� ������ ���� D
Source *g_source_e;  //��������� ������ ���� E
Source *g_source_f;  //��������� ������ ���� F
Source *g_source_g;  //��������� ������ ���� G
Source *g_source_h;  //��������� ������ ���� H

Timer *g_system_timer;  //��������� �����

Queue *g_queue1;
Queue *g_queue2;
Queue *g_queue3;
Queue *g_queue4;
Queue *g_queue5;
Queue *g_queue6;
Queue *g_queue7;

Controller *g_controller;

Collector *g_collector;

int g_count_piece;
int g_count_work;

void InitValveVsChannel()
{
    g_controller->CreateChannel(7);
    g_controller->CreateValve(7);

    g_controller->GetValve(0)->setChannel(g_controller->GetChannel(0));
    g_controller->GetChannel(0)->setRandomTime(12, 18);

    g_controller->GetValve(1)->setChannel(g_controller->GetChannel(1));
    g_controller->GetChannel(1)->setRandomTime(15, 21);

    g_controller->GetValve(2)->setChannel(g_controller->GetChannel(2));
    g_controller->GetChannel(2)->setRandomTime(3, 7);

    g_controller->GetValve(3)->setChannel(g_controller->GetChannel(3));
    g_controller->GetChannel(3)->setRandomTime(3, 7);

    g_controller->GetValve(4)->setChannel(g_controller->GetChannel(4));
    g_controller->GetChannel(4)->setRandomTime(8, 12);

    g_controller->GetValve(5)->setChannel(g_controller->GetChannel(5));
    g_controller->GetChannel(5)->setRandomTime(11, 19);

    g_controller->GetValve(6)->setChannel(g_controller->GetChannel(6));
    g_controller->GetChannel(6)->setRandomTime(5, 11);
}

void InitSMO(const int count_piece, const int count_work)
{
    g_source_a = new Source(10, 20, 0);
    g_source_b = new Source(4, 8, 1);
    g_source_c = new Source(7, 13, 2);
    g_source_d = new Source(0, 0, 3);
    g_source_e = new Source(0, 0, 4);
    g_source_f = new Source(0, 0, 5);
    g_source_g = new Source(0, 0, 6);
    g_source_h = new Source(0, 0, 7);
    g_system_timer = new Timer();
    g_queue1 = new Queue();
    g_queue2 = new Queue();
    g_queue3 = new Queue();
    g_queue4 = new Queue();
    g_queue5 = new Queue();
    g_queue6 = new Queue();
    g_queue7 = new Queue();
    g_controller = new Controller(count_work);
    InitValveVsChannel();
    g_collector = new Collector();

    g_count_piece = count_piece;
    g_count_work = count_work;
}

void ClearSMO()
{
    delete g_source_a;
    delete g_source_b;
    delete g_source_c;
    delete g_source_d;
    delete g_source_e;
    delete g_source_f;
    delete g_source_g;
    delete g_source_h;
    delete g_system_timer;
    delete g_queue1;
    delete g_queue2;
    delete g_queue3;
    delete g_queue4;
    delete g_queue5;
    delete g_queue6;
    delete g_queue7;
    delete g_controller;
    delete g_collector;
}

void StepEmulation()
{
    g_system_timer->IncTime();
    if ((g_count_piece * 3)
            >= (g_source_a->GetCountGenRequest()
                    + g_source_b->GetCountGenRequest()
                    + g_source_c->GetCountGenRequest()))
    {
        g_source_a->DecTime();
        g_source_b->DecTime();
        g_source_c->DecTime();
        GenerationRequests();
    }
    if (g_controller->GetCountBusyChannel() > 0) g_controller->DecTimeAllChannel();
    MovingRequestFromChannelToQueue();
    MovingRequestFromQueueToChannel();
}

void GenerationRequests()
{
    if (g_source_a->GetTime() == 0)
    {
        g_queue1->AddRequest(
                g_source_a->GetNewRequest(g_system_timer->GetTime()));
        g_queue2->AddRequest(
                g_source_a->GetNewRequest(g_system_timer->GetTime()));
        g_source_a->GenTime();
    }

    if (g_source_b->GetTime() == 0)
    {
        g_queue1->AddRequest(
                g_source_b->GetNewRequest(g_system_timer->GetTime()));
        g_queue2->AddRequest(
                g_source_b->GetNewRequest(g_system_timer->GetTime()));
        g_queue3->AddRequest(
                g_source_b->GetNewRequest(g_system_timer->GetTime()));
        g_queue5->AddRequest(
                g_source_b->GetNewRequest(g_system_timer->GetTime()));
        g_source_b->GenTime();
    }

    if (g_source_c->GetTime() == 0)
    {
        g_queue2->AddRequest(
                g_source_c->GetNewRequest(g_system_timer->GetTime()));
        g_queue5->AddRequest(
                g_source_c->GetNewRequest(g_system_timer->GetTime()));
        g_source_c->GenTime();
    }
}

//����������� ������ �� ������ � �������
void MovingRequestFromChannelToQueue()
{
    //����� 1
    if (g_controller->GetChannel(0)->GetTime() == 0
            && g_controller->GetValve(0)->GetStateChannel())
    {
        g_queue3->AddRequest(g_controller->GetChannel(0)->GetRequest());
        g_controller->GetChannel(0)->DeleteRequest();
    }
    //����� 2
    if (g_controller->GetChannel(1)->GetTime() == 0
            && g_controller->GetValve(1)->GetStateChannel())
    {
        g_queue4->AddRequest(g_controller->GetChannel(1)->GetRequest());
        g_controller->GetChannel(1)->DeleteRequest();
    }
    //����� 3
    if (g_controller->GetChannel(2)->GetTime() == 0
            && g_controller->GetValve(2)->GetStateChannel())
    {
        g_queue5->AddRequest(g_controller->GetChannel(2)->GetRequest());
        g_controller->GetChannel(2)->DeleteRequest();
    }
    //����� 4
    if (g_controller->GetChannel(3)->GetTime() == 0
            && g_controller->GetValve(3)->GetStateChannel())
    {
        g_queue6->AddRequest(g_controller->GetChannel(3)->GetRequest());
        g_controller->GetChannel(3)->DeleteRequest();
    }
    //����� 5
    if (g_controller->GetChannel(4)->GetTime() == 0
            && g_controller->GetValve(4)->GetStateChannel())
    {
        g_queue6->AddRequest(g_controller->GetChannel(4)->GetRequest());
        g_controller->GetChannel(4)->DeleteRequest();
    }
    //����� 6
    if (g_controller->GetChannel(5)->GetTime() == 0
            && g_controller->GetValve(5)->GetStateChannel())
    {
        g_queue7->AddRequest(g_controller->GetChannel(5)->GetRequest());
        g_controller->GetChannel(5)->DeleteRequest();
    }
    //����� 7
    if (g_controller->GetChannel(6)->GetTime() == 0
            && g_controller->GetValve(6)->GetStateChannel())
    {
        g_collector->AddRequest(g_controller->GetChannel(6)->GetRequest());
        g_controller->GetChannel(6)->DeleteRequest();
    }
}

void MovingRequestFromQueueToChannel()
{
    int tmp_count_work = g_count_work;
    if (g_controller->GetCountBusyChannel() == g_count_work) return;

    tmp_count_work -= g_controller->GetCountBusyChannel();  //�������� ���-�� �� ������� �������
    //������� 1
    if (Queue1IsReady()
            && g_controller->GetValve(0)->GetStateChannel() == false)
    {
        g_queue1->DeleteRequestFromType(0);
        g_queue1->DeleteRequestFromType(1);
        g_queue1->DeleteRequestFromType(1);
        g_controller->GetChannel(0)->setRequest(
                g_source_d->GetNewRequest(g_system_timer->GetTime()));
        --tmp_count_work;
    }
    if (tmp_count_work == 0) return;
    //������� 2
    if (Queue2IsReady()
            && g_controller->GetValve(1)->GetStateChannel() == false)
    {
        g_queue2->DeleteRequestFromType(0);
        g_queue2->DeleteRequestFromType(1);
        g_queue2->DeleteRequestFromType(2);
        g_controller->GetChannel(1)->setRequest(
                g_source_e->GetNewRequest(g_system_timer->GetTime()));
        --tmp_count_work;
    }
    if (tmp_count_work == 0) return;
    //������� 3
    if (Queue3IsReady()
            && g_controller->GetValve(2)->GetStateChannel() == false)
    {
        g_controller->GetChannel(2)->setRequest(g_queue3->GetRequest(0));
        g_queue3->DeleteRequest(2);
        --tmp_count_work;
    }
    if (tmp_count_work == 0) return;
    //������� 4
    if (Queue4IsReady()
            && g_controller->GetValve(3)->GetStateChannel() == false)
    {
        g_controller->GetChannel(3)->setRequest(g_queue4->GetRequest(0));
        g_queue4->DeleteRequest(3);
        --tmp_count_work;
    }
    if (tmp_count_work == 0) return;
    //������� 5
    if (Queue5IsReady()
            && g_controller->GetValve(4)->GetStateChannel() == false)
    {
        g_queue5->DeleteRequestFromType(3);
        g_queue5->DeleteRequestFromType(1);
        g_controller->GetChannel(4)->setRequest(
                g_source_f->GetNewRequest(g_system_timer->GetTime()));
        --tmp_count_work;
    }
    if (tmp_count_work == 0) return;
    //������� 6
    if (Queue6IsReady()
            && g_controller->GetValve(5)->GetStateChannel() == false)
    {
        g_queue6->DeleteRequestFromType(5);
        g_queue6->DeleteRequestFromType(4);
        g_controller->GetChannel(5)->setRequest(
                g_source_g->GetNewRequest(g_system_timer->GetTime()));
        --tmp_count_work;
    }
    if (tmp_count_work == 0) return;
    //������� 7
    if (Queue2IsReady()
            && g_controller->GetValve(6)->GetStateChannel() == false)
    {
        g_queue7->DeleteRequestFromType(6);
        g_queue7->DeleteRequestFromType(1);
        g_queue7->DeleteRequestFromType(2);
        g_queue7->DeleteRequestFromType(2);
        g_controller->GetChannel(6)->setRequest(
                g_source_h->GetNewRequest(g_system_timer->GetTime()));
        --tmp_count_work;
    }
    if (tmp_count_work == 0) return;
}
//�������� ������� 1, � ��� ������ �������������� A � 2B, ��� �������� � �����
bool Queue1IsReady()
{
    //������ � � 2B
    if (g_queue1->GetCountRequestFromType(0) >= 1
            && g_queue1->GetCountRequestFromType(1) >= 2) return true;
    else return false;
}
//�������� ������� 2, � ��� ������ �������������� A B �, ��� �������� � �����
bool Queue2IsReady()
{
    //������ � B C
    if (g_queue2->GetCountRequestFromType(0) >= 1
            && g_queue2->GetCountRequestFromType(1) >= 1
            && g_queue2->GetCountRequestFromType(2) >= 1) return true;
    else return false;
}
//�������� ������� 3, � ��� ������ �������������� D, ��� �������� � �����
bool Queue3IsReady()
{
    //������ D
    if (g_queue1->GetCountRequestFromType(3) >= 1) return true;
    else return false;
}
//�������� ������� 4, � ��� ������ �������������� E, ��� �������� � �����
bool Queue4IsReady()
{
    //������ E
    if (g_queue1->GetCountRequestFromType(4) >= 1) return true;
    else return false;
}
//�������� ������� 5, � ��� ������ �������������� D B, ��� �������� � �����
bool Queue5IsReady()
{
    //������ D � B
    if (g_queue1->GetCountRequestFromType(1) >= 1
            && g_queue1->GetCountRequestFromType(3) >= 1) return true;
    else return false;
}
//�������� ������� 6, � ��� ������ �������������� F E, ��� �������� � �����
bool Queue6IsReady()
{
    //������ F � E
    if (g_queue1->GetCountRequestFromType(5) >= 1
            && g_queue1->GetCountRequestFromType(4) >= 1) return true;
    else return false;
}
//�������� ������� 7, � ��� ������ �������������� G B 2C, ��� �������� � �����
bool Queue7IsReady()
{
    //������ G B 2C
    if (g_queue1->GetCountRequestFromType(6) >= 1
            && g_queue1->GetCountRequestFromType(1) >= 1
            && g_queue1->GetCountRequestFromType(2) >= 2) return true;
    else return false;
}
bool CheckEndEmulation()
{
    if ((g_count_piece * 3)
            <= (g_source_a->GetCountGenRequest()
                    + g_source_b->GetCountGenRequest()
                    + g_source_c->GetCountGenRequest())
            && g_controller->GetCountBusyChannel() == 0) return true;
    else return false;
}

void PrintSourceState()
{
    printf(Rus("\n����������\tA\tB\tC\n"));
    printf(Rus("����� ���.\t%i\t%i\t%i\n"), g_source_a->GetTime(),
            g_source_b->GetTime(), g_source_c->GetTime());
    printf(Rus("���-�� ������\t%i\t%i\t%i\n"), g_source_a->GetCountGenRequest(),
            g_source_b->GetCountGenRequest(), g_source_c->GetCountGenRequest());
}

void PrintTimer()
{
    printf(Rus("��������� ����� %i ���\n"), g_system_timer->GetTime());
}

void PrintChannelState()
{
    printf(Rus("\n������\t\t1\t2\t3\t4\t5\t6\t7\n"));
    printf(Rus("���������\t%i\t%i\t%i\t%i\t%i\t%i\t%i\n"),
            g_controller->GetChannel(0)->GetTime(),
            g_controller->GetChannel(1)->GetTime(),
            g_controller->GetChannel(2)->GetTime(),
            g_controller->GetChannel(3)->GetTime(),
            g_controller->GetChannel(4)->GetTime(),
            g_controller->GetChannel(5)->GetTime(),
            g_controller->GetChannel(6)->GetTime());
}

void PrintCollectorState()
{
    printf(Rus("\n������ � ��������: %i\n"), g_collector->GetSizeContainer());
}
