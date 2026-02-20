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

	void SetPlayer(Player* player);
	void ShowShopMenu() const;

private:
	void ShowBuyMenu() const;

	Player* _ptrPlayer;
	UserInterfaceManager* _ptrUserInterfaceManager;
	std::vector<std::string> _shopMenuList;
	std::vector<std::string> _buyMenuList;
	 
};