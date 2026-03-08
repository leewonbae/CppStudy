#include "Armor.h"
Armor::Armor()
{
	std::cout << "Armor 기본 생성자 " << std::endl;
}

Armor::Armor(std::string name, int32_t defenceValue) : Item(name, E_ITEM_TYPE::ARMOR)
{
	_defenceValue = defenceValue;
	std::cout << "Armor 오버라이딩 생성자" << std::endl;
}

Armor::~Armor()
{
	std::cout << "Armor 메모리 삭제 " << std::endl;
}

std::string Armor::GetDetailInfo() const
{
	return " 상세 정보 -> 방어 지수 : [" + std::to_string(_defenceValue) + "]";
}
