#include "files.h"
#include <iostream>

void files::readIn(FormV& formV) {
    char w;
    this->in.unsetf(std::ios::skipws);
    if (this->in.eof() == 0) {
        while (true) {
            FormG formG;
            StrL help;
            int c = 10;
            char *str = new char[help.getN()];
            for (int j = 0; j < 10; j++) {
                this->in >> w;
                if (this->in.eof()) {
                    str[j] = '\n';
                    c = j + 1;
                    break;
                }
                str[j] = w;
                if (w == '\n') {
                    c = j+1;
                    break;
                }
            }
            El_G *node = new El_G(str, c);
            help.setData(str, c);
            delete[] str;
            formG.push_back(node);
            if ((w == '\n') || this->in.eof()) {
                formV.push_back(&formG);
            }
            if (this->in.eof()) break;
        }
        for (El_V* node = formV.getHead(); node != nullptr; node = node->getNext()) {
//            for (El_G* n = node->getFormG()->getHead(); n != nullptr; n = n->getNextItem()) {
//                std::cout << n->getItem().getLength() << "\n";
//                for (int j = 0; j < n->getItem().getLength(); j++)
//                    this->out << n->getItem().getData()[j];
//                this->out << "->";
//                if (n->getNextItem() == nullptr) this->out << "NULL";
//            }
            this->out << "\\|/ \n";
        }
    }
}

void files::result() {
    if (in.is_open()) {
        FormV lst;
        this->readIn(lst);
        bool flag;
        if (lst.getHead() == nullptr) flag = false;
        else flag = true;
        if (out.is_open()) {
            this->out << "Панина Анастасия \n2309 \nИндивидуальное задание №3 \n|\nБыл считан текст: \n";
            if (flag) {
//                for (El_V* node = lst.getHead(); node != nullptr; node = node->getNext()) {
//                    for (El_G* n = node->getFormG()->getHead(); n != nullptr; n = n->getNextItem()) {
//                        std::cout << n->getItem().getLength() << "\n";
//                        for (int j = 0; j < n->getItem().getLength(); j++)
//                            this->out << n->getItem().getData()[j];
//                        this->out << "->";
//                        if (n->getNextItem() == nullptr) this->out << "NULL";
//                    }
//                    this->out << "\\|/ \n";
//                }
            } else this->out << "\nНет текста.\n";
        }
    }
    this->out << "Программа завершила свою работу";
}