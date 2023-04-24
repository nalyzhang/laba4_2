#ifndef LAB2_2_FILES_H
#define LAB2_2_FILES_H
#include <fstream>
#include "StrL.h"
#include "FormG.h"
#include "FormV.h"
#include "El_V.h"
#include "El_G.h"

class files {

public:

    std::ifstream in;
    std::ifstream in1;
    std::ofstream out;

    explicit files(const char in[] = "in.txt", const char out[] = "out.txt", const char in1[] = "in1.txt") {
        this->in.open(in);
        this->out.open(out);
        this->in1.open(in1);
    }

    ~files() {
        this->out.close();
        this->in.close();
        this->in1.close();
    }

    void result();

    void readIn(FormV& formV, FormG* formG);

    void readIn1(FormV &formV, FormG *formG);
};

#endif
