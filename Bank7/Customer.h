#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <stddef.h>
#include <memory.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Item.h"
#include "myBank.h"

using namespace std;

enum {
    helped, notHelped
};

class Customer : public Item {
    myBank *bank;

    int transactionTime;

    int customerID;

    int waitingTime;

    bool state;
public:

    virtual ~Customer() { }


    Customer();


    Customer(myBank &b, int waitTime);


    Customer(myBank &b, int waitTime, int ID);

    int getTransactionTime() { return transactionTime; }

    int getID() { return customerID; };

    void setServed() { state = helped; }

    bool getState() { return state; }

    void Run();
};

#endif
