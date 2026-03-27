// Player.h

#pragma once
#include <iostream>
#include <string>

class Player
{
	friend class Artifact;

public:
	
	int HP; // 플레이어 체력
	float BaseAtk; //플레이어 기본 공격력
	std::string pname; //플레이어 이름

	// 유물 효과 스탯, 스테이지 클리어시 획득
	
	int CritChance; //치명타 확률
	float DamageMultiplier; //최종데미지*1.5

	void TakeDamage(int damage); //플레이어가 데미지를 받음
	void ShowStatus(); // 내 상태보기

	
	static void SetAtk(Player& player, int amount) //빌드시 자료형 관련해서 경고 나옴 주말내로 해결해보겠음
	{
		player.BaseAtk += amount;
	}
	static void SetAtk(Player& player, float multiplier)
	{
		player.DamageMultiplier *= multiplier;
	}
	static void SetCrit(Player& player, float bonusCrit)
	{
		player.CritChance += bonusCrit;
	}

};


