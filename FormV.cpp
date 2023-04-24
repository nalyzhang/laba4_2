#include "FormV.h"

void FormV::setTail(El_V *t) {
    this->tail = t;
}

El_V *FormV::getTail(){
    return this->tail;
}

El_V *FormV::getHead() {
    return this->head;
}

void FormV::setHead(El_V *h) {
    this->head = h;
}

void FormV::pop_front() { //удаление с начала
    if (this->head == nullptr) return;
    if (this->head == this->tail) {
        free(this->tail);
        this->head = nullptr;
        this->tail = nullptr;
        return;
    }
    El_V* node = this->getHead();
    this->head = node->getNext();
    free(node);
}

void FormV::push_back(FormG *form) { //добавление в конец
    El_V* node = new El_V(form);
    if (this->getHead() == nullptr) this->setHead(node);
    if (this->getTail() != nullptr) this->getTail()->setNext(node);
    this->setTail(node);
}

bool isOneBiggerThanTwo(El_V* one, El_V* two) {
    int lOne = 0, lTwo = 0;
    for (El_G* n = one->formG->head; n != nullptr; n = n->nextItem) {
        for (int j = 0; j < n->item.length; j++) lOne++;
    }

    for (El_G* n = two->formG->head; n != nullptr; n = n->nextItem) {
        for (int j = 0; j < n->item.length; j++) lTwo++;
    }

    int c = (lOne > lTwo) ? lTwo : lOne;

    El_G* nodeOne = one->formG->head;
    El_G* nodeTwo = two->formG->head;

    int d = c;

    for (int i = 0; i < c; c++) {
        for (int j = 0; (d >= 10) ? j < 10 : j < d; j++) {
            int nOne = nodeOne->item.data[j] - ' ';
            int nTwo = nodeTwo->item.data[j] - ' ';
            if (nOne > nTwo) return true;
            if (nOne < nTwo) return false;
            if (nOne == nTwo) continue;
        }
        d -= 10;
    }
    if (lOne > lTwo) return true;
    else return false;
}

void FormV::processing() {
    for(El_V* node = this->getHead(); node != nullptr; node = node->next) {
        for(El_V* node1 = this->getHead(); node1->next != nullptr; node1 = node1->next) {
            if (isOneBiggerThanTwo(node1, node1->next)) {
                FormG *n = node1->formG;
                node1->formG = node1->next->formG;
                node1->next->formG = n;
            }
        }
    }
}