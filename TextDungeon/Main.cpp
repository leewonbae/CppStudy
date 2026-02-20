#include "GameManager.h"
#include "GameException.h"

#include <iostream>
int main()
{
    GameManager gameManager("TextDungeon");

    try
    {
        gameManager.ShowMainMenu();
    }
	catch (const GameException& e)
    {
		std::cerr << "게임 예외 발생: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "일반 예외 발생: " << e.what() << std::endl;
    }
}