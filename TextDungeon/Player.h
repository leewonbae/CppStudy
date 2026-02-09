#pragma once
#include <string>
#include <iostream>

class Player
{
	public:
		Player();
		Player(std::string name);
		~Player();
		void ShowStatus();
	private:
		std::string _name;
		int32_t _healthPoint;

		void Init();
};