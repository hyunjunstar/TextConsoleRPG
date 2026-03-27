#pragma once
// #include "Player.h"
#include "Monster.h"
#include <cstdlib>

class BattleManager
{
private:
	// Constant Critical and Damage Variability for Maintenance
	static constexpr int CRIT_MAX_CHANCE = 100;
	static constexpr float CRIT_DAMAGE_MULTIPLIER = 2.0f;
	static constexpr int VARIANCE_DIVIDER = 5;

public:
	BattleManager() = default;
	~BattleManager() = default;

	// 1 turn behavior 
	// void processTurn(Player& player, Monster& monster);
};