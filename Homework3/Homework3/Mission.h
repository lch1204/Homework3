#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Node
{
    string typeMission;
    float dataX = 0; //те данные что храним
    float dataY = 0; //те данные что храним
    float dataZ = 0; //те данные что храним
    string typeDive;
    string moveType;
    string moveTypeDepth;
    float hoodPoint = 1; //в метрах
    Node* prev; //указатель на предыдущий элемент
    Node* next; //указатель на следующий элемент
};


class List
{
public:

    virtual void push_back(string typeMission,
                   float dataX,
                   float dataY,
                   float dataZ,
                   string typeDive,
                   string moveType,
                   string moveTypeDepth,
                   float hoodPoint = 1); // добавление в конец списка
  //  virtual void push_front(float data); //добавление в начало списка
    virtual void erase(int index); //удаление элемента
    Node* move(int index); //находим указатель на элемент 
    void print();//напечатать весь список
    void clear(); //очистить весь список
    virtual void swapNode(int index_one, int index_two); //перестановка элементов
    virtual bool correctIndex(int index); //проверка на то, что данный индекс существует
    Node* head; //указатель на начало списка
    Node* tail; //указатель на конец списка
    int count; //счетчик элементов
    void newFile();
    int saveFile();
    int readFile();
    void parser(string str);
    string nameTXT;
    int countSort = 0;
    int test();
    List();

    float depth = 0;
    float coordX = 0;
    float coordY = 0;

    virtual ~List();
private:
    string name;
};

class Mission
{
public:
    
    int count = 0; //счетчик сколько команд было выполнено
    Mission();
    virtual void writeNewCommand(List* list, 
                                 string typeMission,
                                 float dataX,
                                 float dataY,
                                 float dataZ,
                                 string typeDive,
                                 string moveType,
                                 string moveTypeDepth,
                                 float hoodPoint) = 0;
    
    virtual ~Mission() {};
};


class Dive :  public Mission
{
public:
    void writeNewCommand(List* list,
                         string typeMission,
                         float dataX,
                         float dataY,
                         float dataZ,
                         string typeDive,
                         string typeMovementX,
                         string typeMovementY,
                         float hoodPoint) override
    {
        list->push_back(typeMission, dataX, dataY, dataZ,
                        typeDive, "no", "no", hoodPoint);
    }
};

class Lift : public virtual Mission
{

public:
    void writeNewCommand(List* list,
        string typeMission,
        float dataX,
        float dataY,
        float dataZ,
        string typeDive,
        string moveType,
        string moveTypeDepth,
        float hoodPoint) override
    {
        list->push_back(typeMission, dataX, dataY, dataZ,
            typeDive, "no", "no", hoodPoint);
    }
};

class Move : public virtual Mission
{

public:
    void writeNewCommand(List* list,
        string typeMission,
        float dataX,
        float dataY,
        float dataZ,
        string typeDive,
        string moveType,
        string moveTypeDepth,
        float hoodPoint) override
    {
        list->push_back(typeMission, dataX, dataY, dataZ,
            typeDive, moveType, moveTypeDepth, hoodPoint);
    }
};

class Return : public virtual Mission
{

public:
    void writeNewCommand(List* list,
        string typeMission,
        float dataX,
        float dataY,
        float dataZ,
        string typeDive,
        string moveType,
        string moveTypeDepth,
        float hoodPoint) override
    {
        list->push_back(typeMission, dataX, dataY, dataZ,
            typeDive, moveType, moveTypeDepth, hoodPoint);
    }
};