#include "UserInterfaceManager.h"

UserInterfaceManager::UserInterfaceManager()
{
	PrintText("UserInterfaceManager 생성자 호출");
}

UserInterfaceManager::~UserInterfaceManager()
{
	PrintText("UserInterfaceManager 소멸자 호출");
}

void UserInterfaceManager::PrintText(const std::string& text) const
{
	std::cout << text << std::endl;
}

int32_t UserInterfaceManager::PrintMenuAndGetUserInput(const std::vector<std::string>& menuList) const
{
	int32_t num = 1;
	
	std::system("cls");

	for(const auto& menu : menuList) {
		std::cout << num <<" 번 : " << menu << std::endl;
		
		num++;
	}

	int32_t input;

	std::cin >> input;

	return input;
}

int32_t UserInterfaceManager::GetUserInputOnlyNumber()
{
	int32_t input;
	
	while (!(std::cin >> input)) { // 1. 숫자가 제대로 입력될 때까지 반복
		std::cin.clear();           // 2. 에러 플래그 초기화
		std::cin.ignore(2147483647, '\n'); // 3. 입력 버퍼에 남아있는 찌꺼기(문자열 등) 제거

		PrintText("잘못된 입력입니다. 숫자를 입력해주세요: ");
	}
	
	return input;
}

std::string UserInterfaceManager::GetAskAndInputString(const std::string& text) const
{
	std::cout << text;

	std::string input;
	
	std::cin >> input;

	return input;
}

 

void UserInterfaceManager::WaitForUserInput(const std::string& text) const
{
	std::cout << text << std::endl;

	// 입력 버퍼를 비우고 입력을 기다림
	std::cin.clear();
	std::cin.ignore(2147483647, '\n');
	std::string dummy;
	std::getline(std::cin, dummy);
}

void UserInterfaceManager::ShowMainMenu()
{
	std::system("cls");
	std::cout << "1. Start Game" << std::endl;
	std::cout << "2. Exit Game" << std::endl;
}
