#include "FormG.h"

void FormG::setTail(El_G *t) {
    this->tail = t;
}

El_G *FormG::getTail(){
    return this->tail;
}

El_G *FormG::getHead() {
    return this->head;
}

void FormG::setHead(El_G *h) {
    this->head = h;
}

void FormG::pop_front() { //удаление с начала
    if (this->head == nullptr) return;
    if (this->head == this->tail) {
        free(this->tail);
        this->head = nullptr;
        this->tail = nullptr;
        return;
    }
    El_G* node = this->getHead();
    this->head = node->getNextItem();
    free(node);
}

void FormG::push_back(El_G* node) { //добавление в конец
    if (this->getHead() == nullptr) this->setHead(node);
    if (this->getTail() != nullptr) this->getTail()->setNextItem(node);
    this->setTail(node);
}