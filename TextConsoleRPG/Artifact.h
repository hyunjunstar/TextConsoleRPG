#pragma once
#include <string>
#include <vector>

class Player;  // 전방 선언

// === 유물 데이터를 모아두는 컨테이너 ===
// 데이터만 존재
struct ArtifactData 
{
    std::string name;       // 이름
    std::string description;// 설명
    int atkBonus;           // (0 = none)
    float damageMultiplier; // (1.0 = no change)
    float critBonus;        // (0 = none)
    int tier;               // 1 = common, 2 = rare, 3 = legendary
};

class Artifact 
{
private:
    // 모든 유물을 한 리스트에 저장
    std::vector<ArtifactData> artifactPool;

    // 스테이지에 따라 랜덤한 3개의 유물을 정한다
    std::vector<int> getRandomChoices(int stage);

public:
    Artifact();  // constructor fills the pool
    void chooseAndApply(Player& player, int stage);
};