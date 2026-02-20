#include "GameException.h"

GameException::GameException(const E_EXCEPTION_TYPE exceptionType,const std::string& message )
	: _message(message), _exceptionType(exceptionType)
{
}

const char* GameException::what() const noexcept
{
	return _message.c_str();
}
