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
    std::ofstream out;

    explicit files(const char in[] = "in.txt", const char out[] = "out.txt") {
        this->in.open(in);
        this->out.open(out);
    }

    ~files() {
        this->out.close();
        this->in.close();
    }

    void result();

    void readIn(FormV& formV);

    void printList(El_G *lst);
};

#endif
