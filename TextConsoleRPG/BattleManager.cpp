// BattleManager.cpp

#include "BattleManager.h"
#include <iostream>

void BattleManager::processTurn(Player& player, Monster& monster)
{
	// 1. Player Attack Phase

	// ** base attack power
	int totalAtk = player.BaseAtk;

	// ** apply damage variance
	int varianceLimit = totalAtk / VARIANCE_DIVIDER;

	// decide +- damage
	int variance = (std::rand() % (varianceLimit * 2 + 1)) - varianceLimit;
	int finalDamage = totalAtk + variance;

	if (finalDamage < 1) 
	{
	finalDamage = 1;
	}

	// critical calculation
	int critRoll = (std::rand() % CRIT_MAX_CHANCE) + 1; // 1 ~ 100
	if (critRoll <= player.CritChance) 
	{
		finalDamage = static_cast<int>(finalDamage * CRIT_DAMAGE_MULTIPLIER);
	}

	// apply relic
	finalDamage = static_cast<int>(finalDamage * player.DamageMultiplier);

	//apply damage to monster
	monster.takeDamage(finalDamage);
	
	// 2. check monster dead
	if (monster.isDead())
	{
	 	return;  // if monster dead turn end
	}

	// 3. mosnter counterattack phase

	int monsterDamage = monster.useSkill();  // skill attempt

	if (monsterDamage == -1)                 // if skill failed
	{
		monsterDamage = monster.attack();    // replace to base attack
	}

	// apply damage variance to monster attack
	int monsterVariance = monsterDamage / VARIANCE_DIVIDER;
	int monsterFinal = monsterDamage + (std::rand() % (monsterVariance * 2 + 1)) - monsterVariance;

	if (monsterFinal < 1)
	{
		monsterFinal = 1;
	}

	player.TakeDamage(monsterFinal);
}