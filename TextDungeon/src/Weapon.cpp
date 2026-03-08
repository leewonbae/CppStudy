#include "Weapon.h"
Weapon::Weapon()
{
	std::cout << "Weapon 기본 생성자 " << std::endl;
}

Weapon::Weapon(std::string name, int32_t damage) : Item(name,E_ITEM_TYPE::WEAPON)
{ 
	_damage = damage;

	std::cout << "Weapon 오버라이딩 생성자"<< std::endl;
}

Weapon::~Weapon()
{
	std::cout << "무기 메모리 삭제 " << std::endl;
}

std::string Weapon::GetDetailInfo() const 
{
	return " 상세 정보 -> 데미지 : [" + std::to_string(_damage) + "]" ;
}
