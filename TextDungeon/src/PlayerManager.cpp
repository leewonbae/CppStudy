#include "PlayerManager.h"
#include "UserInterfaceManager.h"
#include "Player.h"
#include "GameException.h"

PlayerManager::PlayerManager(UserInterfaceManager* userinterfaceManagaer)
	:_ptrUserInterfaceManager(userinterfaceManagaer),
	_playerMenuList({ "플레이어 정보 확인","뒤로" })

{
	_ptrUserInterfaceManager->PrintText("PlayerManager 생성자");
}

PlayerManager::~PlayerManager()
{
	_ptrUserInterfaceManager->PrintText("PlayerManager 소멸자");
}

void PlayerManager::ShowPlayerMenu() const
{
	while (true)
	{
		auto playerMenuInput = _ptrUserInterfaceManager->PrintMenuAndGetUserInput(_playerMenuList);
		if (playerMenuInput == _playerMenuList.size())
		{
			return;
		}

		switch (playerMenuInput)
		{
		case 1:
			_ptrPlayer->ShowStatus();
			break;
		default:
			throw GameException(E_EXCEPTION_TYPE::INVALID_PLAYER_MENU_INPUT,"잘못된 입력입니다. 다시 입력해주세요.");
		}

		_ptrUserInterfaceManager->WaitForUserInput("계속하려면 아무 키나 누르세요.");
	}
}

Player* PlayerManager::CreatePlayer()
{
	auto playerName =_ptrUserInterfaceManager->GetAskAndInputString("플레이어 이름을 입력하세요: ");

	_ptrPlayer = std::make_unique<Player>(playerName);

	return _ptrPlayer.get();
}


