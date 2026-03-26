#pragma once
// #include "Player.h"
#include "Monster.h"
#include <cstdlib>

class BattleManager
{
private:
	// 유지보수를 위한 크리티컬 및 데미지 변동성 상수화
	static constexpr int CRIT_MAX_CHANCE = 100;
	static constexpr float CRIT_DAMAGE_MULTIPLIER = 2.0f;
	static constexpr int VARIANCE_DIVIDER = 5;

public:
    BattleManager() = default;
    ~BattleManager() = default;

    // 1턴 동안의 동작 정리
    // void processTurn(Player& player, Monster& monster);

    // 끝날 때까지 processTurn 돌리기
    // bool runBattle(Player& player, Monster& monster);
};