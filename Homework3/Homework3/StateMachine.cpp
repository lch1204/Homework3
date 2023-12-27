#include "StateMachine.h"

void StateMachine::start(List* list)
{
    int choice;
    cout << "Добрый день, вы находитесь в начальном состоянии 1" << endl;
    cout << "1) Вы можете перейти в состояние 2 и начать планирование миссии" << endl;
    cout << "2) Вы можете перейти в состояние 3 и загрузить миссию из файла" << endl;
    cout << "3) Вы можете перейти в состояние 0 и завершить работу" << endl;
    do {
        displayMenu();
        std::cin >> choice;

        switch (currentState) 
        {
        case 1:
            cout << "Вы находитесь в начальном состоянии 1" << endl;
            beginState1(choice, list);
            break;

        case 2:
            cout << "Вы находитесь в состоянии 2 - создание миссии" << endl;
            newMissionState2(choice);
            break;

        case 3:
            cout << "Вы находитесь в состоянии 3 - загрузка миссии из файла" << endl;
            fromFileState3(choice);
            break;

        case 4:
            cout << "Вы находитесь в состоянии 4 - развязка между разными состояниями" << endl;
            whatDoState4(choice, list);
            break;
        
        case 5:
            cout << "Вы находитесь в состоянии 5 - планирование миссии" << endl;
            State5(choice, list);
            break;
        case 6:
            cout << "Вы находитесь в состоянии 6 - проверка миссии" << endl;
            testState6(choice, list);
            break;
        case 7:
            cout << "Вы находитесь в состоянии 7 - удаление задач" << endl;
            eraseState7(choice, list);
            break;
        case 8:
            cout << "Вы находитесь в состоянии 8 - вывод миссии" << endl;
            printState8(choice, list);
            break;
        case 9:
            cout << "Вы находитесь в состоянии 9 - перестановка команд" << endl;
            swapState9(choice, list);
            break;

        case 10:
            cout << "Вы находитесь в состоянии 10 - завершениие миссии" << endl;
            endState10(choice, list);
            break;

        default:
            std::cerr << "Ошибка: Недопустимое состояние" << std::endl;
            break;
        }
    } while (currentState != 0);  // Прерывание цикла при вводе 0

}

void StateMachine::beginState1(int choice, List* list)
{
    switch (choice) 
    {
    case 2:
        std::cout << "Переход из Состояния 1 в Состояние 2" << std::endl;
        currentState = 2;
        nameState = "4";
        newMission(list);
        break;

    case 3:
        std::cout << "Переход из Состояния 1 в Состояние 3" << std::endl;
        currentState = 3;
        nameState = "4";
        fromFile(list);
        break;

    case 0:
        std::cout << "Завершение программы" << std::endl;
        currentState = 0;
        break;

    default:
        std::cout << "Недопустимый ввод" << std::endl;
        break;
    }
}

void StateMachine::newMissionState2(int choice)
{
    switch (choice)
    {
    case 2:
        std::cout << "Остаемся в Состоянии 2" << std::endl;
        break;

    case 4:
        std::cout << "Переход из Состояния 2 в Состояние 4" << std::endl;
        currentState = 4;
        nameState = "5, 6, 7, 8, 9, 10";
        break;

    default:
        std::cout << "Недопустимый ввод" << std::endl;
        break;
    }
}

void StateMachine::fromFileState3(int choice)
{
    switch (choice) 
    {
    case 4:
        std::cout << "Переход из Состояния 3 в Состояние 4" << std::endl;
        currentState = 4;
        nameState = "5, 6, 7, 8, 9, 10";
        break;

    default:
        std::cout << "Недопустимый ввод" << std::endl;
        break;
    }
}

void StateMachine::whatDoState4(int choice, List* list)
{
    switch (choice)
    {
    case 4:
        std::cout << "Остаемся в Состоянии 4" << std::endl;
        break;

    case 5:
        std::cout << "Переход из Состояния 4 в Состояние 5" << std::endl;
        currentState = 5;
        newPoint(list);
        nameState = "4, 5";
        break;

    case 6:
        std::cout << "Переход из Состояния 4 в Состояние 6" << std::endl;
        currentState = 6;
        nameState = "4";
        list->test();
        break;

    case 7:
        std::cout << "Переход из Состояния 4 в Состояние 7" << std::endl;
        currentState = 7;
        nameState = "4, 7";
        erase(list);
        break;

    case 8:
        std::cout << "Переход из Состояния 4 в Состояние 8" << std::endl;
        currentState = 8;
        nameState = "4, 8";
        list->print();
        break;

    case 9:
        std::cout << "Переход из Состояния 4 в Состояние 9" << std::endl;
        currentState = 9;
        nameState = "4, 9";
        swap(list);
        break;

    case 10:
        std::cout << "Переход из Состояния 4 в Состояние 10" << std::endl;
        currentState = 10;
        nameState = "1";
        end(list);
        break;

    default:
        std::cout << "Недопустимый ввод" << std::endl;
        break;
    }
}

void StateMachine::State5(int choice, List* list)
{
    switch (choice)
    {
    case 4:
        std::cout << "Переход из Состояния 5 в Состояние 4" << std::endl;
        currentState = 4;
        nameState = "5, 6, 7, 8, 9, 10";
        break;

    case 5:
        std::cout << "Остаемся в Состоянии 5" << std::endl;
        nameState = "4, 5";
        newPoint(list);
        break;


    default:
        std::cout << "Недопустимый ввод" << std::endl;
        break;
    }
}

void StateMachine::testState6(int choice, List* list)
{
    switch (choice)
    {
    case 4:
        std::cout << "Переход из Состояния 6 в Состояние 4" << std::endl;
        currentState = 4;
        nameState = "5, 6, 7, 8, 9, 10";
        break;

    case 6:
        std::cout << "Остаемся в Состоянии 6" << std::endl;
        list->test();
        break;

    default:
        std::cout << "Недопустимый ввод" << std::endl;
        break;
    }
    
}

void StateMachine::eraseState7(int choice, List* list)
{
    switch (choice)
    {
    case 4:
        std::cout << "Переход из Состояния 7 в Состояние 4" << std::endl;
        currentState = 4;
        nameState = "5, 6, 7, 8, 9, 10";
        break;

    case 7:
        std::cout << "Остаемся в Состоянии 7" << std::endl;
        erase(list);
        break;

    default:
        std::cout << "Недопустимый ввод" << std::endl;
        break;
    }
}

void StateMachine::printState8(int choice, List* list)
{
    switch (choice)
    {
    case 4:
        std::cout << "Переход из Состояния 8 в Состояние 4" << std::endl;
        currentState = 4;
        nameState = "5, 6, 7, 8, 9, 10";
        break;

    case 8:
        std::cout << "Остаемся в Состоянии 8" << std::endl;
        list->print();
        break;

    default:
        std::cout << "Недопустимый ввод" << std::endl;
        break;
    }
}

void StateMachine::swapState9(int choice, List* list)
{
    switch (choice)
    {
    case 4:
        std::cout << "Переход из Состояния 9 в Состояние 4" << std::endl;
        currentState = 4;
        nameState = "5, 6, 7, 8, 9, 10";
        break;

    case 9:
        std::cout << "Остаемся в Состоянии 9" << std::endl;
        swap(list);
        break;

    default:
        std::cout << "Недопустимый ввод" << std::endl;
        break;
    }
}

void StateMachine::endState10(int choice, List* list)
{
    switch (choice)
    {
    case 1:
        std::cout << "Переход из Состояния 10 в Состояние 1" << std::endl;
        currentState = 1;
        nameState = "2,3";
        break;


    default:
        std::cout << "Недопустимый ввод" << std::endl;
        break;
    }
}

void StateMachine::newMission(List* list)
{
    cout << "Создаем новую миссию" << endl;
    list->newFile();
}

void StateMachine::fromFile(List* list)
{
    cout << "Загрузим миссию из файла" << endl;
    list->readFile();
}

void StateMachine::newPoint(List* list)
{
    cout << "Вы можете заглубиться (1), всплывать (2)," << endl;
    cout << "выйти в точку в плоскости (x,y) (3) или выйти из планирования (0)" << endl;
    cout << "Введите нужную цифру: ";
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
            cout << "Вы выбрали погружение, введите глубину на которую необходимо погрузиться аппарату: ";
            cin >> dataZ;
            if ((dataZ < 0) or (dataZ > 100) or (list->depth > dataZ))
                cout << "Введеное значение не корректно, попробуйте еще раз" << endl;
        } while ((dataZ < 0) or (dataZ > 100) or (list->depth > dataZ));
        do
        {
            cout << "Погружение может происходить по спирали(1), или вертикально за счет движетелей (2)" << endl;
            cout << "Выберите тип погружения: ";
            cin >> diveTypeInt;
            if (diveTypeInt == 1) diveType = "spiral";
            if (diveTypeInt == 2) diveType = "vertical";
            if ((diveTypeInt < 0) or (diveTypeInt > 3))
                cout << "Введеное значение не корректно, попробуйте еще раз" << endl;
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
            cout << "Вы выбрали всплытие, введите глубину на которую необходимо всплыть аппарату: ";
            cin >> dataZ;
            if ((dataZ < 0) or (dataZ > 100) or (list->depth < dataZ))
                cout << "Введеное значение не корректно, попробуйте еще раз" << endl;
        } while ((dataZ < 0) or (dataZ > 100) or (list->depth < dataZ));
        do
        {
            cout << "Всплытие может происходить по спирали(1), или вертикально за счет движетелей (2)" << endl;
            cout << "Выберите тип погружения: ";
            cin >> diveTypeInt;
            if (diveTypeInt == 1) diveType = "spiral";
            if (diveTypeInt == 2) diveType = "vertical";
            if ((diveTypeInt < 0) or (diveTypeInt > 3))
                cout << "Введеное значение не корректно, попробуйте еще раз" << endl;
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
            cout << "Вы выбрали выход в точку, введите координаты X Y через пробел: ";
            cin >> dataX >> dataY;
            if (((dataX < 0) or (dataX > 10000)) and ((dataY < 0) or (dataY > 10000)))
                cout << "Введеное значение не корректно, попробуйте еще раз" << endl;
        } while (((dataX < 0) or (dataX > 10000)) and ((dataY < 0) or (dataY > 10000)));
        do
        {
            cout << "Движение может быть в точку (1) или вдоль прямой (2)" << endl;
            cout << "Выберите тип движения: ";
            cin >> moveTypeInt;
            if (moveTypeInt == 1) moveType = "point";
            if (moveTypeInt == 2) moveType = "line";
            if ((moveTypeInt < 0) or (moveTypeInt > 3))
                cout << "Введеное значение не корректно, попробуйте еще раз" << endl;
        } while ((moveTypeInt < 0) or (moveTypeInt > 3));
        do
        {
            cout << "Движение может быть с постоянной глубиной (1) или нет (2)" << endl;
            cout << "Выберите тип движения: ";
            cin >> moveTypeInt;
            if (moveTypeInt == 1) moveTypeDepth = "depthConst";
            if (moveTypeInt == 2) moveTypeDepth = "depthNoConst";
            if ((moveTypeInt < 0) or (moveTypeInt > 3))
                cout << "Введеное значение не корректно, попробуйте еще раз" << endl;
        } while ((moveTypeInt < 0) or (moveTypeInt > 3));
        list->coordX = dataX;
        list->coordY = dataY;
        mv.writeNewCommand(list, "move", dataX, dataY, -1, "no", moveType, moveTypeDepth, 5);
        list->print();
    }
    if ((status > 3)or (status < 0)) cout << "Вы ошиблись, попробуйте позднее" << endl;
}

void StateMachine::erase(List* list)
{
    int index;
    do
    {
        cout << "Введите какой номер команды вы хотите удалить: ";

        cin >> index;
        if (index > list->count)
            cout << "Введенный индекс не корректен, попробуйте еще раз" << endl;
    } while (index > list->count);
    list->erase(index);
}

void StateMachine::swap(List* list)
{
    int index1, index2;
    cout << "Введите индексы команд, которые вы бы хотели поменять местами: ";
    cin >> index1 >> index2;
    list->swapNode(index1, index2);
}

void StateMachine::end(List* list)
{
    int res = list->test();
    if (res != 0)
    {
        cout << "Простите, но вы не можете завершить миссию, насильно переводим вас в 4 состояние" << endl;
        currentState = 4;
        nameState = "5, 6, 7, 8, 9, 10";
        return;
    }
    cout << "Давайте вернемся назад на базу c координатами 0, 0, 0" << endl;
    Return rn;
    rn.writeNewCommand(list, "return", 0, 0, 0, "no", "no", "no", 0);
    cout << "Итоговая миссия" << endl;
    list->print();
    cout << "Запишим файл: " << list->nameTXT <<endl;
    int result = list->saveFile();
    if (result == 0)
    {
        cout << "Миссия успешно сохранена" << endl;
        
        currentState = 0;
        return;
    }
    else 
    {
        cout << "Миссия не сохранена" << endl;
        currentState = 4;
        nameState = "5, 6, 7, 8, 9, 10";
        return;
    }
        
}
