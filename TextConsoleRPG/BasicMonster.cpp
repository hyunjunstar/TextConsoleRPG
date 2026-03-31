// BasicMonster.cpp

#include "BasicMonster.h"
#include <windows.h>

const int COLOR_NORMAL = 0x07;  // 검은 바탕 + 기본 흰색 (평상시)
const int COLOR_REWARD = 0x0E;  // 검은 바탕 + 노란색 (보상, 렙업, 클리어)
const int COLOR_BOSS = 0x04; // 검은 바탕 + 빨간색 (보스 경고, 사망)

extern void SetColor(int colorCode);

BasicMonster::BasicMonster(
    string mName,
    int mHp,
    int mAtk,
    string mAtkName,
    string mSkName,
    int mSkChance,
    int mSkBonus
) {
    name = mName;
    hp = mHp;
    atk = mAtk;
    atkName = mAtkName;
    skName = mSkName;
    skChance = mSkChance;
    skBonus = mSkBonus;
}

void BasicMonster::showStatus() {
    cout << "Monster: " << name
        << " | HP: " << hp
        << " | ATK: " << atk << endl;
}

int BasicMonster::attack() {
    SetColor(COLOR_BOSS);
    cout << name << "의 " << atkName << "!" << endl;
    SetColor(COLOR_NORMAL);
    return atk;
}

int BasicMonster::useSkill() {

    int randValue = rand() % 100;

    if (randValue >= skChance)
    {
        return -1;
    }

    SetColor(COLOR_BOSS);
    cout << name << "의 스킬 발동 " << skName << "!!" << endl;
    SetColor(COLOR_NORMAL);
    return atk + skBonus;
}

void BasicMonster::takeDamage(int damage) {
    hp -= damage;

    if (hp < 0) {
        hp = 0;
    }
    cout << "[" << name << "] 님이"
        << damage << " 의 데미지를 입었습니다. (HP: "
        << hp << ")" << endl;
}

bool BasicMonster::isDead() {
    return hp <= 0;
}