#ifndef L2_4_EL_G_H
#define L2_4_EL_G_H

#include "StrL.h"
#include <iostream>


class El_G {
private:
    StrL item;
    El_G* nextItem;

public:
    El_G(char* text, int l) {
        this->item.setData(text, l);
        this->nextItem = nullptr;
    }

    StrL getItem();

    void setItem(StrL text);

    El_G* getNextItem();

    void setNextItem(El_G* next);
};


#endif
