#include "Mission.h"
using namespace std;

Mission::Mission()  
{
    cout << "����������� ������ Mission" << endl;
}

void List::newFile()
{
    cout << "������� �������� ��� ������: " << endl;
    string name;
    std::cin >> name;
    cout << "�������� ������: " << name << endl;
    nameTXT = name + ".txt";
    ofstream outFile(nameTXT);

    if (!outFile.is_open())
    {
        while (!outFile.is_open())
        {
            cout << "���������� ������� ������ � ����� ������, ���������� ����� ��������: " << endl;
            std::cin >> name;
            string nameTXT = name + ".txt";
            ofstream outFile(nameTXT);
        }
    }
    outFile.close();
}

int List::saveFile()
{
    ofstream appendFile(nameTXT, ios::app);
    if (!appendFile.is_open()) {
        std::cerr << "�� ������� ������� ���� ��� �����������." << std::endl;
        return 1;
    }
    Node* ptr = head;
    appendFile << "typeMission, dataX, dataY, dataZ, typeDive, moveType, moveTypeDepth, hoodPoint" << endl;
    for (int i = 0; i < count; i++)
    {
        appendFile << ptr->typeMission << ", " <<
            ptr->dataX << ", " <<
            ptr->dataY << ", " <<
            ptr->dataZ << ", " <<
            ptr->typeDive << ", " <<
            ptr->moveType << ", " <<
            ptr->moveTypeDepth << ", " <<
            ptr->hoodPoint << endl;
        ptr = ptr->next;
    }

    appendFile << endl;
    appendFile.close();
    return 0;
}

int List::readFile()
{
    cout << "������� �������� �����, ������� ������ �� ��������� � ������� ***.txt: " << endl;
    cin >> nameTXT;
    ifstream inFile(nameTXT);
    string line;
    if (!inFile.is_open()) {
        std::cerr << "�� ������� ������� ���� ��� ������." << std::endl;
        return 1;
    }
    while (getline(inFile, line)) {
        parser(line);
    }
    inFile.close();
    return 0;
}

void List::parser(string str)
{
    string none = "";
    int resultNone = str.compare(none);
    if (resultNone == 0) return;
    string sr = "typeMission, dataX, dataY, dataZ, typeDive, moveType, moveTypeDepth, hoodPoint";
    int res = str.compare(sr);
    if (res == 0) return;
    Node* node = new Node;
    istringstream inputStream(str);
    getline(inputStream, node->typeMission, ',');
    inputStream >> node->dataX >> ws;
    inputStream.ignore();
    inputStream >> node->dataY >> ws;
    inputStream.ignore();
    inputStream >> node->dataZ >> ws;
    inputStream.ignore(); // ���������� ������� ����� param3
    getline(inputStream, node->typeDive, ',');
    getline(inputStream, node->moveType, ',');
    getline(inputStream, node->moveTypeDepth, ',');
    inputStream >> node->hoodPoint;
    string returhn = "return";
    int res2 = node->typeMission.compare(returhn);
    if (res2 == 0) return;
    if (res2 != 0)
    push_back(node->typeMission, node->dataX, node->dataY, node->dataZ, \
        node->typeDive, node->moveType, node->moveTypeDepth, node->hoodPoint);
}

int List::test()
{
    string dive = "dive";
    string move = "move";
    string lift = "lift";
    Node* ptr = head;
    Node* ptrNext = head;
    ptrNext = ptrNext->next;
    if ((ptr->typeMission == "lift") and (ptr->dataZ != 0))
    {
        cout << "������! ������� �� ����� ��������� �� ���� ��� �� ����������" << endl;
        return 1;
    }
    for (int i = 0;  i < count-1; i++)
    {
        cout << "ptrNext->dataZ" << ptrNext->dataZ << endl;
        cout << "ptr->dataZ" << ptr->dataZ << endl;
        int resDive = ptr->typeMission.compare(dive);
        int resDiveNext = ptrNext->typeMission.compare(dive);
        int resLift = ptr->typeMission.compare(lift);
        int resLiftNext = ptrNext->typeMission.compare(lift);
        if ((resDive == 0) and (resDiveNext == 0))
        {
            if (ptrNext->dataZ < ptr->dataZ)
            {
                cout << "������! ������� �� ����� ����������� �� ������� ������� ��� ���� �� �����" << endl;
                cout << "������ � ������: " << endl;
                cout << ptrNext->typeMission << ", " << \
                    ptrNext->dataX << ", " << \
                    ptrNext->dataY << ", " << \
                    ptrNext->dataZ << ", " << \
                    ptrNext->typeDive << ", " << \
                    ptrNext->moveType << ", " << \
                    ptrNext->moveTypeDepth << ", " << \
                    ptrNext->hoodPoint << endl;
                return 1;
            }
        }
        if ((resLift == 0) and (resLiftNext == 0))
        {
            if (ptrNext->dataZ > ptr->dataZ)
            {
                cout << "������! ������� �� ����� ������ �� ������� ������� ��� ���� �� �����" << endl;
                cout << "������ � ������:" << endl;
                cout << ptrNext->typeMission << ", " <<
                    ptrNext->dataX << ", " <<
                    ptrNext->dataY << ", " <<
                    ptrNext->dataZ << ", " <<
                    ptrNext->typeDive << ", " <<
                    ptrNext->moveType << ", " <<
                    ptrNext->moveTypeDepth << ", " <<
                    ptrNext->hoodPoint << endl;
                return 1;
            }
            
        }
        if ((resDive == 0) and (resLiftNext == 0))
        {
            if (ptrNext->dataZ < ptr->dataZ)
            {
                cout << "������! ������� �� ����� ������ �� ������� ������� ��� ���� �� �����" << endl;
                cout << "������ � ������:" << endl;
                cout << ptrNext->typeMission << ", " <<
                    ptrNext->dataX << ", " <<
                    ptrNext->dataY << ", " <<
                    ptrNext->dataZ << ", " <<
                    ptrNext->typeDive << ", " <<
                    ptrNext->moveType << ", " <<
                    ptrNext->moveTypeDepth << ", " <<
                    ptrNext->hoodPoint << endl;
                return 1;
            }
        }
        if ((resDive == 0) and (resLiftNext ==0))
        {
            if (ptrNext->dataZ > ptr->dataZ)
            {
                cout << "������! ������� �� ����� ����������� �� ������� ������� ��� ���� �� �����" << endl;
                cout << "������ � ������:" << endl;
                cout << ptrNext->typeMission << ", " <<
                    ptrNext->dataX << ", " <<
                    ptrNext->dataY << ", " <<
                    ptrNext->dataZ << ", " <<
                    ptrNext->typeDive << ", " <<
                    ptrNext->moveType << ", " <<
                    ptrNext->moveTypeDepth << ", " <<
                    ptrNext->hoodPoint << endl;
                return 1;
            }
        
    }
        ptr = ptr->next;
        ptrNext = ptrNext->next;
    }
    std::cout << "�� �����, �� �������!" << endl;
    return 0;
}

List::List()
{
    cout << "����������� ������ List" << endl;
    head = tail = nullptr; //��� �������� ������ ������� ���������� �� ���� (��� ������� ��� ��� ������� ������ ���)
    count = countSort = 0;
}


List::~List()
{
    clear();
}

void List::push_back(string typeMission, float dataX, float dataY, float dataZ, string typeDive, string moveType, string moveTypeDepth, float hoodPoint)
{
    Node* ptr = new Node; //������� ����� �������, ���� ��� ��������� �� �����
    ptr->prev = tail;// ����������� ��������� ����� �������� ���������� ��������
    if (tail != nullptr) //���� ������� ��������� ������� �����������
    {
        tail->next = ptr; //��������� ����� �������� �������� � ������ ��������
    }
    if (head == nullptr)
    {
        head = ptr; //��� ��� � ���� ������ ������ ������������
    }
    ptr->typeMission = typeMission;
    ptr->dataX = dataX;
    ptr->dataY = dataY;
    ptr->dataZ = dataZ;
    ptr->typeDive = typeDive;
    ptr->moveType = moveType;
    ptr->moveTypeDepth = moveTypeDepth;
    ptr->hoodPoint = hoodPoint;
    tail = ptr; //��������� �� ����� ������ ������ ��������� �� ����� ��������� �������
    count++;
}

void List::erase(int index)
{
    if (count == 0) return;
    if (!correctIndex(index)) return;
    Node* ptr = move(index); //��������� ���������� �� ��������� �������
    Node* ptrPrev = ptr->prev;
    Node* ptrNext = ptr->next;
    if (index == 0)
        head = ptrNext; //���� ������� ������ �������
    else
        ptrPrev->next = ptrNext; //�������
    if (index == count - 1)
        tail = ptrPrev; //���� ������� ���������
    else
        ptrNext->prev = ptrPrev;
    delete ptr;
    count--;
}

Node* List::move(int index)
{
    Node* ptr = head; //������������� ��������� �� ������
    for (int i = 0; i < index; i++)
        ptr = ptr->next;
    return ptr;
}

void List::print()
{
    Node* ptr = head;
    cout << "typeMission, dataX, dataY, dataZ, typeDive, moveType, moveTypeDepth, hoodPoint" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << ptr->typeMission << ", " <<
            ptr->dataX << ", " <<
            ptr->dataY << ", " <<
            ptr->dataZ << ", " <<
            ptr->typeDive << ", " << 
            ptr->moveType << ", " <<
            ptr->moveTypeDepth << ", " <<
            ptr->hoodPoint << endl;
        ptr = ptr->next;
    }

    cout << endl;
}

void List::clear()
{
    int n = count;
    for (int i = 0; i < n; i++)
        erase(0);//����� 0, �� �� ������� ������� ������� � 0, ������ ������ ����� ����������
}

void List::swapNode(int index_one, int index_two)
{
    if (!correctIndex(index_one)) return;
    if (!correctIndex(index_two)) return;
    Node* ptrOne = move(index_one);
    Node* ptrTwo = move(index_two);
    string typeMission = ptrOne->typeMission;
    float dataX = ptrOne->dataX;
    float dataY = ptrOne->dataY;
    float dataZ = ptrOne->dataZ;
    string typeDive = ptrOne->typeDive;
    string moveType = ptrOne->moveType;
    string moveTypeDepth = ptrOne->moveTypeDepth;
    float hoodPoint = ptrOne->hoodPoint;
    ptrOne->typeMission = ptrTwo->typeMission;
    ptrOne->dataX = ptrTwo->dataX;
    ptrOne->dataY = ptrTwo->dataY;
    ptrOne->dataZ = ptrTwo->dataZ;
    ptrOne->typeDive = ptrTwo->typeDive;
    ptrOne->moveType = ptrTwo->moveType;
    ptrOne->moveTypeDepth = ptrTwo->moveTypeDepth;
    ptrOne->hoodPoint = ptrTwo->hoodPoint;
    ptrTwo->typeMission = typeMission;
    ptrTwo->dataX = dataX;
    ptrTwo->dataY = dataY;
    ptrTwo->dataZ = dataZ;
    ptrTwo->typeDive = typeDive;
    ptrTwo->moveType = moveType;
    ptrTwo->moveTypeDepth = moveTypeDepth;
    ptrTwo->hoodPoint = hoodPoint;
}

inline bool List::correctIndex(int index)
{
    if ((index >= 0) and (index < count))
        return true;
    else
    {
        cout << "��������� ������ �� �������� ����������, �� ������ ������ ����� ���������: " << count << endl;
        return false;
    }
}
