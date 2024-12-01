#pragma once 
#include <iostream>
#include "Exception_vvod.h"
#include "Ring.h"
using namespace std;

int GetInt(int min, int max);
string GetDate();
string GetName();
string GetTitle();
int GetInt(int min, int max, istream& in);
string GetDate(istream& in);
string GetName(istream& in);
string GetTitle(istream& in);