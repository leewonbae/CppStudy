#include "GameManager.h"
#include "UserInterfaceManager.h"
#include "Player.h"

GameManager::GameManager(const std::string& gameName) 
	: _gameName(gameName),
	_ptrPlayer(nullptr)
{
}

GameManager::~GameManager()
{
}

void GameManager::InitManagers()
{
	_ptrUserInterfaceManager = std::make_unique<UserInterfaceManager>();
}

void GameManager::StartGame()
{
	bool isRunning = true;
	while (isRunning)
	{
		
		_ptrUserInterfaceManager.get()->ShowMainMenu();
		
		int32_t input = _ptrUserInterfaceManager.get()->GetUserInputOnlyNumber();
		
		E_GAME_MANAGER_INPUT_STATE choice = static_cast<E_GAME_MANAGER_INPUT_STATE>(input);
		
		switch (choice)
		{
			case E_GAME_MANAGER_INPUT_STATE::START_GAME:
				_ptrUserInterfaceManager.get()->PrintText("게임을 시작합니다.");
				if(_ptrPlayer == nullptr)
				{
					CreatePlayer();
				}
				break;

			case E_GAME_MANAGER_INPUT_STATE::EXIT_GAME:
				isRunning = false;
				break;

			default:
				_ptrUserInterfaceManager.get()->WaitForUserInput("잘못된 입력입니다. 다시 입력해주세요.");
				break;
		}

		if (!isRunning)
		{
			_ptrUserInterfaceManager.get()->PrintText("게임을 종료합니다.");
			break;
		}
	}
}

void GameManager::CreatePlayer()
{
	std::string playerName = _ptrUserInterfaceManager.get()->GetAskAndInputString("플레이어 이름을 입력하세요: ");

	_ptrPlayer = std::make_unique<Player>(playerName);
}
