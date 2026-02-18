#include "GameManager.h"

int main()
{
    GameManager gameManager("TextDungeon");

	gameManager.InitManagers();
    gameManager.StartGame();
}