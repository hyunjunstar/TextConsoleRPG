// Monster.cpp

#include "Monster.h"

Monster::Monster(string mName, int mLevel, int mHp, int mAtk) {
    name = mName;
    level = mLevel;
    hp = mHp;
    atk = mAtk;
}

void Monster::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) hp = 0;
    cout << "[" << name << "] 으윽! " << damage << "의 데미지를 입었다. (남은 HP: " << hp << ")" << endl;
}

void Monster::showStatus() {
    cout << "▶ 몬스터[" << name << "] HP: " << hp << " / 공격력: " << atk << endl;
}

bool Monster::isDead() {
    return hp <= 0;
}
