#include "GameManager.h"
#include "PlayerManager.h"
#include "UserInterfaceManager.h"
#include "ShopManager.h"

GameManager::GameManager(const std::string& gameName)
	: _gameName(gameName),
	_ptrPlayer(nullptr)
{
	_ptrUserInterfaceManager = std::make_unique<UserInterfaceManager>();
	_ptrShopManager = std::make_unique<ShopManager>(_ptrUserInterfaceManager.get());
	_ptrPlayerManager = std::make_unique<PlayerManager>(_ptrUserInterfaceManager.get());
}

GameManager::~GameManager()
{
}

void GameManager::ShowMainMenu()
{
	bool isRunning = true;
	while (isRunning)
	{
		_ptrUserInterfaceManager.get()->ShowMainMenu();

		int32_t mainMenuInput = _ptrUserInterfaceManager.get()->GetUserInputOnlyNumber();

		E_MAIN_MENU_INPUT_TYPE inputState = static_cast<E_MAIN_MENU_INPUT_TYPE>(mainMenuInput);

		if (inputState == E_MAIN_MENU_INPUT_TYPE::EXIT_GAME) {
			return;
		}

		if (inputState == E_MAIN_MENU_INPUT_TYPE::START_GAME) 
		{
			if (_ptrPlayer == nullptr)
			{
				_ptrPlayer = _ptrPlayerManager.get()->CreatePlayer();
				_ptrShopManager.get()->SetPlayer(_ptrPlayer);
			}

			ShowInGameMenu(); // 인게임 전용 루프로 진입
		}
		else
		{
			_ptrUserInterfaceManager.get()->WaitForUserInput("잘못된 입력입니다. 다시 입력해주세요.");
		}
	}
}

void GameManager::ShowInGameMenu()
{
	while (true)
	{
		auto menuList = std::vector<std::string>{ "플레이어 정보","상점 이동","던전 이동","메인 메뉴 이동" };

		auto inGameInput = _ptrUserInterfaceManager.get()->PrintMenuAndGetUserInput(menuList);
		if (inGameInput == menuList.size())
		{
			return;
		}

		switch (inGameInput)
		{
		case 1: // 플레이어
			_ptrPlayerManager.get()->ShowPlayerMenu();
			break;

		case 2: //상점 이동
			_ptrShopManager.get()->ShowShopMenu();
			break;

		case 3: //던전 이동
			_ptrUserInterfaceManager.get()->PrintText("게임을 시작합니다.");
			break;

		default:
			_ptrUserInterfaceManager.get()->WaitForUserInput("잘못된 입력입니다. 다시 입력해주세요.");
			break;
		}
	}
}