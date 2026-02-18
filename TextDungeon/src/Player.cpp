#include "Player.h"
#include "Monster.h"
#include "Weapon.h"

Player::Player() {
	std::cout << "Player 생성자"<< std::endl;

	Init();
}

Player::Player(std::string name)
	: _name(name)
{
	std::cout << "Player 생성자"<< std::endl;

	Init();
}

Player::~Player()
{
	std::cout << "Player 소멸자" << std::endl;
}

void Player::EquipItem(std::unique_ptr<Item> ptrItem)
{
	std::cout << "아이템 장착" << ptrItem->GetName() << std::endl;

	auto slot = ptrItem->GetItemSlot();
	_itemSlotMap[slot] = std::move(ptrItem);

	if (slot == E_ITEM_SLOT::LEFT_HAND)
	{
		_currentWeapon = dynamic_cast<Weapon*>(_itemSlotMap[E_ITEM_SLOT::LEFT_HAND].get());
	}
}

void Player::SetTargetMonster(Monster* targetMonster)
{
	_ptrTargetMonster = targetMonster;
	std::cout << "TargetMonster Name :" << _ptrTargetMonster->GetName() << std::endl;
}

void Player::AttackMonster()
{
	if (_ptrTargetMonster != nullptr)
	{
		std::cout << "몬스터 공격 :" << _ptrTargetMonster->GetName() << std::endl;

		int damage;
		if (_currentWeapon != nullptr)
		{
			std::cout << "무기 장착 공격 :" << _currentWeapon->GetName() << std::endl;
			damage = _currentWeapon->GetDamage();
		}
		else
		{
			std::cout << "맨손 공격" << std::endl;
			damage = 1;
		}

		auto remainDamage = _ptrTargetMonster->AddDamage(damage);

		std::cout << _ptrTargetMonster->GetName() << " 남은 체력 :" << remainDamage << std::endl;
	}
	else
	{
		std::cout << "타겟 몬스터가 없습니다." << std::endl;
	}
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
