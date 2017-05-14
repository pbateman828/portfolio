#include <iostream>
#include <time.h>
#include "Manager.h"
#include "Item.h"
#include "myBank.h"

using namespace std;

int main(int argc, char *argv[]) {
    //random time at zero

    srandom(time(0));

    //Start of Report

    cout<< "------------------------------------" <<endl;

    cout << "Start of BankReport" << endl;

    cout<< "------------------------------------" <<endl;

    int badtel, goodtel;

    //Get number of good tellers from user

    cout << "Enter Good Tellers: " << endl;

    cin >> goodtel;

    cout<< "------------------------------------" <<endl;

    //get number of badtellers from user

    cout << "Enter Bad Tellers: " << endl;

    cin >> badtel;

    cout<< "------------------------------------" <<endl;
    //Put the number of tellers into BankClass
    //Run report until there is nothing left

    myBank bfinal(goodtel, badtel);

    while (!bfinal.pq.empty()) {

        bfinal.pq.top()->Run();

        bfinal.pq.pop();
    }
    //If finished, tell user it is finished and read Report.txt

    cout<< "--------------------------------------------" <<endl;

    cout << "** Finished with bank Report. Read Report.txt  **" << endl;

    cout<< "----------------------------------------------" <<endl;

    bfinal.Report();
}
