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

Queue *g_queue1;  //�������
Queue *g_queue2;
Queue *g_queue3;
Queue *g_queue4;
Queue *g_queue5;
Queue *g_queue6;
Queue *g_queue7;

Controller *g_controller;  //����������

Collector *g_collector;  //�������

int g_count_piece;  //���-�� ������ (�������
int g_count_work;  //���-�� �������

//�������� ������� � ��������
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
//�������� ������� �������������
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
//������� �������
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
//��� ��������
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
//��������� ������
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
        g_queue7->AddRequest(
                g_source_b->GetNewRequest(g_system_timer->GetTime()));
        g_queue5->AddRequest(
                g_source_b->GetNewRequest(g_system_timer->GetTime()));
        g_source_b->GenTime();
    }

    if (g_source_c->GetTime() == 0)
    {
        g_queue2->AddRequest(
                g_source_c->GetNewRequest(g_system_timer->GetTime()));
        g_queue7->AddRequest(
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
//����������� ������ �� ������� � �����
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
        g_queue3->DeleteRequest(0);
        --tmp_count_work;
    }
    if (tmp_count_work == 0) return;
    //������� 4
    if (Queue4IsReady()
            && g_controller->GetValve(3)->GetStateChannel() == false)
    {
        g_controller->GetChannel(3)->setRequest(g_queue4->GetRequest(0));
        g_queue4->DeleteRequest(0);
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
    if (Queue7IsReady()
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
    if (g_queue3->GetCountRequestFromType(3) >= 1) return true;
    else return false;
}
//�������� ������� 4, � ��� ������ �������������� E, ��� �������� � �����
bool Queue4IsReady()
{
    //������ E
    if (g_queue4->GetCountRequestFromType(4) >= 1) return true;
    else return false;
}
//�������� ������� 5, � ��� ������ �������������� D B, ��� �������� � �����
bool Queue5IsReady()
{
    //������ D � B
    if (g_queue5->GetCountRequestFromType(1) >= 1
            && g_queue5->GetCountRequestFromType(3) >= 1) return true;
    else return false;
}
//�������� ������� 6, � ��� ������ �������������� F E, ��� �������� � �����
bool Queue6IsReady()
{
    //������ F � E
    if (g_queue6->GetCountRequestFromType(5) >= 1
            && g_queue6->GetCountRequestFromType(4) >= 1) return true;
    else return false;
}
//�������� ������� 7, � ��� ������ �������������� G B 2C, ��� �������� � �����
bool Queue7IsReady()
{
    //������ G B 2C
    if (g_queue7->GetCountRequestFromType(6) >= 1
            && g_queue7->GetCountRequestFromType(1) >= 1
            && g_queue7->GetCountRequestFromType(2) >= 2) return true;
    else return false;
}
//�������� ���������� ��������
bool CheckEndEmulation()
{
    if ((g_count_piece * 3)
            <= (g_source_a->GetCountGenRequest()
                    + g_source_b->GetCountGenRequest()
                    + g_source_c->GetCountGenRequest())
            && g_controller->GetCountBusyChannel() == 0 && !Queue1IsReady()
            && !Queue2IsReady() && !Queue3IsReady() && !Queue4IsReady()
            && !Queue5IsReady() && !Queue6IsReady() && !Queue7IsReady()) return true;
    //if (g_system_timer->GetTime() == 1000) return true;
    else return false;
}
//����� �� ����� ��������� ����������� ������
void PrintSourceState()
{
    printf(Rus("\n����������\tA\tB\tC\n"));
    string str;
    str.append(IntToChar(g_source_a->GetTime()));
    str.append("\t");
    str.append(IntToChar(g_source_b->GetTime()));
    str.append("\t");
    str.append(IntToChar(g_source_c->GetTime()));
    SetWindowText(g_hwnd_time_gen_sourse, str.c_str());
    printf(Rus("����� ���.\t%i\t%i\t%i\n"), g_source_a->GetTime(),
            g_source_b->GetTime(), g_source_c->GetTime());
    str = "";
    str.append(IntToChar(g_source_a->GetCountGenRequest()));
    str.append("\t");
    str.append(IntToChar(g_source_b->GetCountGenRequest()));
    str.append("\t");
    str.append(IntToChar(g_source_c->GetCountGenRequest()));
    SetWindowText(g_hwnd_count_gen_request, str.c_str());
    printf(Rus("���-�� ������\t%i\t%i\t%i\n"), g_source_a->GetCountGenRequest(),
            g_source_b->GetCountGenRequest(), g_source_c->GetCountGenRequest());
}
//����� ���������� �������
void PrintTimer()
{
    printf(Rus("��������� ����� %i ���\n"), g_system_timer->GetTime());
    string str;
    str.append(IntToChar(g_system_timer->GetTime()));
    str.append(" ���");
    SetWindowText(g_hwnd_sys_time, str.c_str());
}
//����� ��������� �������
void PrintChannelState()
{
    printf(Rus("\n������\t\t1\t2\t3\t4\t5\t6\t7\n"));
    string str = "���������\t";
    str.append(IntToChar(g_controller->GetValve(0)->GetStateChannel()));
    str.append("\t");
    str.append(IntToChar(g_controller->GetValve(1)->GetStateChannel()));
    str.append("\t");
    str.append(IntToChar(g_controller->GetValve(2)->GetStateChannel()));
    str.append("\t");
    str.append(IntToChar(g_controller->GetValve(3)->GetStateChannel()));
    str.append("\t");
    str.append(IntToChar(g_controller->GetValve(4)->GetStateChannel()));
    str.append("\t");
    str.append(IntToChar(g_controller->GetValve(5)->GetStateChannel()));
    str.append("\t");
    str.append(IntToChar(g_controller->GetValve(6)->GetStateChannel()));
    SetWindowText(g_hwnd_channel_info, str.c_str());
    printf(Rus("���������\t%i\t%i\t%i\t%i\t%i\t%i\t%i\n"),
            g_controller->GetValve(0)->GetStateChannel(),
            g_controller->GetValve(1)->GetStateChannel(),
            g_controller->GetValve(2)->GetStateChannel(),
            g_controller->GetValve(3)->GetStateChannel(),
            g_controller->GetValve(4)->GetStateChannel(),
            g_controller->GetValve(5)->GetStateChannel(),
            g_controller->GetValve(6)->GetStateChannel());

    str = "���������\t";
    str.append(IntToChar(g_controller->GetChannel(0)->GetTime()));
    str.append("\t");
    str.append(IntToChar(g_controller->GetChannel(1)->GetTime()));
    str.append("\t");
    str.append(IntToChar(g_controller->GetChannel(2)->GetTime()));
    str.append("\t");
    str.append(IntToChar(g_controller->GetChannel(3)->GetTime()));
    str.append("\t");
    str.append(IntToChar(g_controller->GetChannel(4)->GetTime()));
    str.append("\t");
    str.append(IntToChar(g_controller->GetChannel(5)->GetTime()));
    str.append("\t");
    str.append(IntToChar(g_controller->GetChannel(6)->GetTime()));
    SetWindowText(g_hwnd_channel_time, str.c_str());
    printf(Rus("���������\t%i\t%i\t%i\t%i\t%i\t%i\t%i\n"),
            g_controller->GetChannel(0)->GetTime(),
            g_controller->GetChannel(1)->GetTime(),
            g_controller->GetChannel(2)->GetTime(),
            g_controller->GetChannel(3)->GetTime(),
            g_controller->GetChannel(4)->GetTime(),
            g_controller->GetChannel(5)->GetTime(),
            g_controller->GetChannel(6)->GetTime());
}
//����� ������ � ��������
void PrintCollectorState()
{
    printf(Rus("\n������ � ��������: %i\n"), g_collector->GetSizeContainer());
    string str = "������ � ��������: \t";
    str.append(IntToChar(g_collector->GetSizeContainer()));
    SetWindowText(g_hwnd_count_request_collection, str.c_str());
}
//����� ���-�� ������ � �������
void PrintQueueState()
{
    printf(Rus("\n�������\t\t1\t2\t3\t4\t5\t6\t7\n"));

    string str = "����������\t";
    str.append(IntToChar(Queue1IsReady()));
    str.append("\t");
    str.append(IntToChar(Queue2IsReady()));
    str.append("\t");
    str.append(IntToChar(Queue3IsReady()));
    str.append("\t");
    str.append(IntToChar(Queue4IsReady()));
    str.append("\t");
    str.append(IntToChar(Queue5IsReady()));
    str.append("\t");
    str.append(IntToChar(Queue6IsReady()));
    str.append("\t");
    str.append(IntToChar(Queue7IsReady()));
    SetWindowText(g_hwnd_redy_queue, str.c_str());
    printf(Rus("����������\t%i\t%i\t%i\t%i\t%i\t%i\t%i\n"), Queue1IsReady(),
            Queue2IsReady(), Queue3IsReady(), Queue4IsReady(), Queue5IsReady(),
            Queue6IsReady(), Queue7IsReady());
    str = "���-�� ������\t";
    str.append(IntToChar(g_queue1->GetSizeContainer()));
    str.append("\t");
    str.append(IntToChar(g_queue2->GetSizeContainer()));
    str.append("\t");
    str.append(IntToChar(g_queue3->GetSizeContainer()));
    str.append("\t");
    str.append(IntToChar(g_queue4->GetSizeContainer()));
    str.append("\t");
    str.append(IntToChar(g_queue5->GetSizeContainer()));
    str.append("\t");
    str.append(IntToChar(g_queue6->GetSizeContainer()));
    str.append("\t");
    str.append(IntToChar(g_queue7->GetSizeContainer()));
    SetWindowText(g_hwnd_count_request_queue, str.c_str());
    printf(Rus("���-�� ������\t%i\t%i\t%i\t%i\t%i\t%i\t%i\n"),
            g_queue1->GetSizeContainer(), g_queue2->GetSizeContainer(),
            g_queue3->GetSizeContainer(), g_queue4->GetSizeContainer(),
            g_queue5->GetSizeContainer(), g_queue6->GetSizeContainer(),
            g_queue7->GetSizeContainer());
    int count_request_a = 0;
    int count_request_b = 0;
    int count_request_c = 0;
    int count_request_d = 0;
    int count_request_e = 0;
    int count_request_f = 0;
    int count_request_g = 0;
    for (int i = 0; i < g_queue1->GetSizeContainer(); i++)
    {
        if (g_queue1->GetRequest(i)->GetType() == 0) ++count_request_a;
        if (g_queue1->GetRequest(i)->GetType() == 1) ++count_request_b;
    }
    for (int i = 0; i < g_queue2->GetSizeContainer(); i++)
    {
        if (g_queue2->GetRequest(i)->GetType() == 0) ++count_request_a;
        if (g_queue2->GetRequest(i)->GetType() == 1) ++count_request_b;
        if (g_queue2->GetRequest(i)->GetType() == 2) ++count_request_c;
    }
    for (int i = 0; i < g_queue3->GetSizeContainer(); i++)
    {
        if (g_queue3->GetRequest(i)->GetType() == 3) ++count_request_d;
    }
    for (int i = 0; i < g_queue4->GetSizeContainer(); i++)
    {
        if (g_queue4->GetRequest(i)->GetType() == 4) ++count_request_e;
    }
    for (int i = 0; i < g_queue5->GetSizeContainer(); i++)
    {
        if (g_queue5->GetRequest(i)->GetType() == 3) ++count_request_d;
        if (g_queue5->GetRequest(i)->GetType() == 1) ++count_request_b;
    }
    for (int i = 0; i < g_queue6->GetSizeContainer(); i++)
    {
        if (g_queue6->GetRequest(i)->GetType() == 5) ++count_request_f;
        if (g_queue6->GetRequest(i)->GetType() == 4) ++count_request_e;
    }
    for (int i = 0; i < g_queue7->GetSizeContainer(); i++)
    {
        if (g_queue7->GetRequest(i)->GetType() == 0) ++count_request_a;
        if (g_queue7->GetRequest(i)->GetType() == 1) ++count_request_b;
        if (g_queue7->GetRequest(i)->GetType() == 2) ++count_request_c;
        if (g_queue7->GetRequest(i)->GetType() == 6) ++count_request_g;
    }
    str = "������ A:\t";
    str.append(IntToChar(count_request_a));
    str.append("\n������ B:\t");
    str.append(IntToChar(count_request_b));
    str.append("\n������ C:\t");
    str.append(IntToChar(count_request_c));
    str.append("\n������ D:\t");
    str.append(IntToChar(count_request_d));
    str.append("\n������ E:\t");
    str.append(IntToChar(count_request_e));
    str.append("\n������ F:\t");
    str.append(IntToChar(count_request_f));
    str.append("\n������ G:\t");
    str.append(IntToChar(count_request_g));
    SetWindowText(g_hwnd_all_request_info, str.c_str());
    printf(
            Rus(
                    "������ A: %i\n������ B: %i\n������ C: %i\n������ D: %i\n������ E: %i\n������ F: %i\n������ G: %i\n"),
            count_request_a, count_request_b, count_request_c, count_request_d,
            count_request_e, count_request_f, count_request_g);
}
