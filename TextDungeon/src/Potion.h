#pragma once
#include <string>

#include "Item.h"

class Potion : public Item
{
public:
	Potion();
	Potion(std::string name, int32_t recoveryValue);
	~Potion() override;
	// Item을(를) 통해 상속됨
	std::string GetDetailInfo() const override;

private:
	int32_t _recoveryValue;
};

