#include "El_V.h"

El_V *El_V::getNext() {
    return next;
}

void El_V::setNext(El_V *next) {
    El_V::next = next;
}
