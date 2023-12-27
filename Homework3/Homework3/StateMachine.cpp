#include "StateMachine.h"

void StateMachine::start(List* list)
{
    int choice;
    cout << "������ ����, �� ���������� � ��������� ��������� 1" << endl;
    cout << "1) �� ������ ������� � ��������� 2 � ������ ������������ ������" << endl;
    cout << "2) �� ������ ������� � ��������� 3 � ��������� ������ �� �����" << endl;
    cout << "3) �� ������ ������� � ��������� 0 � ��������� ������" << endl;
    do {
        displayMenu();
        std::cin >> choice;

        switch (currentState) 
        {
        case 1:
            cout << "�� ���������� � ��������� ��������� 1" << endl;
            beginState1(choice, list);
            break;

        case 2:
            cout << "�� ���������� � ��������� 2 - �������� ������" << endl;
            newMissionState2(choice);
            break;

        case 3:
            cout << "�� ���������� � ��������� 3 - �������� ������ �� �����" << endl;
            fromFileState3(choice);
            break;

        case 4:
            cout << "�� ���������� � ��������� 4 - �������� ����� ������� �����������" << endl;
            whatDoState4(choice, list);
            break;
        
        case 5:
            cout << "�� ���������� � ��������� 5 - ������������ ������" << endl;
            State5(choice, list);
            break;
        case 6:
            cout << "�� ���������� � ��������� 6 - �������� ������" << endl;
            testState6(choice, list);
            break;
        case 7:
            cout << "�� ���������� � ��������� 7 - �������� �����" << endl;
            eraseState7(choice, list);
            break;
        case 8:
            cout << "�� ���������� � ��������� 8 - ����� ������" << endl;
            printState8(choice, list);
            break;
        case 9:
            cout << "�� ���������� � ��������� 9 - ������������ ������" << endl;
            swapState9(choice, list);
            break;

        case 10:
            cout << "�� ���������� � ��������� 10 - ����������� ������" << endl;
            endState10(choice, list);
            break;

        default:
            std::cerr << "������: ������������ ���������" << std::endl;
            break;
        }
    } while (currentState != 0);  // ���������� ����� ��� ����� 0

}

void StateMachine::beginState1(int choice, List* list)
{
    switch (choice) 
    {
    case 2:
        std::cout << "������� �� ��������� 1 � ��������� 2" << std::endl;
        currentState = 2;
        nameState = "4";
        newMission(list);
        break;

    case 3:
        std::cout << "������� �� ��������� 1 � ��������� 3" << std::endl;
        currentState = 3;
        nameState = "4";
        fromFile(list);
        break;

    case 0:
        std::cout << "���������� ���������" << std::endl;
        currentState = 0;
        break;

    default:
        std::cout << "������������ ����" << std::endl;
        break;
    }
}

void StateMachine::newMissionState2(int choice)
{
    switch (choice)
    {
    case 2:
        std::cout << "�������� � ��������� 2" << std::endl;
        break;

    case 4:
        std::cout << "������� �� ��������� 2 � ��������� 4" << std::endl;
        currentState = 4;
        nameState = "5, 6, 7, 8, 9, 10";
        break;

    default:
        std::cout << "������������ ����" << std::endl;
        break;
    }
}

void StateMachine::fromFileState3(int choice)
{
    switch (choice) 
    {
    case 4:
        std::cout << "������� �� ��������� 3 � ��������� 4" << std::endl;
        currentState = 4;
        nameState = "5, 6, 7, 8, 9, 10";
        break;

    default:
        std::cout << "������������ ����" << std::endl;
        break;
    }
}

void StateMachine::whatDoState4(int choice, List* list)
{
    switch (choice)
    {
    case 4:
        std::cout << "�������� � ��������� 4" << std::endl;
        break;

    case 5:
        std::cout << "������� �� ��������� 4 � ��������� 5" << std::endl;
        currentState = 5;
        newPoint(list);
        nameState = "4, 5";
        break;

    case 6:
        std::cout << "������� �� ��������� 4 � ��������� 6" << std::endl;
        currentState = 6;
        nameState = "4";
        list->test();
        break;

    case 7:
        std::cout << "������� �� ��������� 4 � ��������� 7" << std::endl;
        currentState = 7;
        nameState = "4, 7";
        erase(list);
        break;

    case 8:
        std::cout << "������� �� ��������� 4 � ��������� 8" << std::endl;
        currentState = 8;
        nameState = "4, 8";
        list->print();
        break;

    case 9:
        std::cout << "������� �� ��������� 4 � ��������� 9" << std::endl;
        currentState = 9;
        nameState = "4, 9";
        swap(list);
        break;

    case 10:
        std::cout << "������� �� ��������� 4 � ��������� 10" << std::endl;
        currentState = 10;
        nameState = "1";
        end(list);
        break;

    default:
        std::cout << "������������ ����" << std::endl;
        break;
    }
}

void StateMachine::State5(int choice, List* list)
{
    switch (choice)
    {
    case 4:
        std::cout << "������� �� ��������� 5 � ��������� 4" << std::endl;
        currentState = 4;
        nameState = "5, 6, 7, 8, 9, 10";
        break;

    case 5:
        std::cout << "�������� � ��������� 5" << std::endl;
        nameState = "4, 5";
        newPoint(list);
        break;


    default:
        std::cout << "������������ ����" << std::endl;
        break;
    }
}

void StateMachine::testState6(int choice, List* list)
{
    switch (choice)
    {
    case 4:
        std::cout << "������� �� ��������� 6 � ��������� 4" << std::endl;
        currentState = 4;
        nameState = "5, 6, 7, 8, 9, 10";
        break;

    case 6:
        std::cout << "�������� � ��������� 6" << std::endl;
        list->test();
        break;

    default:
        std::cout << "������������ ����" << std::endl;
        break;
    }
    
}

void StateMachine::eraseState7(int choice, List* list)
{
    switch (choice)
    {
    case 4:
        std::cout << "������� �� ��������� 7 � ��������� 4" << std::endl;
        currentState = 4;
        nameState = "5, 6, 7, 8, 9, 10";
        break;

    case 7:
        std::cout << "�������� � ��������� 7" << std::endl;
        erase(list);
        break;

    default:
        std::cout << "������������ ����" << std::endl;
        break;
    }
}

void StateMachine::printState8(int choice, List* list)
{
    switch (choice)
    {
    case 4:
        std::cout << "������� �� ��������� 8 � ��������� 4" << std::endl;
        currentState = 4;
        nameState = "5, 6, 7, 8, 9, 10";
        break;

    case 8:
        std::cout << "�������� � ��������� 8" << std::endl;
        list->print();
        break;

    default:
        std::cout << "������������ ����" << std::endl;
        break;
    }
}

void StateMachine::swapState9(int choice, List* list)
{
    switch (choice)
    {
    case 4:
        std::cout << "������� �� ��������� 9 � ��������� 4" << std::endl;
        currentState = 4;
        nameState = "5, 6, 7, 8, 9, 10";
        break;

    case 9:
        std::cout << "�������� � ��������� 9" << std::endl;
        swap(list);
        break;

    default:
        std::cout << "������������ ����" << std::endl;
        break;
    }
}

void StateMachine::endState10(int choice, List* list)
{
    switch (choice)
    {
    case 1:
        std::cout << "������� �� ��������� 10 � ��������� 1" << std::endl;
        currentState = 1;
        nameState = "2,3";
        break;


    default:
        std::cout << "������������ ����" << std::endl;
        break;
    }
}

void StateMachine::newMission(List* list)
{
    cout << "������� ����� ������" << endl;
    list->newFile();
}

void StateMachine::fromFile(List* list)
{
    cout << "�������� ������ �� �����" << endl;
    list->readFile();
}

void StateMachine::newPoint(List* list)
{
    cout << "�� ������ ����������� (1), ��������� (2)," << endl;
    cout << "����� � ����� � ��������� (x,y) (3) ��� ����� �� ������������ (0)" << endl;
    cout << "������� ������ �����: ";
    cin >> status;
    if (status == 0)  {}
    if (status == 1)
    {
        Dive dv;
        float dataZ = 0;
        string diveType;
        int diveTypeInt;
        do 
        {
            cout << "�� ������� ����������, ������� ������� �� ������� ���������� ����������� ��������: ";
            cin >> dataZ;
            if ((dataZ < 0) or (dataZ > 100) or (list->depth > dataZ))
                cout << "�������� �������� �� ���������, ���������� ��� ���" << endl;
        } while ((dataZ < 0) or (dataZ > 100) or (list->depth > dataZ));
        do
        {
            cout << "���������� ����� ����������� �� �������(1), ��� ����������� �� ���� ���������� (2)" << endl;
            cout << "�������� ��� ����������: ";
            cin >> diveTypeInt;
            if (diveTypeInt == 1) diveType = "spiral";
            if (diveTypeInt == 2) diveType = "vertical";
            if ((diveTypeInt < 0) or (diveTypeInt > 3))
                cout << "�������� �������� �� ���������, ���������� ��� ���" << endl;
        } while ((diveTypeInt < 0) or (diveTypeInt > 3));
        list->depth = dataZ;
        dv.writeNewCommand(list, "dive", -1, -1, dataZ, diveType, "no", "no", 0);
        
        list->print();
    }
    if (status == 2)
    {
        Lift lf;
        float dataZ = 0;
        string diveType;
        int diveTypeInt;
        do
        {
            cout << "�� ������� ��������, ������� ������� �� ������� ���������� ������� ��������: ";
            cin >> dataZ;
            if ((dataZ < 0) or (dataZ > 100) or (list->depth < dataZ))
                cout << "�������� �������� �� ���������, ���������� ��� ���" << endl;
        } while ((dataZ < 0) or (dataZ > 100) or (list->depth < dataZ));
        do
        {
            cout << "�������� ����� ����������� �� �������(1), ��� ����������� �� ���� ���������� (2)" << endl;
            cout << "�������� ��� ����������: ";
            cin >> diveTypeInt;
            if (diveTypeInt == 1) diveType = "spiral";
            if (diveTypeInt == 2) diveType = "vertical";
            if ((diveTypeInt < 0) or (diveTypeInt > 3))
                cout << "�������� �������� �� ���������, ���������� ��� ���" << endl;
        } while ((diveTypeInt < 0) or (diveTypeInt > 3));
        list->depth = dataZ;
        lf.writeNewCommand(list, "lift", -1, -1, dataZ, diveType, "no", "no", 0);
        list->print();
    }
    if (status == 3)
    {
        Move mv;
        float dataX = 0;
        float dataY = 0;
        string moveType;
        string moveTypeDepth;
        int moveTypeInt;
        do 
        {
            cout << "�� ������� ����� � �����, ������� ���������� X Y ����� ������: ";
            cin >> dataX >> dataY;
            if (((dataX < 0) or (dataX > 10000)) and ((dataY < 0) or (dataY > 10000)))
                cout << "�������� �������� �� ���������, ���������� ��� ���" << endl;
        } while (((dataX < 0) or (dataX > 10000)) and ((dataY < 0) or (dataY > 10000)));
        do
        {
            cout << "�������� ����� ���� � ����� (1) ��� ����� ������ (2)" << endl;
            cout << "�������� ��� ��������: ";
            cin >> moveTypeInt;
            if (moveTypeInt == 1) moveType = "point";
            if (moveTypeInt == 2) moveType = "line";
            if ((moveTypeInt < 0) or (moveTypeInt > 3))
                cout << "�������� �������� �� ���������, ���������� ��� ���" << endl;
        } while ((moveTypeInt < 0) or (moveTypeInt > 3));
        do
        {
            cout << "�������� ����� ���� � ���������� �������� (1) ��� ��� (2)" << endl;
            cout << "�������� ��� ��������: ";
            cin >> moveTypeInt;
            if (moveTypeInt == 1) moveTypeDepth = "depthConst";
            if (moveTypeInt == 2) moveTypeDepth = "depthNoConst";
            if ((moveTypeInt < 0) or (moveTypeInt > 3))
                cout << "�������� �������� �� ���������, ���������� ��� ���" << endl;
        } while ((moveTypeInt < 0) or (moveTypeInt > 3));
        list->coordX = dataX;
        list->coordY = dataY;
        mv.writeNewCommand(list, "move", dataX, dataY, -1, "no", moveType, moveTypeDepth, 5);
        list->print();
    }
    if ((status > 3)or (status < 0)) cout << "�� ��������, ���������� �������" << endl;
}

void StateMachine::erase(List* list)
{
    int index;
    do
    {
        cout << "������� ����� ����� ������� �� ������ �������: ";

        cin >> index;
        if (index > list->count)
            cout << "��������� ������ �� ���������, ���������� ��� ���" << endl;
    } while (index > list->count);
    list->erase(index);
}

void StateMachine::swap(List* list)
{
    int index1, index2;
    cout << "������� ������� ������, ������� �� �� ������ �������� �������: ";
    cin >> index1 >> index2;
    list->swapNode(index1, index2);
}

void StateMachine::end(List* list)
{
    int res = list->test();
    if (res != 0)
    {
        cout << "��������, �� �� �� ������ ��������� ������, �������� ��������� ��� � 4 ���������" << endl;
        currentState = 4;
        nameState = "5, 6, 7, 8, 9, 10";
        return;
    }
    cout << "������� �������� ����� �� ���� c ������������ 0, 0, 0" << endl;
    Return rn;
    rn.writeNewCommand(list, "return", 0, 0, 0, "no", "no", "no", 0);
    cout << "�������� ������" << endl;
    list->print();
    cout << "������� ����: " << list->nameTXT <<endl;
    int result = list->saveFile();
    if (result == 0)
    {
        cout << "������ ������� ���������" << endl;
        
        currentState = 0;
        return;
    }
    else 
    {
        cout << "������ �� ���������" << endl;
        currentState = 4;
        nameState = "5, 6, 7, 8, 9, 10";
        return;
    }
        
}
