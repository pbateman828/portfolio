#include "Teller.h"
#include "myBank.h"



//start the tellers with the master at zero.
//starting fresh
Teller::Teller() {

    master = 0;

    tellernum = 0;

    //standstill is also idle time

    status = standstill;

    lastbreaktime = 0;

    servingCustomer = false;
}
//pass to the bank
Teller::Teller(myBank &b) {

    master = 0;

    tellernum = 0;

    //idle

    status = standstill;

    lastbreaktime = 0;

    servingCustomer = false;

    bank = &b;
}
//pass with identification
Teller::Teller(myBank &b, int id) {

    master = 0;

    tellernum = id;

    //idle

    status = standstill;

    lastbreaktime = 0;

    servingCustomer = false;

    bank = &b;
}
//deconstructor
Teller::~Teller() { }

//when the teller is working
void Teller::serveCustomer(Customer &customer) {

    status = working;

    servingCustomer = true;

    master = master + (timeperCust * customer.getTransactionTime());

    customer.setServed();

    numCustomersServed++;

    cout << "Current teller " << tellernum << " is with a customer " <<

    customer.getID() << " finishing in "

    << customer.getTransactionTime() << "s" << endl;

    bank->pq.push(this);
}
//when the teller is resting
void Teller::restofteller() {

    status = rest;

    lastbreaktime = master;

    servingCustomer = false;

    master += breaklen;

    cout << "Current Teller " << tellernum << " on break " <<

    "will be back in " << master << "s" << endl;

    bank->pq.push(this);
}
//when the teller is not on break and not working with a customer but idle
void Teller::idletimeofteller() {

    status = standstill;

    servingCustomer = false;

    //standingstill

    master += telleridleLength;

    cout << "Current Teller " << tellernum << " is not doing anything "

    << " and is standstill" << endl;

    bank->pq.push(this);
}
