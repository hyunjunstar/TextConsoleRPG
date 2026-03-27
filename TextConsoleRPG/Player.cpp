//Player.cpp

#include "Player.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

//케릭터 생성
Player CreatePlayer() //Player class에서 케릭터를 생성하는 함수
{
    Player p; //Player class로 p 라는 케릭터를 만듦

    std::cout << "당신은 누구시죠?" << std::endl;
    std::cin >> p.pname;
    std::cout << "위대한 모험가 " << p.pname << "의 여정이 시작되었다" << std::endl;

    p.HP = 100;
    p.BaseAtk = std::rand() % 6 + 10;
    //를 사용하려는데 안되서 일단 10으로 고정함 //해결함
    //기본공격력은 10~15 범위안에서 랜덤으로 설정이라는 뜻
    p.bonusAtk = 0;
    p.CritChance = 0;
    p.DamageMultiplier = 1.0f;

    return p;
}

//데미지를 받음
void Player::TakeDamage(int damage)//Player class에 속한 데미지받는 행동을 정의한 함수
{
    HP -= damage;

    if (HP < 0) HP = 0;//HP가 0보다 작을 경우 0으로 보정

    if (HP == 0) //HP가 0일때 사망
    {
        std::cout << pname << "(이)가 사망했습니다...\n 그렇게 세상은 멸망했다...\n";

        return;
    }

    std::cout << pname << "(이)가 " << damage << "의 데미지를 입었습니다.(남은 HP : " << HP << ")" << std::endl;

}


// 내 상태 보기
void Player::ShowStatus()//Player class에 속한 내 상태를 보여주는 함수
{
    std::cout << "\n=================================\n";
    std::cout << "[" << pname << "의 상태]\n";
    std::cout << "===================================\n";
    std::cout << "HP:" << HP << "\n";
    std::cout << "공격력:" << (BaseAtk + bonusAtk) << "\n";
    std::cout << "[유물 효과] 크리티컬 확률: " << CritChance << "%\n";
    std::cout << "데미지 배율 : x" << DamageMultiplier << "\n";
    std::cout << "===================================\n" << std::endl;
}