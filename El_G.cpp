#include "El_G.h"

StrL El_G::getItem(){
    return this->item;
}

void El_G::setItem(StrL text){
    this->item.setData(text.getData(), text.getLength());
}

El_G* El_G::getNextItem(){
    return this->nextItem;
}

void El_G::setNextItem(El_G* next){
    this->nextItem = next;
}