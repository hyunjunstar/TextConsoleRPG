// Monster.cpp

#include "BasicMonster.h"

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
    cout << name << " Attack!" << endl;
    return atk;
}

int BasicMonster::useSkill() {
    cout << name << " Skill Attack!" << endl;
    return atk + skBonus;
}

void BasicMonster::takeDamage(int damage) {
    hp -= damage;

    if (hp < 0) {
        hp = 0;
    }
    cout << "[" << name << "] "
        << damage << " Take Damage (HP: "
        << hp << ")" << endl;
}

bool BasicMonster::isDead() {
    return hp <= 0;
}