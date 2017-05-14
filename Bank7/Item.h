#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item {
public:
    //keeps track of time
    int master;

    virtual void Run() { };

    Item() : master(0) { }

    virtual ~Item() { }
};

struct compareItem : binary_function<Item *, Item *, bool> {
    bool operator()(const Item *t1, const Item *t2) {
        return (t1->master > t2->master);
    }
};

#endif
