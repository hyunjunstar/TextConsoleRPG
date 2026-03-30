// MonsterFactory.cpp
#include "MonsterFactory.h"
#include "BasicMonster.h"
#include <cstdlib>

std::unique_ptr<BasicMonster> MonsterFactory::createMonster(int stage)
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
        return std::make_unique<BasicMonster>
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
        return std::make_unique<BasicMonster>
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
        return std::make_unique<BasicMonster>
            (
            "Slime",
            static_cast<int>(40 * hpScale),
            static_cast<int>(5 * atkScale),
            "Body Slam", "Spraying Mucus",
            20, 3
        );

    case 1:
        return std::make_unique<BasicMonster>
            (
            "Goblin",
            static_cast<int>(60 * hpScale),
            static_cast<int>(7 * atkScale),
            "Quick Strike", "Stab Attack",
            25, 5
        );

    case 2:
        return std::make_unique<BasicMonster>
            (
            "Orc",
            static_cast<int>(80 * hpScale),
            static_cast<int>(10 * atkScale),
            "Heavy Smash", "Power Ground Hit",
            30, 8
        );

    case 3:
        return std::make_unique<BasicMonster>
            (
            "Skeleton Knight",
            static_cast<int>(100 * hpScale),
            static_cast<int>(12 * atkScale),
            "Rusty Blade", "Dark Rupture",
            35, 10
        );

    case 4:
        return std::make_unique<BasicMonster>
            (
            "Scorpion",
            static_cast<int>(120 * hpScale),
            static_cast<int>(15 * atkScale),
            "Venom Sting", "Paralyzing Venom",
            40, 12
        );

    case 5:
        return std::make_unique<BasicMonster>
            (
            "Zombie",
            static_cast<int>(140 * hpScale),
            static_cast<int>(18 * atkScale),
            "Rotten Claw", "Decaying Bite",
            45, 15
        );

    case 6:
        return std::make_unique<BasicMonster>
            (
            "Wolf",
            static_cast<int>(160 * hpScale),
            static_cast<int>(20 * atkScale),
            "Savage Bite", "Frenzy Rush",
            50, 18
        );

    case 7:
        return std::make_unique<BasicMonster>
            (
            "Gargoyle",
            static_cast<int>(180 * hpScale),
            static_cast<int>(22 * atkScale),
            "Stone Claw", "Petrify",
            55, 20
        );

            // 현재 총 10가지 몬스터 작성 완료(보스2, 일반8).

    default:
        return std::make_unique<BasicMonster>
            (
            "Slime",
            static_cast<int>(40 * hpScale),
            static_cast<int>(5 * atkScale),
            "Body Slam", "Spraying Mucus",
            20, 3
        );
    }
}