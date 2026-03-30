// Monster.h

#pragma once
#include <iostream>
#include <string>

using namespace std;

class BasicMonster{

private:
    string name;      // 몬스터 이름
    int hp;           // 현재 체력
    int atk;          // 기본 공격력
    string atkName;   // 기본 공격 이름
    string skName;    // 스킬 공격 이름
    int skChance;     // 스킬 발동 확률
    int skBonus;      // 스킬 추가 데미지

public:
    BasicMonster(
        string mName,
        int mHp,
        int mAtk,
        string mAtkName,
        string mSkName,
        int mSkChance,
        int mSkBonus
    );

    void showStatus();
    int attack();
    int useSkill();
    void takeDamage(int damage);
    bool isDead();
};