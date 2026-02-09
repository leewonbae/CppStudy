#pragma once
#include <string>
#include <iostream>
#include <unordered_map>
#include <memory>
#include "Item.h"
#include "Commons.h"

class Player
{
	public:
		Player();
		Player(std::string name);
		~Player();

		void EquipItem(std::unique_ptr<Item> ptrItem);

		void ShowStatus() const;
	private:
		std::string _name;
		int32_t _healthPoint;

		std::unordered_map<E_ITEM_SLOT, std::unique_ptr<Item>> _itemSlotMap;
		void Init();
};