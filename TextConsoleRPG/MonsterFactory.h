#pragma once
#include "BasicMonster.h"
#include <memory>

// Factory pattern — creates monsters based on stage number
// Usage: auto monster = MonsterFactory::createMonster(3);

class MonsterFactory {
public:
    static std::unique_ptr<BasicMonster> createMonster(int stage);
};
