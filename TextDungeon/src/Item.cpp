#include "Item.h"

Item::Item()
{
	std::cout << "item 기본 생성자" << std::endl;
}

Item::Item(std::string name, E_ITEM_SLOT itemSlot)
{
	_name = name;
	_itemSlot = itemSlot;
	std::cout << "item 오버라이딩 생성자"<< std::endl;
}

std::string Item::GetName() const
{
	return _name;
}

E_ITEM_SLOT Item::GetItemSlot() const
{
	return _itemSlot;
}

Item::~Item()
{
	std::cout << "item 소멸 " << std::endl;
}

