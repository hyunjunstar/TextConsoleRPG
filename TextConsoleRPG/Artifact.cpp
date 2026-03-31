#include "Artifact.h"
#include <iostream>
#include "Player.h"

Artifact::Artifact() {
    // === tier 1 — common ===
    // 초반 유물, 상대적으로 적은 보너스
    artifactPool.push_back({ "슬라임 주스",     "공격력 +3",             3,  1.0f, 0.0f,  1 });
    artifactPool.push_back({ "가죽 장갑",       "공격력 +5",             5,  1.0f, 0.0f,  1 });
    artifactPool.push_back({ "행운의 동전",     "크리티컬 확률 +10%",     0,  1.0f, 10.0f, 1 });
    artifactPool.push_back({ "철제 반지",       "공격력 +4",             4,  1.0f, 0.0f,  1 });
    artifactPool.push_back({ "드림 캐쳐",       "최종 데미지 x1.2",       0,  1.1f, 0.0f,  1 });
    artifactPool.push_back({ "손목시계",        "크리티컬 확률 +8%",      0,  1.0f, 8.0f,  1 });
    artifactPool.push_back({ "상아 오카리나",   "최종 데미지 x1.1",       0,  1.1f, 0.0f,  1 });
    artifactPool.push_back({ "은장식 장화고리", "크리티컬 확률 +9%",      0,  1.0f, 9.0f,  1 });
    artifactPool.push_back({ "초코파이",        "공격력 +1",             1,  1.0f, 0.0f,  1 });
    artifactPool.push_back({ "다마고치",        "크리티컬 확률 +3%",      0,  1.0f, 3.0f,  1 });


    // === tier 2 — rare ===
    // 중반 유물, 초반 보다 큰 보너스
    artifactPool.push_back({ "고블린 주물",     "크리티컬 확률 +15%",     0,  1.0f, 15.0f, 2 });
    artifactPool.push_back({ "군악대 북",       "공격력 +8",             8,  1.0f, 0.0f,  2 });
    artifactPool.push_back({ "투명 망토",       "크리티컬 확률 +20%",     0,  1.0f, 20.0f, 2 });
    artifactPool.push_back({ "결투의 나팔",     "최종 데미지 x1.3",       0,  1.3f, 0.0f,  2 });
    artifactPool.push_back({ "신성한 사슬",     "크리티컬 확률 +18%",     0,  1.0f, 18.0f, 2 });
    artifactPool.push_back({ "비전 팔찌",       "공격력 +9",             9,  1.0f, 0.0f,  2 });
    artifactPool.push_back({ "마그마 화염공",   "공격력 +10",            10, 1.0f, 0.0f,  2 });
    artifactPool.push_back({ "피의 성배",       "최종 데미지 x1.4",       0,  1.4f, 0.0f,  2 });
    artifactPool.push_back({ "타이거 마스크",   "공격력 +7",              7,  1.0f, 0.0f,  2 });
    artifactPool.push_back({ "50년 된 위스키",  "크리티컬 확률 +18%",      0,  1.0f, 18.0f, 2 });


    // === tier 3 — legendary ===
    // 후반 유물, 큰 보너스
    artifactPool.push_back({ "오크의 철퇴",      "최종 데미지 x1.8",                               0,  1.8f, 0.0f,  3 });
    artifactPool.push_back({ "용의 이빨",        "공격력 +18 크리티컬 확률 +10%",                  18, 1.0f, 10.0f, 3 });
    artifactPool.push_back({ "불사조의 깃털",    "공격력 +5 최종 데미지 x1.5",                      5,  1.5f, 0.0f,  3 });
    artifactPool.push_back({ "타이탄 건틀릿",    "공격력 +15 최종 데미지 x1.3",                    15, 1.3f, 0.0f,  3 });
    artifactPool.push_back({ "미스릴 갑옷",      "최종 데미지 x1.4 크리티컬 확률 +15%",              0,  1.4f, 15.0f, 3 });
    artifactPool.push_back({ "크라켄잡이 작살",  "공격력 +35",                                    35, 1.0f, 0.0f,  3 });
    artifactPool.push_back({ "강령술사의 책",    "최종 데미지 x1.2 크리티컬 확률 +30%",              0,  1.2f, 30.0f, 3 });
    artifactPool.push_back({ "수호천사",         "공격력 +10 최종 데미지 x1.3 크리티컬 확률 +10%",  10, 1.3f, 10.0f, 3 });
    artifactPool.push_back({ "크립토나이트",     "크리티컬 확률 +55%",                              0,  1.0f, 55.0f, 3 });
    artifactPool.push_back({ "악마의 열매",      "숨겨진 능력을 얻었습니다",                        25, 2.5f, 25.0f, 3 });
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
        Player::AddAtk(player, chosen.atkBonus);
    }
    if (chosen.damageMultiplier > 1.0f) {
        Player::MultiplyDamage(player, chosen.damageMultiplier);
    }
    if (chosen.critBonus > 0.0f) {
        Player::SetCrit(player, chosen.critBonus);
    }

    std::cout << "[Artifact Acquired] " << chosen.name
        << " — " << chosen.description << std::endl;
}


