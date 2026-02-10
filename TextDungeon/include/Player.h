#pragma once
#include <string>
#include <iostream>
#include <unordered_map>
#include <memory>
#include "Item.h"
#include "Commons.h"

class Monster;
class Weapon;
class Player
{
public:
	Player();
	Player(std::string name);
	~Player();

	void EquipItem(std::unique_ptr<Item> ptrItem);
	void SetTargetMonster(Monster* targetMonster);
	void AttackMonster();
	void ShowStatus() const;
	std::string GetName() const { return _name; }

private:
	std::string _name;
	int32_t _healthPoint;
	Monster* _ptrTargetMonster;
	std::unordered_map<E_ITEM_SLOT, std::unique_ptr<Item>> _itemSlotMap;
	Weapon* _currentWeapon;
	void Init();
};