#pragma once

#include<string>
#include<iostream>
#include "Commons.h"
class Item
{
public:
	Item();
	Item(std::string name, E_ITEM_SLOT itemSlot);

	std::string GetName() const;
	E_ITEM_SLOT GetItemSlot() const;
	virtual ~Item();
private:
	std::string _name;
	E_ITEM_SLOT _itemSlot = E_ITEM_SLOT::NONE;
};

