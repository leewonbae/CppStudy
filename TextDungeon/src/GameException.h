#pragma once
#include <exception>
#include <string>

#include "Commons.h"

class GameException : public std::exception
{
public:
	GameException(const E_EXCEPTION_TYPE exceptionType, const std::string& message);
	virtual ~GameException() noexcept override = default;
	virtual const char* what() const noexcept override;

private:
	std::string _message;
	E_EXCEPTION_TYPE _exceptionType;
};

