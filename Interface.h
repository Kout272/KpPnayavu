#pragma once
#include "Ring.h"
#include "Errors.h"

class Interface
{
private:
    int choise;
    int type;
public:
    void start();
    template<typename T>
    void OperatingRing(Ring<T>& list);
};