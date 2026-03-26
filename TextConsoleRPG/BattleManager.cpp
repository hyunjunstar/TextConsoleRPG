#include "BattleManager.h"
#include <iostream>


// void BattleManager::processTurn(Player& player, Monster& monster)
// {
	// 1. 플레이어 공격 페이즈

	// 일단 기초 공격력 결정
	// int totalAtk = player.baseAtk + player.bonusAtk;

	// 데미지 변동성 적용
	// int varianceLimit = totalAtk / VARIANCE_DIVIDER;

	// 랜덤하게 데미지가 추가될지 감소될지 결정
	// int variance = (std::rand() % (varianceLimit * 2 + 1)) - varianceLimit;
	// int finalDamage = totalAtk + variance;

	// if (finalDamage < 1) 
	// {
	// 	finalDamage = 1;
	// }

	// 크리티컬 계산
	// int critRoll = (std::rand() % CRIT_MAX_CHANCE) + 1; // 1 ~ 100
	// if (critRoll <= player.critChance) 
	// {
	// 	finalDamage = static_cast<int>(finalDamage * CRIT_DAMAGE_MULTIPLIER);
	// }

	// 유물 배율 적용
	// finalDamage = static_cast<int>(finalDamage * player.damageMultiplier);

	// 몬스터에게 데미지 적용
	// monster.takeDamage(finalDamage);
// }