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
        delete this->tail;
        this->head = this->tail = nullptr;
        return;
    }
    El_V* node = this->getHead();
    this->head = node->getNext();
    delete node;
}

void FormV::push_back(FormG *form) { //добавление в конец
    El_V* node = new El_V(form);
    if (this->getHead() == nullptr) this->setHead(node);
    if (this->getTail() != nullptr) this->getTail()->setNext(node);
    this->setTail(node);
}

El_V* FormV::getAt(int k) { //доступ к элементу
    if (k < 0) return nullptr;
    El_V* node = this->getHead();
    int n = 0;
    while (node && n != k && node->getNext()) {
        node = node->getNext();
        n++;
    }
    return (n == k) ? node : nullptr;
}

//вствка элемента
void FormV::insert(int k, FormG* text){ //индекс k - индекс элемента, после которого нужно вставить объект
    El_V* left = getAt(k);
    if (left == nullptr) return;
    El_V* right = left->getNext();
    El_V* node = new El_V(text);
    left->setNext(node);
    node->setNext(right);
    if (right == nullptr) this->setTail(node);
}

//удаление промежуточного элемента
void FormV::earse(int k) {
    if (k < 0) return;
    if (k == 0) {
        pop_front();
        return;
    }
    El_V* left = this->getAt(k-1);
    El_V* node = left->getNext();
    if (node == nullptr) return;
    El_V* right = node->getNext();
    left->setNext(right);
    if (node == this->getTail()) this->setTail(left);
    delete node;
}