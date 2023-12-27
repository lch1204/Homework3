#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Node
{
    string typeMission;
    float dataX = 0; //�� ������ ��� ������
    float dataY = 0; //�� ������ ��� ������
    float dataZ = 0; //�� ������ ��� ������
    string typeDive;
    string moveType;
    string moveTypeDepth;
    float hoodPoint = 1; //� ������
    Node* prev; //��������� �� ���������� �������
    Node* next; //��������� �� ��������� �������
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
                   float hoodPoint = 1); // ���������� � ����� ������
  //  virtual void push_front(float data); //���������� � ������ ������
    virtual void erase(int index); //�������� ��������
    Node* move(int index); //������� ��������� �� ������� 
    void print();//���������� ���� ������
    void clear(); //�������� ���� ������
    virtual void swapNode(int index_one, int index_two); //������������ ���������
    virtual bool correctIndex(int index); //�������� �� ��, ��� ������ ������ ����������
    Node* head; //��������� �� ������ ������
    Node* tail; //��������� �� ����� ������
    int count; //������� ���������
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
    
    int count = 0; //������� ������� ������ ���� ���������
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