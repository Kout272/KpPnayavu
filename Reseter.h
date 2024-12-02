#pragma once
#include <variant>
#include <string>
#include "Ring.h"
#include <iostream>
#include <stdexcept>



template<class T>
class LinkedList {
protected:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* cursor;
    size_t size; // New member variable to track the size

public:
    LinkedList() : head(nullptr), tail(nullptr), cursor(nullptr), size(0) {}
    LinkedList(T& val) : cursor(nullptr), size(1) {
        head = new Node<T>(val);
        tail = head;
    }
    ~LinkedList() { clear(); }

    void insertLeft(T &item);
    void insertRight(T& item);
    T& removeLeft();
    T& removeRight();
    void clear();
    bool isEmpty();
    void resetCursor() { cursor = head; }
    void tailCursor() { cursor = tail; }
    T& getValue();
    size_t getSize() const { return size; } // Function to return the size

    Node<T>* operator++();
    Node<T>* operator--();
    void print();
};

template<class T>
bool LinkedList<T>::isEmpty() {
    return (head == nullptr && tail == nullptr);
}

template<class T>
void LinkedList<T>::insertLeft(T& item) {
    Node<T>* newNode = new Node<T>(item);
    if (!isEmpty()) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else {
        head = tail = newNode;
    }
    size++; // Increment size
}

template<class T>
void LinkedList<T>::insertRight(T& item) {
    Node<T>* newNode = new Node<T>(item);
    if (!isEmpty()) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else {
        head = tail = newNode;
    }
    size++; // Increment size
}

template<class T>
T& LinkedList<T>::removeRight() {
    if (isEmpty()) throw std::runtime_error("List is empty");
    T val = tail->data;
    Node<T>* temp = tail;
    tail = tail->prev;
    if (tail)
        tail->next = nullptr;
    else
        head = nullptr;
    delete temp;
    size--; // Decrement size
    return val;
}

template<class T>
T& LinkedList<T>::removeLeft() {
    if (isEmpty()) throw std::runtime_error("List is empty");
    T val = head->value;
    Node<T>* temp = head;
    head = head->next;
    if (head)
        head->prev = nullptr;
    else
        tail = nullptr;
    delete temp;
    size--; // Decrement size
    return val;
}

template<class T>
void LinkedList<T>::clear() {
    Node<T>* current = head;
    while (current) {
        Node<T>* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    head = nullptr;
    tail = nullptr;
    cursor = nullptr;
    size = 0; // Reset size
}

template<class T>
T& LinkedList<T>::getValue() {
    if (cursor == nullptr) throw std::runtime_error("Cursor is null");
    return cursor->data;
}

template<class T>
Node<T>* LinkedList<T>::operator++() {
    if (cursor != nullptr) {
        if (cursor->next != nullptr) {
            cursor = cursor->next; // Переместить курсор на следующий узел, если он доступен
        }
        else {
            cursor = nullptr; // Если курсор на tail, возвращаем nullptr
        }
    }
    else {
        cursor = nullptr; // Если курсор был null, возвращаем nullptr
    }
    return cursor; // Вернуть текущее положение курсора
}

template<class T>
Node<T>* LinkedList<T>::operator--() {
    if (cursor != nullptr) {
        if (cursor->prev != nullptr) {
            cursor = cursor->prev; // Переместить курсор на предыдущий узел, если он доступен
        }
        else {
            cursor = nullptr; // Если курсор на head, возвращаем nullptr
        }
    }
    else {
        cursor = nullptr; // Если курсор был null, возвращаем nullptr
    }
    return cursor; // Вернуть текущее положение курсора
}

