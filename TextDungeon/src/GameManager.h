#pragma once

#include <string>
#include <memory>

class UserInterfaceManager;
class Player;

enum class E_GAME_MANAGER_INPUT_STATE {
	START_GAME = 1,
	EXIT_GAME = 2
};

class GameManager
{
public:
	GameManager(const std::string& gameName);
	~GameManager();

	void InitManagers();
	void StartGame();

private:
	void CreatePlayer();

	std::unique_ptr<UserInterfaceManager> _ptrUserInterfaceManager;

	std::unique_ptr<Player> _ptrPlayer;

	std::string _gameName;
};

