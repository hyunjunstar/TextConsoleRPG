// Monster.h

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Monster {
protected:
    string name;
    int hp;
    int atk;

public:
    Monster(string mName, int mHp, int mAtk);
    virtual ~Monster();

    virtual int attack() = 0;
    virtual int useSkill() = 0;

    void takeDamage(int damage);
    void showStatus();
    bool isDead();
};