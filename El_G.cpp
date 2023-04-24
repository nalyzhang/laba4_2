#include "El_G.h"

El_G* El_G::getNextItem(){
    return this->nextItem;
}

void El_G::setNextItem(El_G* next){
    this->nextItem = next;
}