#pragma once

#include <string>
#include <vector>

class UserInterfaceManager;
class Player;

class ShopManager
{
public:
	ShopManager(UserInterfaceManager* userInterfaceManager);
	~ShopManager();

	void ShowShopMenu(Player* player) const;

private:
	void ShowBuyMenu(Player* player) const;

	Player* _ptrPlayer;
	UserInterfaceManager* _ptrUserInterfaceManager;
	std::vector<std::string> _shopMenuList;
	std::vector<std::string> _buyMenuList;
	 
};