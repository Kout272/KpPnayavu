#include "Exception_vvod.h"

Exception_vvod::Exception_vvod(string Message) : ExceptionBase(Message) {}

Exception_vvod::~Exception_vvod() {}

string Exception_vvod::What()
{
	return state;
}