#include "files.h"
#include <iostream>

void files::readIn(FormV& formV, FormG* formG) {
    char w;
    int i = 0;
    this->in.unsetf(std::ios::skipws);
    if (this->in.eof() == 0) {
        while (!this->in.eof()) {
            int c = 10;
            char str[10];
            for (int j = 0; j < 10; j++) {
                this->in >> w;
                if ((this->in.eof())||(w == '\n')) {
                    c = j;
                    break;
                }
                str[j] = w;
            }
            El_G *node = new El_G(str, c);
            formG[i].push_back(node);
            if ((w == '\n') || this->in.eof()) formV.push_back(&formG[i++]);
        }
    }
}

void files::readIn1(FormV& formV, FormG* formG) {
    char w;
    int i = 0;
    this->in1.unsetf(std::ios::skipws);
    if (this->in1.eof() == 0) {
        while (!this->in1.eof()) {
            int c = 10;
            char str[10];
            for (int j = 0; j < 10; j++) {
                this->in1 >> w;
                if ((this->in1.eof())||(w == '\n')) {
                    c = j;
                    break;
                }
                str[j] = w;
            }
            El_G *node = new El_G(str, c);
            if (c > 0) formG[i].push_back(node);
            if ((w == '\n') || this->in1.eof())
                formV.push_back(&formG[i++]);
        }
    }
}

void files::result() {
    if (in.is_open()) {

        FormV lst, lst1;
        auto* form = new FormG[1000000];
        auto* form1 = new FormG[1000000];

        this->readIn(lst, form);
        this->readIn1(lst1, form1);

        if (out.is_open()) {

            this->out << "Панина Анастасия \n2309 \nИндивидуальное задание №4 \n\nБыл считан текст 1: \n\n";

            for (El_V* node = lst.getHead(); node != nullptr; node = node->getNext()){
                for (El_G* n = node->formG->head; n != nullptr; n = n->nextItem) {
                    int c = n->item.length;
                    for (int j = 0; j < c; j++) this->out << n->item.data[j];
                    this->out << "->";
                    if (n->getNextItem() == nullptr) this->out << "NULL";
                } this->out << "\n\\|/\n";
            }
            this->out << "NULL \n";

            this->out << "\nИ обработан:\n\n";

            lst.processing();

            for (El_V* node = lst.getHead(); node != nullptr; node = node->getNext()){
                for (El_G* n = node->formG->head; n != nullptr; n = n->nextItem) {
                    int c = n->item.length;
                    for (int j = 0; j < c; j++) this->out << n->item.data[j];
                    this->out << "->";
                    if (n->getNextItem() == nullptr) this->out << "NULL";
                } this->out << "\n\\|/\n";
            }
            this->out << "NULL \n";

            this->out << "\nБыл считан текст 2:\n\n";

            for (El_V* node = lst1.getHead(); node != nullptr; node = node->getNext()){
                if (node->formG->head == nullptr) this->out << "->NULL";
                for (El_G* n = node->formG->head; n != nullptr; n = n->nextItem) {
                    int c = n->item.length;
                    for (int j = 0; j < c; j++) this->out << n->item.data[j];
                    this->out << "->";
                    if (n->getNextItem() == nullptr) this->out << "NULL";
                } this->out << "\n\\|/\n";
            }
            this->out << "NULL \n";

            this->out << "\nИ обработан:\n\n";

            lst1.processing();

            for (El_V* node = lst1.getHead(); node != nullptr; node = node->getNext()){
                if (node->formG->head == nullptr) this->out << "->NULL";
                for (El_G* n = node->formG->head; n != nullptr; n = n->nextItem) {
                    int c = n->item.length;
                    for (int j = 0; j < c; j++) this->out << n->item.data[j];
                    this->out << "->";
                    if (n->getNextItem() == nullptr) this->out << "NULL";
                } this->out << "\n\\|/\n";
            }
            this->out << "NULL \n";

            this->out << "\nПолучился текст:\n";

            FormV finalList;

            for (El_V* node = lst1.getHead(); node != nullptr; node = node->getNext()) finalList.push_back(node->formG);
            for (El_V* node = lst.getHead(); node != nullptr; node = node->getNext()) finalList.push_back(node->formG);

            finalList.processing();

            for (El_V* node = finalList.getHead(); node != nullptr; node = node->getNext()){
                if (node->formG->head == nullptr) this->out << "->NULL";
                for (El_G* n = node->formG->head; n != nullptr; n = n->nextItem) {
                    int c = n->item.length;
                    for (int j = 0; j < c; j++) this->out << n->item.data[j];
                    this->out << "->";
                    if (n->getNextItem() == nullptr) this->out << "NULL";
                } this->out << "\n\\|/\n";
            }
            this->out << "NULL \n";

            delete[] form;
            delete[] form1;
        }
    }
    this->out << "Программа завершила свою работу";
}