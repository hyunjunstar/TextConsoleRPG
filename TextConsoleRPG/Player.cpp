//Player.cpp

#include "Player.h"
#include <cstdlib>
#include <iostream>

//캐릭터 생성
Player CreatePlayer() //Player class에서 캐릭터를 생성하는 함수
{
    Player p; //Player class로 p 라는 캐릭터를 만듦

    std::cout << "Enter your name, adventurer: " << std::endl;
    std::cin >> p.pname;
    std::cout << "The journey of the great adventurer [" << p.pname << "] begins!\n" << std::endl;

    p.HP = 100;
    p.BaseAtk = std::rand() % 6 + 10;
    //를 사용하려는데 안되서 일단 10으로 고정함 //해결함
    //기본공격력은 10~15 범위안에서 랜덤으로 설정이라는 뜻
    p.CritChance = 0;
    p.DamageMultiplier = 1.0f;

    return p;
}

//데미지를 받음
void Player::TakeDamage(int damage)//Player class에 속한 데미지받는 행동을 정의한 함수
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    } //HP가 0보다 작을 경우 0으로 보정

    if (HP == 0) //HP가 0일때 사망
    {
        std::cout << pname << "has died...\nAnd so, the world ends...\n";

        return;
    }

    std::cout << pname << " took " << damage << " damage. (Current HP: " << HP << ")" << std::endl;

}


// 내 상태 보기
void Player::ShowStatus() //Player class에 속한 내 상태를 보여주는 함수
{
    std::cout << "\n=================================\n";
    std::cout << "       [" << pname << "'s Status]      \n";
    std::cout << "===================================\n";
    std::cout << "HP: " << HP << "\n";
    std::cout << "ATK: " << BaseAtk << "\n";
    std::cout << " [Artifact] Crit Chance: " << CritChance << "%\n";
    std::cout << "[Artifact] DMG Multiplier: x" << DamageMultiplier << "\n";
    std::cout << "===================================\n" << std::endl;
}