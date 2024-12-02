#pragma once
#include "Ring.h"
#include "Errors.h"

class Interface
{
private:
    int choise;
    int type;
    int cz;
public:
   // void start();
    Interface() :choise(0), type(0), cz(0) {}
    template<typename T>
    void OperatingRing(Ring<T>& list);
};
#include"Interface.cpp"