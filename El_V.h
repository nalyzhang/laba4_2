#ifndef LABA4_2_EL_V_H
#define LABA4_2_EL_V_H

#include "FormG.h"


class El_V {
private:
    FormG* formG;
    El_V* next;

public:
    El_V(FormG* form){
        this->formG = form;
        this->next = nullptr;
        std::cout << "Элемент вертикального списка создан \n";
    }

    FormG* getFormG();

    void setFormG(FormG* item);

    El_V *getNext();

    void setNext(El_V *next);

};


#endif