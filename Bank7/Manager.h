#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include "Item.h"

using namespace std;
//using enum to make life easier
enum {
    //either he is in his office or he is serving customers
    visit, office
};
//include bank class
class myBank;

class Manager : public Item {
    int status;

    int managerID;

    int nextVisitTime;

    int numberCustomersServed;

    int currentlyServingCustomer;

    myBank *bank;
public:
    //passing the manager to the bank class
    Manager();

    Manager(myBank &);
    //virtual
    virtual ~Manager();
    //Report run
    void Run();

    bool getState() { return status; }
};

#endif
