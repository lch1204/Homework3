#pragma once
#include <iostream>
#include <string>
#include "Mission.h"


using namespace std;

class StateMachine 
{
public:
	void start(List* list);

private:
    int currentState = 1;
    string nameState = "2, 3  ��� ������� 0 ��� ����������";

    void displayMenu() 
    {
        cout << "������� ������� �� ����������:" << endl;
        cout << "1 - ������, 2 - �������� ������, 3 - �������� �� �����" << endl;
        cout << "4 - ����������������� �����, 5 - �������� ������, 6 - ��������" << endl;
        cout << "7 - �������� ������, 8 - ����� ������, 9 - ������������" << endl;
        cout << "10 - ���������� ������" << endl;
        std::cout << "������� ���������: " << currentState << std::endl;
        std::cout << "�������� ��������� ���������: (" << nameState << "): ";
    }
    void beginState1(int choice, List* list);
    void newMissionState2(int choice);
    void fromFileState3(int choice);
    void whatDoState4(int choice, List* list);
    void State5(int choice, List* list);
    void testState6(int choice, List* list);
    void eraseState7(int choice, List* list);
    void printState8(int choice, List* list);
    void swapState9(int choice, List* list);
    void endState10(int choice, List* list);
    
    void newMission(List* list);
    void fromFile(List* list);
    void newPoint(List* list);
    void erase(List* list);
    void swap(List* list);
    void end(List* list);
    int status = 0;
};