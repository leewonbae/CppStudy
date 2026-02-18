#pragma once

#include <iostream>
#include <string>

class UserInterfaceManager
{
	public:
	UserInterfaceManager();
	~UserInterfaceManager();
	
	void PrintText(const std::string& text) const;



	void WaitForUserInput(const std::string& text) const;
	int32_t GetUserInputOnlyNumber();
	std::string GetAskAndInputString(const std::string& text) const;
	void ShowMainMenu();
};

