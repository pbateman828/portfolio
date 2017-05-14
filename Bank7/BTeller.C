#include "BTeller.h"
#include "myBank.h"
#include "Customer.h"
#include <iostream>

using namespace std;

//Construtors of badTeller using the teller class

BTeller::BTeller() : Teller() { }

BTeller::BTeller(myBank &money) : Teller(money) { }

//Definition of break length, time per customer and telleridlelength
BTeller::BTeller(myBank &money, int identification) : Teller(money, identification) {
    breaklen = 600;

    timeperCust = 2;

    telleridleLength = 60;
}


BTeller::~BTeller() { }

//conditionals stating what the badteller does at specific times
void BTeller::Run() {
    //Bank closed
    if (bank->status == closed) {

        if (servingCustomer) {

            cout << "The bad teller has finished serving their customer" << endl;
        }

        return;
    }
    //idle time
    if (status == standstill) {

        if (random() % 2 == 1) {

            idletimeofteller();

            return;
        }

        Customer *customer = bank->FirstCustomer();

        if (customer != NULL) {

            serveCustomer(*customer);
        }

        else {

            restofteller();
        }
        //after rest
    } else if (status == rest) {

        Customer *customer = bank->FirstCustomer();

        if (customer != NULL) {

            serveCustomer(*customer);
        } else {

            idletimeofteller();
        }
    } else {

        cout << "The bad teller has finished with their customer" << endl;

        if (master - 3600 >= lastbreaktime) {

            restofteller();

            return;
        } else if (random() % 2 == 1) {

            idletimeofteller();

            return;
        }
        Customer *customer = bank->FirstCustomer();
        if (customer != NULL) {

            serveCustomer(*customer);
        } else {

            if ((random() % 2 == 1 && bank->getStateOfManager() == office)) {

                restofteller();
            } else {

                idletimeofteller();
            }

        }
    }
}
