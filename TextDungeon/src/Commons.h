#pragma once

namespace Config {
	constexpr int ITEM_SLOT_MAX_COUNT = 6;
}

enum class E_ITEM_SLOT{
	NONE,
	LEFT_HAND,
	RIGHT_HAND,
	CHEST,
	HEAD,
	LEG,
	BACK
};