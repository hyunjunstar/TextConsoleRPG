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
            "오크 워로드",
            static_cast<int>(140 * hpScale),
            static_cast<int>(12 * atkScale),
            "헤비 스매시", "지면 파쇄",
            30, 8
        );
    }

    if (stage == 10) 
    {
        return std::make_unique<BasicMonster>
            (
            "드래곤 로드",
            static_cast<int>(280 * hpScale),
            static_cast<int>(17 * atkScale),
            "파이어 브레스", "지옥불 블래스트",
            38, 14
        );
    }

    // === early stages (1~4): weak monsters ===
    if (stage <= 4)
    {
        int roll = std::rand() % 3;

        switch (roll)
        {
        case 0:
            return std::make_unique<BasicMonster>(
                "슬라임",
                static_cast<int>(55 * hpScale),
                static_cast<int>(8 * atkScale),
                "몸통 박치기", "점액 뿌리기",
                24, 5
            );
        case 1:
            return std::make_unique<BasicMonster>(
                "고블린",
                static_cast<int>(70 * hpScale),
                static_cast<int>(9 * atkScale),
                "속공", "독 찌르기",
                28, 6
            );
        case 2:
            return std::make_unique<BasicMonster>(
                "늑대",
                static_cast<int>(60 * hpScale),
                static_cast<int>(10 * atkScale),
                "광란 돌진", "포식자의 송곳니",
                26, 7
            );
        default:
            return std::make_unique<BasicMonster>(
                "슬라임",
                static_cast<int>(55 * hpScale),
                static_cast<int>(8 * atkScale),
                "몸통 박치기", "점액 뿌리기",
                24, 5
            );
        }
    }

    // === mid stages (6~7): medium monsters ===
    if (stage <= 7)
    {
        int roll = std::rand() % 3;

        switch (roll)
        {
        case 0:
            return std::make_unique<BasicMonster>(
                "오크",
                static_cast<int>(90 * hpScale),
                static_cast<int>(12 * atkScale),
                "헤비 스매시", "지면 파쇄",
                32, 8
            );
        case 1:
            return std::make_unique<BasicMonster>(
                "스켈레톤 나이트",
                static_cast<int>(95 * hpScale),
                static_cast<int>(13 * atkScale),
                "부식의 칼날", "암흑 파열",
                34, 9
            );
        case 2:
            return std::make_unique<BasicMonster>(
                "스콜피온",
                static_cast<int>(85 * hpScale),
                static_cast<int>(14 * atkScale),
                "맹독 침", "마비 독",
                36, 10
            );
        default:
            return std::make_unique<BasicMonster>(
                "오크",
                static_cast<int>(90 * hpScale),
                static_cast<int>(12 * atkScale),
                "헤비 스매시", "지면 파쇄",
                32, 8
            );
        }
    }

    // === late stages (8~9): strong monsters ===
    int roll = std::rand() % 2;

    switch (roll)
    {
    case 0:
        return std::make_unique<BasicMonster>(
            "좀비",
            static_cast<int>(110 * hpScale),
            static_cast<int>(15 * atkScale),
            "썩은 발톱", "부패한 물어뜯기",
            38, 11
        );
    case 1:
        return std::make_unique<BasicMonster>(
            "가고일",
            static_cast<int>(115 * hpScale),
            static_cast<int>(16 * atkScale),
            "돌 발톱", "석화",
            42, 12
        );
    default:
        return std::make_unique<BasicMonster>(
            "좀비",
            static_cast<int>(110 * hpScale),
            static_cast<int>(15 * atkScale),
            "썩은 발톱", "부패한 물어뜯기",
            38, 11
        );
    }
}