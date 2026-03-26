// Slime.h

#pragma once
#include "Monster.h"

class Slime : public Monster {
public:
    Slime();

    int attack() override;
    int useSkill() override;
};