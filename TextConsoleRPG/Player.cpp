//Player.cpp

#include "Player.h"
#include <cstdlib>
#include <iostream>
#include <windows.h>

const int COLOR_NORMAL = 0x07;  
const int COLOR_REWARD = 0x0E;  

extern void SetColor(int colorCode);

//캐릭터 생성
Player CreatePlayer() //Player class에서 캐릭터를 생성하는 함수
{
    Player p; //Player class로 p 라는 캐릭터를 만듦

    std::cout << "\n위대한 모험가님의 성함을 알려주세요: ";
    std::getline(std::cin, p.pname);//*3.30 수정 띄어쓰기 사용가능
    SetColor(COLOR_REWARD);
    std::cout << "모험가 [" << p.pname << "] 님의 위대한 여정이 시작됩니다!\n" << std::endl;
    SetColor(COLOR_NORMAL);
    p.maxHP = 100;//3.30 추가
    p.HP = p.maxHP;//3.30 수정
    p.exp = 0;//3.30 추가
    p.level = 1;//3.30 추가
    p.BaseAtk = std::rand() % 6 + 10;
    //를 사용하려는데 안되서 일단 10으로 고정함 //해결함
    //기본공격력은 10~15 범위안에서 랜덤으로 설정이라는 뜻
    p.CritChance = 0;
    p.DamageMultiplier = 1.0f;
    p.potion = 0;

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
        std::cout << pname << "\n님이 쓰러졌습니다...\n그렇게 세상은 종말을 맞이했습니다...\n";

        return;
    }

    std::cout << pname << "님이 " << damage << "의 데미지를 입었습니다. (현재 HP: " << HP << ")" << std::endl;

}

// 내 상태 보기
void Player::ShowStatus() //Player class에 속한 내 상태를 보여주는 함수
{
    std::cout << "\n===================================\n";
    std::cout << "       [" << pname << "의 상태]      \n";
    std::cout << "===================================\n";
    std::cout << "Level: " << level << "\n";//*3.30 추가
    std::cout << "EXP: " << exp << "\n";//*3.30추가
    std::cout << "HP: " << HP << "/ " << maxHP << "\n";//*3.30 수정 최대최력과 현재 체력 보여줌
    std::cout << "공격력: " << BaseAtk << "\n";
    std::cout << "[유물] 치명타 확률: " << CritChance << "%\n";
    std::cout << "[유물] 데미지 배율: x" << DamageMultiplier << "\n";
    std::cout << "===================================\n" << std::endl;
}

void Player::GainExp(int amount)//경험치 획득 함수*3.30 추가
{
    exp += amount;
    std::cout << pname << "님이 " << amount << "의 경험치를 획득했습니다!\n";

    while (exp >= 100)//경험치가 100보다 크거나 같으면
    {
        exp -= 100;//경험치에서 100을 뺀후
        Levelup();// 레벨업
    }
}

void Player::Levelup()//레벨업 함수 *3.30 추가
{
    if (level >= 10)
    {
        std::cout << "최대 레벨에 도달했습니다!\n";
        std::cout << "이제 더 이상 내게 적수는 없다!!" << std::endl;//도전과제 몬스터 보스전
        return;
    }
    level++;
    maxHP += 20;
    HP = maxHP;// HP 회복
    BaseAtk += 5;

    SetColor(COLOR_REWARD);
    std::cout << "\n*** LEVEL UP! ***\n";
    SetColor(COLOR_NORMAL);
    std::cout << pname << "님이 레벨 " << level << "으로 올랐습니다!\n";
    std::cout << "최대 체력이 20, 공격력이 5 증가했습니다.\n" << std::endl;
}