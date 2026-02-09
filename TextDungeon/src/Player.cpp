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

void Player::EquipItem(std::unique_ptr<Item> ptrItem)
{
	std::cout << "¾ÆÀÌÅÛ ÀåÂø" << ptrItem->GetName() << std::endl;
	_itemSlotMap[ptrItem->GetItemSlot()] = std::move(ptrItem);
}

void Player::ShowStatus() const
{
	std::cout << "name :" << _name << std::endl;
	std::cout << "HealthPoint :" << _healthPoint << std::endl;
}


void Player::Init()
{
	_healthPoint = 100;
}
