#pragma once

#include <string>
#include <memory>
#include <vector>

class Player;
class UserInterfaceManager;

class PlayerManager
{
public:
PlayerManager(UserInterfaceManager* userinterfaceManagaer);
~PlayerManager();

void ShowPlayerMenu() const;

Player* CreatePlayer();
	
private:
	UserInterfaceManager* _ptrUserInterfaceManager;
	std::vector<std::string> _playerMenuList;
	std::unique_ptr<Player> _ptrPlayer;

};

