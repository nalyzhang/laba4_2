#ifndef LABA4_2_FORMV_H
#define LABA4_2_FORMV_H

#include "El_V.h"


class FormV {
public:
    El_V* head;
    El_V* tail;

public:

    FormV(){
        this->head = this->tail = nullptr;
        std::cout << "Вертикальный список создан\n";
    }

    ~FormV(){
        while (this->head != nullptr) pop_front();
        if((this->head == nullptr)&&(this->tail == nullptr)) std::cout << "Вертикальный список удален\n";
    }

    void pop_front();

    El_V *getHead();

    void setHead(El_V *h);

    El_V *getTail();

    void setTail(El_V *t);

    void push_back(FormG* form);

    void processing();
};


#endif
