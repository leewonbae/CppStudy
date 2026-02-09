#pragma once
#include "Item.h"
#include <string>
class Weapon : public Item
{
public :
	Weapon();
	Weapon(std::string name, int32_t damage);
	~Weapon() override;
private:
	int32_t _damage;
};

