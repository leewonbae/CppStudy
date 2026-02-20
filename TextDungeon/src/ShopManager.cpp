#include "ShopManager.h"

#include "UserInterfaceManager.h"
#include "GameException.h"

ShopManager::ShopManager(UserInterfaceManager* userInterfaceManager)
	:_ptrUserInterfaceManager(userInterfaceManager),
	_ptrPlayer(nullptr)
{
	_shopMenuList = std::vector<std::string>({ "아이템 구매","아이템 판매","뒤로" }),
	_buyMenuList = std::vector<std::string>({ "검", "방패", "포션", "뒤로"}),
	
	_ptrUserInterfaceManager->PrintText("ShopManager 생성자");
}

ShopManager::~ShopManager()
{
	_ptrUserInterfaceManager->PrintText("ShopManager 소멸자");
}

void ShopManager::SetPlayer(Player* player)
{
	_ptrPlayer = player;
}

void ShopManager::ShowShopMenu() const
{
	while (true)
	{
		auto shopMenuInput = _ptrUserInterfaceManager->PrintMenuAndGetUserInput(_shopMenuList);
		if (shopMenuInput == _shopMenuList.size())
		{
			return;
		}

		switch (shopMenuInput)
		{
		case 1:
			ShowBuyMenu();
			break;
		case 2:
			_ptrUserInterfaceManager->PrintText("아이템 판매 선택");
			break;
		default:
			break;
		}
		_ptrUserInterfaceManager->WaitForUserInput("계속하려면 아무 키나 누르세요.");
	}
}

void ShopManager::ShowBuyMenu() const
{
	_ptrUserInterfaceManager->PrintText("아이템 구매 선택");
	auto buyInput = _ptrUserInterfaceManager->PrintMenuAndGetUserInput(_buyMenuList);

	if(buyInput == _buyMenuList.size())
	{
		return;
	}

	switch (buyInput)
	{
	case 1:
		_ptrUserInterfaceManager->PrintText("검 구매 선택");
		break;
	case 2:
		_ptrUserInterfaceManager->PrintText("방패 구매 선택");
		break;
	case 3:
		_ptrUserInterfaceManager->PrintText("포션 구매 선택");
		break;
	default:
		throw GameException(E_EXCEPTION_TYPE::INVALID_SHOP_MENU_INPUT, "INVALID_SHOP_MENU_INPUT");
	}
}

