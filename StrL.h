#ifndef L2_4_STRL_H
#define L2_4_STRL_H

#include <iostream>

class StrL {
public:
    char* data;
    int length;
    int N = 10;
public:
    StrL() {
        this->length = N;
        this->data = new char[N];
        for (int i = 0; i < this->length; i++) this->data[i] = ' ';
    }

    ~StrL() {
        free(this->data);
    }

    void setData(char* text, int l);

    void setLength(int l);
};


#endif
