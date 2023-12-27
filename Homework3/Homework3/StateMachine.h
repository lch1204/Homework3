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
    string nameState = "2, 3  или введите 0 для завершения";

    void displayMenu() 
    {
        cout << "Краткая справка по состояниям:" << endl;
        cout << "1 - начало, 2 - создание миссии, 3 - загрузка из файла" << endl;
        cout << "4 - распределительный пункт, 5 - создание задачи, 6 - проверка" << endl;
        cout << "7 - удаление задачи, 8 - вывод миссии, 9 - перестановка" << endl;
        cout << "10 - завершение миссии" << endl;
        std::cout << "Текущее состояние: " << currentState << std::endl;
        std::cout << "Выберите следующее состояние: (" << nameState << "): ";
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