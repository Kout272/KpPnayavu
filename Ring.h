#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node* prev;
    Node* next;
    Node(T& dat) :prev(nullptr), next(nullptr), data(dat) {}
    Node() :prev(nullptr), next(nullptr), data() {}
};

template <typename T>
class Ring
{
    Node<T>* begin;
    Node<T>* current;
public:
    Ring();
    Ring(const Ring& other);
    void Push(T& data);
    void Display();
    void RemoveCurrent();
    bool Empty();
    void FindMin();
    void FindMax();
    void ShowCurrent();
    bool Search();
    void RemoveAll();
    ~Ring();
};

#include "Ring.cpp"