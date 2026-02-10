#include "Monster.h"
#include "Player.h"

Monster::Monster(const std::string& name)
{
	_name = name;
	std::cout << "Monster 생성자 " << _name << std::endl;
}

Monster::~Monster()
{
	std::cout << "Monster 소멸자 " << _name << std::endl;
}

int Monster::AddDamage(int32_t damage)
{
	_healthPoint -= damage;
	std::cout << _ptrTargetPlayer->GetName() << " 이(가) " << damage << " 공격 했습니다." << std::endl;

	return _healthPoint;
}

void Monster::SetTaretPlayer(Player* targetPlayer)
{
	_ptrTargetPlayer = targetPlayer;
	std::cout << "targetPlayer Name" << _ptrTargetPlayer->GetName() << std::endl;
}


