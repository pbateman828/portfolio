#ifndef TELLER_H
#define TELLER_H

#include "Item.h"

class myBank;

class Customer;
//easier

enum {
    standstill, rest, working
};

class Teller : public Item {

//use of protected variables

protected:

    int tellernum;

    int status;

    int lastbreaktime;


    int breaklen;

    int timeperCust;

    int telleridleLength;

    bool servingCustomer;

    myBank *bank;

    void serveCustomer(Customer &customer);

    void restofteller();

    void idletimeofteller();

public:
    //number of customers served
    int numCustomersServed;

    Teller();

    Teller(myBank &);

    Teller(myBank &, int);
    //virtual
    virtual ~Teller();
};

#endif
