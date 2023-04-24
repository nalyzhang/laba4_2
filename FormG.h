#ifndef LABA4_2_FORMG_H
#define LABA4_2_FORMG_H

#include "StrL.h"
#include "El_G.h"
#include <iostream>


class FormG {
public:
    El_G* head;
    El_G* tail;

public:
    FormG(){
        this->head = this->tail = nullptr;
        //std::cout << "Горизонтальный список создан\n";
    }

    ~FormG(){
        while (this->head != nullptr) pop_front();
        //if((this->head == nullptr)&&(this->tail == nullptr)) std::cout << "Горизонтальный список удален\n";
    }

    void pop_front();

    El_G *getHead();

    void setHead(El_G *h);

    El_G *getTail();

    void setTail(El_G *t);

    void push_back(El_G* node);

};

#endif