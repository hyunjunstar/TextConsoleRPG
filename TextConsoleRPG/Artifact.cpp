#include "Artifact.h"
#include <iostream>
#include "Player.h"

Artifact::Artifact() {
    // === tier 1 — common ===   총 10개 예정
    // 초반 유물, 상대적으로 적은 보너스
    artifactPool.push_back({ "Slime Juice",    "+3 ATK",      3,  1.0f, 0.0f,  1 });
    artifactPool.push_back({ "Leather Gloves", "+5 ATK",      5,  1.0f, 0.0f,  1 });
    artifactPool.push_back({ "Lucky Coin",     "+10% Crit",   0,  1.0f, 10.0f, 1 });
    artifactPool.push_back({ "Iron Ring",      "+4 ATK",      4,  1.0f, 0.0f,  1 });

    // === tier 2 — rare ===    총 10개 예정
    // 중반 유물, 초반 보다 큰 보너스
    artifactPool.push_back({ "Goblin Totem",   "+15% Crit",   0,  1.0f, 15.0f, 2 });
    artifactPool.push_back({ "War Drum",       "+8 ATK",      8,  1.0f, 0.0f,  2 });
    artifactPool.push_back({ "Shadow Cloak",   "+20% Crit",   0,  1.0f, 20.0f, 2 });
    artifactPool.push_back({ "Battle Horn",    "x1.3 DMG",    0,  1.3f, 0.0f,  2 });

    // === tier 3 — legendary ===   총 10개 예정
    // 후반 유물, 큰 보너스
    artifactPool.push_back({ "Orc Hammer",     "x1.5 DMG",           0,  1.5f, 0.0f,  3 });
    artifactPool.push_back({ "Dragon Fang",    "+12 ATK +10% Crit",  12, 1.0f, 10.0f, 3 });
    artifactPool.push_back({ "Phoenix Feather","x1.8 DMG",           0,  1.8f, 0.0f,  3 });
    artifactPool.push_back({ "Titan Gauntlet", "+15 ATK x1.3 DMG",   15, 1.3f, 0.0f,  3 });
}

std::vector<int> Artifact::getRandomChoices(int stage)
{
    // 스테이지에 따라 어떤 티어의 유물을 선택할지 결정
    int tierChance = std::rand() % 100;
    int targetTier;

    if (stage <= 3) {
        // 초반은 80% 확률로 일반, 20% 확률로 레어
        targetTier = (tierChance < 80) ? 1 : 2;
    }
    else if (stage <= 7) {
        // 중반은 30% 확률로 일반, 50% 확률로 레어, 20% 확률로 레전더리
        if (tierChance < 30)       targetTier = 1;
        else if (tierChance < 80)  targetTier = 2;
        else                       targetTier = 3;
    }
    else {
        // 후반엔 10% 확률로 일반, 40% 확률로 레어, 50% 확률로 레전더리
        if (tierChance < 10)       targetTier = 1;
        else if (tierChance < 50)  targetTier = 2;
        else                       targetTier = 3;
    }

    // 전체 유물 중 해당 등급만 골라낸다. -> 인덱스만 pool에 담긴다.
    std::vector<int> pool;
    for (int i = 0; i < static_cast<int>(artifactPool.size()); i++) {
        if (artifactPool[i].tier == targetTier) {
            pool.push_back(i);
        }
    }

    // pool에서 랜덤으로 하나를 뽑고 중복 방지를 위해 뽑은 것은 erase 한다.
    std::vector<int> choices;
    while (choices.size() < 3 && !pool.empty()) {
        int pick = std::rand() % pool.size();
        choices.push_back(pool[pick]);
        pool.erase(pool.begin() + pick);
    }

    return choices;
}

void Artifact::chooseAndApply(Player& player, int stage)
{
    std::vector<int> choices = getRandomChoices(stage);

    // 플레이어에게 선택지를 보여줌.
    std::cout << "\n=== Choose an Artifact ===" << std::endl;

    for (int i = 0; i < static_cast<int>(choices.size()); i++)
    {
        ArtifactData& a = artifactPool[choices[i]];
        std::cout << "  " << (i + 1) << ". " << a.name
            << " (" << a.description << ")" << std::endl;
    }

    // 플레이어의 선택(1~3)을 받는다.
    int selection = 0;
    while (selection < 1 || selection > static_cast<int>(choices.size())) {
        std::cout << "Enter your choice (1-" << choices.size() << "): ";
        std::cin >> selection;
    }

    // 입력 받은 유물을 플레이어에게 적용한다.
    ArtifactData& chosen = artifactPool[choices[selection - 1]];

    if (chosen.atkBonus > 0) {
        Player::SetAtk(player, chosen.atkBonus);
    }
    if (chosen.damageMultiplier > 1.0f) {
        Player::SetAtk(player, chosen.damageMultiplier);
    }
    if (chosen.critBonus > 0.0f) {
        Player::SetCrit(player, chosen.critBonus);
    }

    std::cout << "[Artifact Acquired] " << chosen.name
        << " — " << chosen.description << std::endl;
}


