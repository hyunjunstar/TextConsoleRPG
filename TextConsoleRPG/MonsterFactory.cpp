// MonsterFactory.cpp
#include "MonsterFactory.h"
// #include "BasicMonster.h"
#include <cstdlib>

std::unique_ptr<Monster> MonsterFactory::createMonster(int stage) 
{

    // stat scaling — higher stage = stronger monster
    float hpScale = 1.0f + (stage - 1) * 0.2f;
    float atkScale = 1.0f + (stage - 1) * 0.2f;

    // boss stage bonus
    if (stage == 5 || stage == 10) 
    {
        hpScale *= 1.5f;
        atkScale *= 1.3f;
    }

    // === boss stages ===
    if (stage == 5) 
    {
        // return std::make_unique<BasicMonster>
            (
            "Orc Warlord",
            static_cast<int>(150 * hpScale),
            static_cast<int>(12 * atkScale),
            "Heavy Smash", "Power Ground Hit",
            30, 8
        );
    }

    if (stage == 10) 
    {
        // return std::make_unique<BasicMonster>
            (
            "Dragon Lord",
            static_cast<int>(300 * hpScale),
            static_cast<int>(18 * atkScale),
            "Fire Breath", "Inferno Blast",
            40, 15
        );
    }

    // === normal stages — random monster ===
    int roll = std::rand() % 3;

    switch (roll) 
    {
    case 0:
        // return std::make_unique<BasicMonster>
            (
            "Slime",
            static_cast<int>(40 * hpScale),
            static_cast<int>(5 * atkScale),
            "Body Slam", "Spraying Mucus",
            20, 3
        );

    case 1:
        // return std::make_unique<BasicMonster>
            (
            "Goblin",
            static_cast<int>(70 * hpScale),
            static_cast<int>(8 * atkScale),
            "Quick Strike", "Stab Attack",
            25, 5
        );

    case 2:
        // return std::make_unique<BasicMonster>
            (
            "Orc",
            static_cast<int>(100 * hpScale),
            static_cast<int>(12 * atkScale),
            "Heavy Smash", "Power Ground Hit",
            30, 8
        );

            // 현재 총 5가지 몬스터 작성 완료(보스2, 일반3). 추후에 일반 5 추가 예정

    default:
        // return std::make_unique<BasicMonster>
            (
            "Slime",
            static_cast<int>(40 * hpScale),
            static_cast<int>(5 * atkScale),
            "Body Slam", "Spraying Mucus",
            20, 3
        );
    }

    return nullptr;  // TODO: replace when BasicMonster is ready
}