#pragma once
#include"Ring.h"
class ExceptionBase
{
protected:
	string state;
public:
	ExceptionBase(string Message);
	~ExceptionBase();
	virtual string What();
};