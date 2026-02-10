#pragma once
#include<iostream>
#include<string>
#include<memory>
class Player;

class Monster
{
public :
	Monster(const std::string& name);
	~Monster();
	
	std::string GetName() const { return _name; }
	int AddDamage(int32_t damage);
	void SetTaretPlayer(Player* targetPlayer);
private:
	int32_t _healthPoint = 100;
	std::string _name;
	Player* _ptrTargetPlayer;
};

