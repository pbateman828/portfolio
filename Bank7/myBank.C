#include "myBank.h"
#include "Customer.h"
#include "GodTeller.h"
#include "BTeller.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;
//myBank class
myBank::myBank() {

    score = 0;

    status = open;

    numCustomers = 0;

    servedCustomers = 0;


    // good tellers
    GodTeller *gt;

    for (int i = 1; i < 6; i++) {

        gt = new GodTeller(*this, i);

        tellerList.push_front(gt);

        pq.push(gt);
    }

    // Bad tellers
    BTeller *bt;

    for (int i = 1; i < 11; i++) {

        bt = new BTeller(*this, 5 + i);

        tellerList.push_front(bt);

        pq.push(bt);
    }

    // Manager
    manager = new Manager(*this);

    pq.push(manager);

    pq.push(this);
}

myBank::myBank(int numGoodTellers, int numBadTellers) {

    score = 0;

    status = open;

    numCustomers = 0;

    servedCustomers = 0;

    // good tellers
    GodTeller *gt;
    for (int i = 1; i <= numGoodTellers; i++) {

        gt = new GodTeller(*this, i);

        tellerList.push_front(gt);

        pq.push(gt);
    }

    // bad tellers
    BTeller *bt;

    for (int i = 1; i <= numBadTellers; i++) {

        bt = new BTeller(*this, numGoodTellers + i);

        tellerList.push_front(bt);

        pq.push(bt);
    }

    // Manager
    manager = new Manager(*this);

    pq.push(manager);


    pq.push(this);
}
//making sure there isn't any memory leaks
myBank::~myBank() {

    tellerList.clear();

    customerList.clear();

    while (!pq.empty()) pq.pop();

    delete manager;
}
//first customer
Customer *myBank::FirstCustomer() {

    if (customerList.size() == 0) return NULL;

    Customer *c = customerList.back();

    customerList.pop_back();

    return c;
}
//what is the manager doing
bool myBank::getStateOfManager() {

    return manager->getState();
}

//using the time of the bank to determine where to close or not
void myBank::Run() {
    if (master >= 28800) {

        status = closed;

        cout << "The myBank closed thier doors." << endl;

        return;
    }
    else {
        //bank time using random and updating
        int bankTime = random() % (120 - 60 + 1) + 60;

        master += bankTime;

        numCustomers++;

        Customer *newCust = new Customer(*this, master, numCustomers);

        pq.push(newCust);

        customerList.push_front(newCust);

        pq.push(this);
    }

}

//This is the output to the text file using ofstream
void myBank::Report() {

    ofstream out;

    out.open("Report.txt");

    out << numCustomers << " customers entered myBank" << endl << servedCustomers <<
    " customers was served in myBank" << endl <<
    "This is based on how well the tellers and the manager did during the time period" << endl <<
    "Based on the myBank's standards the efficiency of it is " << score << endl;

    out.close();

}
