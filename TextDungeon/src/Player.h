#pragma once
#include <string>
#include <iostream>
#include <unordered_map>
#include <memory>
#include "Item.h"
#include "Commons.h"

class Monster;
class Item;

class Player
{
public:
	Player();
	Player(std::string name);
	~Player();

	void ShowStatus() const;
	void AddItemInInventory(std::unique_ptr<Item> item);
	void ShowInventory() const;
	std::string GetName() const { return _name; }

private:
	std::string _name;
	int32_t _healthPoint;
	std::vector<std::unique_ptr<Item>> _inventory;

	void Init();
};