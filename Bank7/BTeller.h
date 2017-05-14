#ifndef BTELLER_H
#define BTELLER_H

#include "Teller.h"

class myBank;

class BTeller : public Teller {
public:
    BTeller();

    BTeller(myBank &money);

    BTeller(myBank &money, int identification);
    //virtual function
    virtual ~BTeller();
    //Runs the report
    void Run();
};

#endif
