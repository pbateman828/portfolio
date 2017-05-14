#ifndef MYBANK_H
#define MYBANK_H

#include <queue>
#include <list>
#include <iostream>
#include "Item.h"
#include "Manager.h"
#include "Customer.h"
#include "Teller.h"

using namespace std;

enum {
    open, closed
};

//myBank class using Item
class myBank : Item {
public:

    //Efficient score
    int score;

    int status;
    //status of tellers

    int numCustomers;

    int servedCustomers;

    Manager *manager;

    priority_queue<Item *, vector<Item *>, compareItem> pq;

    list<Customer *> customerList;

    list<Teller *> tellerList;

    myBank();

    myBank(int, int);
    //Virtual
    virtual ~myBank();
    //myBank Report
    void Report();

    Customer *FirstCustomer();

    bool getStateOfManager();

    void Run();
};

#endif
