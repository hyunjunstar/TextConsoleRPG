// Main.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>

#include "Player.h"
#include "BasicMonster.h"
#include "BattleManager.h"
#include "MonsterFactory.h"
#include "Artifact.h"
#include "UI.h"

using namespace std;

const int COLOR_NORMAL = 0x07;  // 검은 바탕 + 기본 흰색 (평상시)
const int COLOR_BOSS = 0x04;  // 검은 바탕 + 빨간색 (보스 경고, 사망)
const int COLOR_REWARD = 0x0E;  // 검은 바탕 + 노란색 (보상, 렙업, 클리어)
const int COLOR_SYSTEM = 0x0B;  // 검은 바탕 + 청록색 (시스템 메시지, 선택지)

void SetColor(int colorCode) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
}

extern Player CreatePlayer();

void NextStep(string message) 
{
    SetColor(COLOR_SYSTEM);
    cout << "\n" << message;
    SetColor(COLOR_NORMAL);

    cin.clear();
    if (cin.rdbuf()->in_avail() > 0)
    {
        cin.ignore(256, '\n');
    } // 버퍼 비우기

    cin.get();
    // 엔터만 쳐도 다음으로 넘어갈 수 있게 해줌.
}

int main() {

    srand((unsigned int)time(NULL));
    // rand() 기능을 쓸 때 시작점을 바꿔주기 위해서 쓰는 코드.
    // time(NULL)은 "1970년 1월 1일부터 지금까지 몇 초나 지났어?"라고 컴퓨터의 시계를 확인하는 코드 -> 매 순간 변하는 걸 이용한 것!

    UI ui;
    BattleManager battle;
    Artifact artifactSystem; 

    SetColor(COLOR_NORMAL);

    cout << "=============================================" << endl;
    cout << "  박경호와 아이들이 만든 Text Console RPG " << endl;
    cout << "=============================================\n" << endl;

    ui.printCharacter();
    Player myPlayer = CreatePlayer();
    myPlayer.ShowStatus();
    NextStep("(엔터를 눌러 모험을 시작하세요...)");

    

    // === 10 stage loop ===
    for (int stage = 1; stage <= 10; stage++)
    {
        // create monster for this stage
        auto monster = MonsterFactory::createMonster(stage);

        // stage announcement
        cout << "\n========================================" << endl;

        if (stage == 5)
        {
            SetColor(COLOR_BOSS);
            cout << "  [Stage " << stage << "] 중간 보스가 나타났습니다!!!\n" << endl;
            SetColor(COLOR_NORMAL);
            ui.printGoblin();
        }
        else if (stage == 10)
        {
            SetColor(COLOR_BOSS);
            cout << "  [Stage " << stage << "] 최종 보스가 나타났습니다!!!!!\n" << endl;
            SetColor(COLOR_NORMAL);
            ui.printOrk();
        }
        else
        {
            SetColor(COLOR_BOSS);
            cout << "  [Stage " << stage << "] 몬스터가 나타났습니다!\n" << endl;
            SetColor(COLOR_NORMAL);
            ui.printSlime();
        }

        cout << "========================================" << endl;
        monster->showStatus();

        // battle loop
        while (myPlayer.HP > 0 && !monster->isDead())
        {
            SetColor(COLOR_SYSTEM);
            int choice = 0;
            cout << "\n [ HP: " << myPlayer.HP << " / " << myPlayer.maxHP << " ] " << endl;
            SetColor(COLOR_NORMAL);

            cout << "\n[1] 현재 상태 확인 (턴 소모 없음) " << endl;
            cout << "==================================" << endl;
            cout << "\n[2] 공격하기!! [3] 포션 사용하기 (남은 개수: "<< myPlayer.potion << ")" << endl;
            cout << "\n행동을 선택하세요 : ";
         

            cin >> choice;

            if (choice == 1)
            {
                myPlayer.ShowStatus();
                continue;
            }

            if (choice == 3)
            {
                if (myPlayer.potion <= 0)
                {
                    SetColor(COLOR_BOSS);
                    cout << "\n 남은 포션이 없습니다." << endl;
                    SetColor(COLOR_NORMAL);
                    continue;
                }
                else
                {
                    myPlayer.potion--;
                    myPlayer.HP += 50;

                    if (myPlayer.HP > myPlayer.maxHP)
                    {
                        myPlayer.HP = myPlayer.maxHP;
                    }

                    SetColor(COLOR_REWARD);
                    cout << "\n [아이템] 포션을 사용했습니다! 체력을 50 회복했습니다." << endl;
                    SetColor(COLOR_NORMAL);

                    SetColor(COLOR_BOSS);
                    cout << "\n 몬스터가 공격합니다!" << endl;
                    SetColor(COLOR_NORMAL);

                    ui.printAttack();
                    // 여기에 몬스터만 player 공격할 수 있게 코드 부탁드려요 ㅠㅠ

                }

            }

            else
            {
                ui.printAttack();
                battle.processTurn(myPlayer, *monster);
            }

            if (myPlayer.HP > 0 && !monster->isDead())
            {
                NextStep("(엔터를 눌러 다음 스테이지로 이동하세요...)");
            }
        }

        // game over check
        if (myPlayer.HP <= 0)
        {
            SetColor(COLOR_BOSS);
            ui.printGameOver();
            SetColor(COLOR_NORMAL);
            return 0;
        }

        // stage clear
        SetColor(COLOR_REWARD);
        cout << "\n--- Stage " << stage << " Cleared! ---" << endl;
        SetColor(COLOR_NORMAL);


        myPlayer.potion++;
        cout << "보상: 몬스터를 처치하여 포션을 1개 획득했습니다!" << endl;

        myPlayer.HP = myPlayer.maxHP;
        cout << "스테이지 클리어 보너스로 모든 체력이 회복되었습니다!" << endl;
        

        // gain exp
        myPlayer.GainExp(30 + stage * 10);

        // artifact selection (not on final stage)
        if (stage < 10)
        {
            artifactSystem.chooseAndApply(myPlayer, stage);
        }

        myPlayer.ShowStatus();

        // next stage prompt
        if (stage < 10)
        {
            if (stage == 4)
            {
                NextStep("(엔터를 눌러 중간 보스의 방으로 진입하세요...)");
            }
            else if (stage == 9)
            {
                NextStep("(엔터를 눌러 최종 보스의 방으로 진입하세요...)");
            }
            else
            {
                NextStep("(엔터를 눌러 다음 스테이지로 이동하세요...)");
            }
        }
    }

    NextStep("(엔터를 눌러 엔딩을 확인하세요...)");
    SetColor(COLOR_REWARD);
    ui.printGameClear();
    cout << "\n 축하합니다! 당신이 세상을 구했습니다!" << endl;

    SetColor(COLOR_NORMAL);
    cout << "\n\n [만든 사람들]" << endl;
    cout << "- 메인 디렉터 : 백록담 - " << endl;
    cout << "- 플레이어 담당 : 김남윤 - " << endl;
    cout << "- 몬스터 담당 : 김현준 - " << endl;
    cout << "- 핵심 로직(전투 계산) 담당 : 조유현 - " << endl;
    cout << "- 성장 로직(유물 시스템) 담당 : 정태민 - " << endl;
    cout << "- UI 및 텍스트 연출 담당 : 전지원 - " << endl;

    return 0;
}