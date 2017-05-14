#include <stddef.h>
#include <memory.h>
#include <iostream>
#include <stdlib.h>
#include "Item.h"
#include "myBank.h"
#include "Customer.h"

using namespace std;

// the default constructor
Customer::Customer() {

    transactionTime = random() % (1199 - 600 + 1) + 600;

    customerID = 0;

    int waitingTime = 0;

    state = notHelped;

    master = waitingTime;

}

//Constructor calculating the wait time
Customer::Customer(myBank &b, int waitTime) {

    bank = &b;

    transactionTime = random() % (1199 - 600 + 1) + 600;

    customerID = 0;

    waitingTime = waitTime;

    state = notHelped;

    master = waitingTime;
}
//including customer ID
Customer::Customer(myBank &b, int waitTime, int ID) {

    bank = &b;

    waitingTime = waitTime;

    customerID = ID;

    state = notHelped;

    transactionTime = random() % (1199 - 600 + 1) + 600;

    master = waitingTime;
}

//Output of customer is served or not using id
void Customer::Run() {
    if (state == helped) {

        bank->score += 10;

        bank->servedCustomers += 1;

        cout << "The Customer " << customerID << " served." << endl;
    } else {

        bank->score -= 10;

        bank->customerList.pop_back();

        cout << "The Customer " << customerID << " not served." << endl;
    }
}
