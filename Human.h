#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Human
{
private:
    string Name;
    string Surname;
    int quantity;
public:
    Human();
    Human(Human& other);
    Human(string& Name, string& Surname);
    ~Human();
    void displayInfo();
    void setNAME(string Name);
    void setSURNAME(string Surname);
    string getNAME();
    string getSURNAME();
    friend istream& operator>>(istream& in, Human& obj);
    friend ostream& operator<<(ostream& out, const Human& obj);
};