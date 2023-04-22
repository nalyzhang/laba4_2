#include "El_V.h"

FormG* El_V::getFormG(){
    return this->formG;
}

void El_V::setFormG(FormG* item) {
    this->formG = item;
}

El_V *El_V::getNext() {
    return next;
}

void El_V::setNext(El_V *next) {
    El_V::next = next;
}
