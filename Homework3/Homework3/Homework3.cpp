#include <iostream>
#include <iomanip>
#include <string>
#include "StateMachine.h"

int main() {
    setlocale(LC_ALL, "rus");
    List* list = new List();
    StateMachine fsm;
    fsm.start(list);
    delete list;
    return 0;
}