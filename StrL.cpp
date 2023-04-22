#include "StrL.h"

char* StrL::getData() {
    return this->data;
}

int StrL::getLength() {
    return this->length;
}

void StrL::setData(char* text, int l){
    this->setLength(l);
    delete[] this->data;
    this->data = new char[l];
    for (int i = 0; i < l; i++) this->data[i] = text[i];
}

void StrL::setLength(int l){
    this->length = l;
}