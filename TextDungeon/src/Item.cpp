#include "Item.h"

Item::Item()
{
	std::cout << "item 기본 생성자" << std::endl;
}

Item::Item(std::string name, E_ITEM_TYPE itemType) :
_name(name), _itemType(itemType)
{
	std::cout << "item 오버라이딩 생성자"<< std::endl;
}

std::string Item::GetName() const
{
	return _name;
}

std::string Item::GetItemType() const
{
	return  ConvertItemTypeToEnum(_itemType);
}

Item::~Item()
{
	std::cout << "item 소멸 " << std::endl;
}

std::string Item::ConvertItemTypeToEnum(E_ITEM_TYPE itemType) const
{
	switch (itemType)
	{
	case E_ITEM_TYPE::WEAPON:
		return "WEAPON";
	case E_ITEM_TYPE::ARMOR:
		return "ARMOR";
	case E_ITEM_TYPE::POTION:
		return "POTION";
	case E_ITEM_TYPE::ETC:
		return "ETC";
	}
}

