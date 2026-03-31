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
            static_cast<int>(150 * hpScale),
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
            static_cast<int>(300 * hpScale),
            static_cast<int>(18 * atkScale),
            "파이어 브레스", "지옥불 블래스트",
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
            "슬라임",
            static_cast<int>(40 * hpScale),
            static_cast<int>(5 * atkScale),
            "몸통 박치기", "점액 뿌리기",
            20, 3
        );

    case 1:
        return std::make_unique<BasicMonster>
            (
            "고블린",
            static_cast<int>(60 * hpScale),
            static_cast<int>(7 * atkScale),
            "속공", "독 찌르기",
            25, 5
        );

    case 2:
        return std::make_unique<BasicMonster>
            (
            "오크",
            static_cast<int>(80 * hpScale),
            static_cast<int>(10 * atkScale),
            "헤비 스매시", "지면 파쇄",
            30, 8
        );

    case 3:
        return std::make_unique<BasicMonster>
            (
            "스켈레톤 나이트",
            static_cast<int>(100 * hpScale),
            static_cast<int>(12 * atkScale),
            "부식의 칼날", "암흑 파열",
            35, 10
        );

    case 4:
        return std::make_unique<BasicMonster>
            (
            "스콜피온",
            static_cast<int>(120 * hpScale),
            static_cast<int>(15 * atkScale),
            "맹독 침", "마비 독",
            40, 12
        );

    case 5:
        return std::make_unique<BasicMonster>
            (
            "좀비",
            static_cast<int>(140 * hpScale),
            static_cast<int>(18 * atkScale),
            "썩은 발톱", "부패한 물어뜯기",
            45, 15
        );

    case 6:
        return std::make_unique<BasicMonster>
            (
            "늑대",
            static_cast<int>(160 * hpScale),
            static_cast<int>(20 * atkScale),
            "광란 돌진", "포식자의 송곳니",
            50, 18
        );

    case 7:
        return std::make_unique<BasicMonster>
            (
            "가고일",
            static_cast<int>(180 * hpScale),
            static_cast<int>(22 * atkScale),
            "돌 발톱", "석화",
            55, 20
        );

            // 현재 총 10가지 몬스터 작성 완료(보스2, 일반8).

    default:
        return std::make_unique<BasicMonster>
            (
            "슬라임",
            static_cast<int>(40 * hpScale),
            static_cast<int>(5 * atkScale),
            "몸통 박치기", "점액 뿌리기",
            20, 3
        );
    }
}