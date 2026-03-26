// Monster.h

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Monster {
public:
    string name;
    int level;
    int hp;
    int atk;

    Monster(string mName, int mLevel, int mHp, int mAtk);
    void takeDamage(int damage);
    void showStatus();
    bool isDead();
};
