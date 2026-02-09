#include "Player.h"

Player::Player() {
	std::cout << "name : " << _name << std::endl;

	Init();
}

Player::Player(std::string name)
{
	_name = name;
	std::cout << "name :" << _name << std::endl;

	Init();
}

Player::~Player()
{
	std::cout << "¼Ò¸êÀÚ : " << _name <<std::endl;

}

void Player::ShowStatus()
{
	std::cout << "name :" << _name << std::endl;
	std::cout << "HealthPoint :" << _healthPoint << std::endl;
}

void Player::Init()
{
	_healthPoint = 100;
}
