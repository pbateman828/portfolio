#ifndef GODTELLER_H
#define GODTELLER_H

#include "Teller.h"

class myBank;

class GodTeller : public Teller {
public:

    GodTeller();

    GodTeller(myBank &b);

    GodTeller(myBank &b, int identification);

    virtual ~GodTeller();

    void Run();
};

#endif
