#include "GodTeller.h"
#include "myBank.h"
#include "Customer.h"
#include <iostream>

using namespace std;

GodTeller::GodTeller() : Teller() { }

GodTeller::GodTeller(myBank &b) : Teller(b) { }

//the good teller takes a shorter break than the bad teller
//Goodteller is faster and has less idletime
GodTeller::GodTeller(myBank &b, int identification) : Teller(b, identification) {

    breaklen = 300;

    timeperCust = 1;

    telleridleLength = 30;
}

GodTeller::~GodTeller() { }

//Determining what time it is and what the goodteller is doing
void GodTeller::Run() {
    //closing time
    if (bank->status == closed) {

        if (servingCustomer) {

            cout << "The good teller has finished with their work" << endl;
        }
        return;
    }
    //idle time
    if (status == standstill) {

        Customer *customer = bank->FirstCustomer();

        if (customer != NULL) {
            serveCustomer(*customer);
        }
        else if (master - 3600 >= lastbreaktime) {

            restofteller();
        } else {

            idletimeofteller();
        }
        //rest
    } else if (status == rest) {

        Customer *customer = bank->FirstCustomer();

        if (customer != NULL) {

            serveCustomer(*customer);
        } else {

            idletimeofteller();
        }
    } else {

        cout << "The  good teller has finished with their work" << endl;

        Customer *customer = bank->FirstCustomer();
        if (customer != NULL) {


            serveCustomer(*customer);
        } else if (master - 3600 >= lastbreaktime) {


            restofteller();
        } else {

            idletimeofteller();
        }
    }
}
