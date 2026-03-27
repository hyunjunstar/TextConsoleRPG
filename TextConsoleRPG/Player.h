// Player.h

#pragma once

class Player
{
	friend class Artifact;

public:
	static void SetAtk(Player& player, int bonusAtk)
	{
		baseAtk += bonusAtk;
	}
	static void SetAtk(Player& player, float bonusAtk)
	{
		baseAtk *= bonusAtk;
	}
	static void SetCrit(Player& player, float bonusCrit)
	{
		baseCrit += bonusCrit;
	}


private:
	static int baseAtk;
	static int baseCrit;

};

