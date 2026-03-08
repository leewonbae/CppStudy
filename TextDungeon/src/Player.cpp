#include "Player.h"

Player::Player() {
	std::cout << "Player 积己磊"<< std::endl;

	Init();
}

Player::Player(std::string name)
	: _name(name)
{
	std::cout << "Player 积己磊"<< std::endl;

	Init();
}

Player::~Player()
{
	std::cout << "Player 家戈磊" << std::endl;
}

void Player::ShowStatus() const
{
	std::cout << "name :" << _name << std::endl;
	std::cout << "HealthPoint :" << _healthPoint << std::endl;

	ShowInventory();
}

void Player::AddItemInInventory(std::unique_ptr<Item> item)
{
	_inventory.push_back(std::move(item));
}

void Player::ShowInventory() const
{
	std::cout << "item 格废 " << std::endl;

	int32_t index = 0;
	for (const auto& item : _inventory)
	{
		std::cout <<"[" << index <<"] Name [ " << item->GetName() << " ] " <<item->GetDetailInfo() << std::endl;
		
		index++;
	}
}


void Player::Init()
{
	_healthPoint = 100;
	_inventory.reserve(100);
}
