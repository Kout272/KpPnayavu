#pragma once
#include "Ring.h"

template <typename T>
void Ring<T>::ShowCurrent()
{
    if (current == nullptr)
    {
            cout << "Кольцо пустое\n";
    }
    else
    {
            cout << current->data << endl;
    }
}

template<typename T>
Ring<T>::~Ring() {
    if (this->current != nullptr) {
        Node<T>* tmp = this->current;
        do {
            Node<T>* nextNode = tmp->next;
            delete tmp;
            tmp = nextNode;
        } while (tmp != this->current);
    }
}

template<typename T>
void Ring<T>::RemoveAll()
{
    if (this->current != nullptr) {
        if (this->current->next == this->current) {
            delete this->current;
            this->current = nullptr;
                cout << "Кольцо успешно очищено!" << endl;
        }
        else
        {
            Node<T>* tmp = this->current;
            do {
                Node<T>* nextNode = tmp->next;
                delete tmp;
                tmp = nextNode;
            } while (tmp != this->current);
            this->current = nullptr;
                cout << "Кольцо пусто" << endl;
        }
    }
    else
    {
            cout << "Кольцо пусто" << endl;
    }
}

template<typename T>
Ring<T>::Ring(const Ring& other)
{
    Node<T>* current = other.current;
    do
    {
        Push(current->data);
        current = current->next;
    } while (current != other.current);

}

//template<typename T>
//bool Ring<T>::Search()
//{
//    cout << "Введите фамилию, которую вы хотите найти: ";
//    string surname;
//    cin >> surname;
//    if (this->current == nullptr) return false;
//    else
//    {
//        Node<T>* tmp = this->current;
//        do {
//            if (tmp->data.Human::getSurname() == surname) return true;
//            tmp = tmp->next;
//        } while (tmp != this->current);
//        cout << endl;
//        return false;
//    }
//}

template <typename T>
void  Ring<T>::FindMax()
{
    if (this->current == nullptr)
    {
        return;
    }

    Node<T>* tmp = this->current;
    T max = tmp->data;
    do {
        if (max.Human::getAge() < tmp->data.Human::getAge())max = tmp->data;
        tmp = tmp->next;
    } while (tmp != this->current);
    max.shapka();
    cout << max;
}

template <typename T>
void  Ring<T>::FindMin()
{
    if (this->current == nullptr)
    {
        return;
    }
    Node<T>* tmp = this->current;
    T min = tmp->data;
    do {
        if (min.Human::getAge() > tmp->data.Human::getAge())min = tmp->data;
        tmp = tmp->next;
    } while (tmp != this->current);
    min.shapka();
    cout << min;
}

template <typename T>
void Ring<T>::RemoveCurrent()
{
    Node<T>* tmp = nullptr;
    if (current == nullptr)
    {
            cout << "Кольцо пустое\n";
    }
    else
    {
        if (this->current->next == this->current)
        {
            delete this->current;
            this->current = nullptr;
        }
        else
        {
            tmp = current->next;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            current = tmp;
        }
    }

}

template <typename T>
bool Ring<T>::Empty()
{
    if (current == NULL)return 1;
    else return 0;
}

template <typename T>
Ring<T>::Ring()
{
    this->begin = NULL;
    this->current = NULL;
}

template <typename T>
void Ring<T>::Push(T& data)
{
    Node<T>* tmp = new Node<T>;
    tmp->data = data;
    if (current == NULL)
    {
        tmp->next = tmp;
        tmp->prev = tmp;
        current = tmp;
        begin = current;
    }
    else
    {
        tmp->next = begin;
        tmp->prev = current;
        current->next = tmp;
        begin->prev = tmp;
        current = tmp;
    }
}

template <typename T>
void Ring<T>::Display()
{
    Node<T>* tmp = current;
    if (current == NULL)
    {
            cout << "Кольцо пустое\n";
    }
    else
    {
        do
        {
            cout << tmp->data << "\n";
            tmp = tmp->next;
        } while (tmp != current);
    }
}