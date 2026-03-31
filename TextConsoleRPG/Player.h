#pragma once
#include <iostream>
#include <string>

class Player
{
    friend class Artifact;

public:
    std::string pname = "";//플레이어 이름
    int HP = 0;//체력
    float BaseAtk = 0.0f;//기본공격력
    int exp = 0;//경험치//*3.30추가
    int level = 1;//레벨(플레이어가 사용)//*3.30추가
    int maxHP = 0; // 플레이어 최대체력//*3.30추가
    int potion = 0;

    float CritChance = 0.0f;//치명타확률//*3.30 수정 밑의 치명타 확률 설정 함수랑 통일하기위해 float로 변경
    float DamageMultiplier = 1.0f;//데미지 배율

    void TakeDamage(int damage);// 데미지를 받는 함수
    void ShowStatus();// 내상태보는 함수
    void Levelup();//레벨업 함수// *3.30추가
    void GainExp(int amount);//경험치 획득 함수 *3.30추가

    static void AddAtk(Player& player, int amount)//공격력증가 함수, 함수명 변경
    {
        player.BaseAtk += amount;
    }
    static void MultiplyDamage(Player& player, float multiplier)//데미지 배율 함수, 함수명 변경
    {
        player.DamageMultiplier *= multiplier;
    }
    static void SetCrit(Player& player, float bonusCrit)// 치명타 확률 증가 함수
    {
        player.CritChance += bonusCrit;
    }

};

Player CreatePlayer();//케릭터 생성