#ifndef LABA4_2_EL_V_H
#define LABA4_2_EL_V_H

#include "FormG.h"


class El_V {
public:
    FormG* formG;
    El_V* next;

public:
    El_V(FormG* form){
        this->formG = form;
        this->next = nullptr;
    }

    El_V *getNext();

    void setNext(El_V *next);

};


#endif