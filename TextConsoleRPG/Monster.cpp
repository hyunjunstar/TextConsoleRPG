// Monster.cpp

#include "Monster.h"

Monster::Monster(string mName, int mHp, int mAtk) {
    name = mName;
    hp = mHp;
    atk = mAtk;
}

Monster::~Monster() {
}

void Monster::takeDamage(int damage) {
    hp -= damage;

    if (hp < 0) {
        hp = 0;
    }

    cout << "[" << name << "] "
        << damage << " Take Damage (HP: "
        << hp << ")" << endl;
}

void Monster::showStatus() {
    cout << "Monster: " << name
        << " | HP: " << hp
        << " | ATK: " << atk << endl;
}

bool Monster::isDead() {
    return hp <= 0;
}