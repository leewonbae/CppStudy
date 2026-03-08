#pragma once
 
#include<string>

#include "Item.h"

class Armor : public Item
{
public:

	Armor();
	Armor(std::string name, int32_t defenceValue);
	~Armor() override;
	// Item을(를) 통해 상속됨
	std::string GetDetailInfo() const override;
private:
	int32_t _defenceValue;
};

