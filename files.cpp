#include "files.h"
#include <iostream>

void files::readIn(FormV& formV) {
    char w;
    this->in.unsetf(std::ios::skipws);
    if (this->in.eof() == 0) {
        while (this->in.eof() == 0) {
            FormG formG;
            StrL help;
            int c = 10;
            char str[help.getN()];
            for (int j = 0; j < 10; j++) {
                this->in >> w;
                if (this->in.eof()) {
                    str[j] = '\n';
                    c = j + 1;
                    break;
                }
                std::cout << w;
                str[j] = w;
                if (w == '\n') {
                    c = j + 1;
                    break;
                }
            }
            El_G *node = new El_G(str, c);
            help.setData(str, c);
            formG.push_back(node);
            if ((w == '\n') || this->in.eof()) formV.push_back(&formG);
        }
    }
}

void files::result() {
    if (in.is_open()) {
        FormV lst;
        this->readIn(lst);
        if (out.is_open()) {
            for (El_V* node = lst .getHead(); node != nullptr; node = node->getNext()) {
//                for (El_G* n = node->getFormG()->getHead(); n != nullptr; n = n->getNextItem()) {
//                    for (int j = 0; j < n->getItem().getLength(); j++)
//                        std::cout << n->getItem().getData()[j];
//                    std::cout << "->";
//                    if (n->getNextItem() == nullptr) std::cout << "NULL";
//                }
                std::cout << "\n\\|/ \n";
            }
            this->out << "Панина Анастасия \n2309 \nИндивидуальное задание №4 \n\nБыл считан текст 1: \n";

            this->out << "\nИ обработан:\n";

            this->out << "\nБыл считан текст 2:\n";

            this->out << "\nИ обработан:\n";

            this->out << "\nПолучился текст:\n";

        }
    }
    this->out << "Программа завершила свою работу";
}