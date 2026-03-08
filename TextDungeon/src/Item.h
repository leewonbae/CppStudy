#pragma once

#include<string>
#include<iostream>
#include "Commons.h"
class Item
{
public:
	Item();
	Item(std::string name, E_ITEM_TYPE itemType);

	std::string GetName() const;
	std::string GetItemType() const;
	virtual std::string GetDetailInfo() const = 0; 
	virtual ~Item();

private:
	std::string _name;
	E_ITEM_TYPE _itemType;
	
	std::string ConvertItemTypeToEnum(E_ITEM_TYPE itemType) const;
};

