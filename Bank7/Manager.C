#include "Manager.h"
#include "myBank.h"
#include "Customer.h"
#include <iostream>

using namespace std;


//Manager class
Manager::Manager() {
    managerID = 1;
    //status means he in his office. where he is currently
    status = office;
    //when he comes out of his office to help a customer
    master = nextVisitTime = 3600;
    //he can't serve a customer in his office
    currentlyServingCustomer = false;
}
//passing the manager to the bank
Manager::Manager(myBank &b) {

    managerID = 1;

    bank = &b;

    status = office;

    master = nextVisitTime = 3600;

    currentlyServingCustomer = false;
}
//deconstructor
Manager::~Manager() { }

//manger is now included in the report
void Manager::Run() {
    if (master % 3600 == 0 && bank->status == open) {

        status = visit;
        //the manager has come out of his office(domain).

        nextVisitTime += 3600;

        Customer *customer = bank->FirstCustomer();

        if (customer == NULL) {

            master = nextVisitTime;

            status = office;

            bank->pq.push(this);

            return;
        }
        //serving customers
        numberCustomersServed++;

        master = master + customer->getTransactionTime();

        customer->setServed();

        currentlyServingCustomer = true;
        //name of manager is steve

        cout << "Steve the manager is not in his office and is serving a customer " << customer->getID()

        << " Steve will finish and return to his domain in " << customer->getTransactionTime() << "s." << endl;

        bank->pq.push(this);
        //the manager is returning to his office after his service of the customer is done.
    } else if (master > 3600 && currentlyServingCustomer) {

        status = office;

        master = nextVisitTime;

        currentlyServingCustomer = false;

        bank->pq.push(this);

        cout << " Steve returned to his domain " << endl;
    }

}
