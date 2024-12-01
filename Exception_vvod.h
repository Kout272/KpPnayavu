#pragma once
#include "ExceptionBase.h"
class Exception_vvod : public ExceptionBase
{
public:
	Exception_vvod(string Message);
	~Exception_vvod();
	string What() override;
};