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

El_G* FormG::getAt(int k) { //доступ к элементу
    if (k < 0) return nullptr;
    El_G* node = this->getHead();
    int n = 0;
    while (node && n != k && node->getNextItem()) {
        node = node->getNextItem();
        n++;
    }
    return (n == k) ? node : nullptr;
}

//вствка элемента
void FormG::insert(int k, StrL text){ //индекс k - индекс элемента, после которого нужно вставить объект
    El_G* left = getAt(k);
    if (left == nullptr) return;
    El_G* right = left->getNextItem();
    El_G* node = new El_G(text.getData(), text.getLength());
    left->setNextItem(node);
    node->setNextItem(right);
    if (right == nullptr) this->setTail(node);
}

//удаление промежуточного элемента
void FormG::earse(int k) {
    if (k < 0) return;
    if (k == 0) {
        pop_front();
        return;
    }
    El_G* left = this->getAt(k-1);
    El_G* node = left->getNextItem();
    if (node == nullptr) return;
    El_G* right = node->getNextItem();
    left->setNextItem(right);
    if (node == this->getTail()) this->setTail(left);
    free(node);
}
