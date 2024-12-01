#include "ExceptionBase.h"

ExceptionBase::ExceptionBase(string Message)
{
	state = Message;
}

ExceptionBase::~ExceptionBase() {}

string ExceptionBase::What()
{
	return state;
}