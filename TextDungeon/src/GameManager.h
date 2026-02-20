#pragma once

#include <string>
#include <memory>

class UserInterfaceManager;
class ShopManager;
class PlayerManager;
class Player;

enum class E_MAIN_MENU_INPUT_TYPE {
	START_GAME = 1,
	EXIT_GAME = 2
};

class GameManager
{
public:
	GameManager(const std::string& gameName);
	~GameManager();

	void ShowMainMenu();

private:
	void ShowInGameMenu();

	std::unique_ptr<UserInterfaceManager> _ptrUserInterfaceManager;
	std::unique_ptr<ShopManager> _ptrShopManager;
	std::unique_ptr<PlayerManager> _ptrPlayerManager;
	Player*_ptrPlayer;

	std::string _gameName;
};

