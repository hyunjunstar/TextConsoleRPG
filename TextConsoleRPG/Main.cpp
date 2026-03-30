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
const int COLOR_BOSS = 0x4F;  // 빨간 바탕 + 밝은 흰색 (보스 경고, 사망)
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
    cout << "\n" << message << endl;
    SetColor(COLOR_NORMAL);

    cin.clear();
    if (cin.rdbuf()->in_avail() > 0)
    {
        cin.ignore(256, '\n');
    } // 버퍼 비우기

    cin.get();
    // 엔터 입력되기 전까지 다음 스테이지로 넘어가는 거 방지하는 코드.
}

int main() {

    srand((unsigned int)time(NULL));
    // rand() 기능을 쓸 때 시작점을 바꿔주기 위해서 쓰는 코드.
    // time(NULL)은 "1970년 1월 1일부터 지금까지 몇 초나 지났어?"라고 컴퓨터의 시계를 확인하는 코드 -> 매 순간 변하는 걸 이용한 것!

    UI ui;
    BattleManager battle;
    Artifact artifactSystem; 

    SetColor(COLOR_NORMAL);

    cout << "========================================" << endl;
    cout << "  The Beginning  " << endl;
    cout << "========================================\n" << endl;

    ui.printCharacter();
    Player myPlayer = CreatePlayer();
    myPlayer.ShowStatus();
    NextStep("(Press Enter to start the adventure...)");


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
            cout << "  [Stage " << stage << "] Mid-Boss appeared!" << endl;
            SetColor(COLOR_NORMAL);
        }
        else if (stage == 10)
        {
            SetColor(COLOR_BOSS);
            cout << "  [Stage " << stage << "] Final Boss appeared!!" << endl;
            SetColor(COLOR_NORMAL);
        }
        else
        {
            cout << "  [Stage " << stage << "] A monster appeared!" << endl;
        }

        cout << "========================================" << endl;
        monster->showStatus();

        // battle loop
        while (myPlayer.HP > 0 && !monster->isDead())
        {
            SetColor(COLOR_SYSTEM);
            int choice = 0;
            cout << "\n[1] Attack!! [2] Check Status" << endl;
            cout << "Choose your action: " << endl;

            SetColor(COLOR_NORMAL);

            cin >> choice;

            if (choice == 2)
            {
                myPlayer.ShowStatus();
                continue;
            }

            else
            {
                ui.printAttack();
                battle.processTurn(myPlayer, *monster);
            }

            if (myPlayer.HP > 0 && !monster->isDead())
            {
                NextStep("(Press Enter to continue to the next turn...)");
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
                NextStep("(Press Enter to enter the Mid-Boss Room...)");
            }
            else if (stage == 9)
            {
                NextStep("(Press Enter to enter the Final Boss Room...)");
            }
            else
            {
                NextStep("(Press Enter to proceed to the next stage...)");
            }
        }
    }

    NextStep("(Press Enter to see the ending...)");
    SetColor(COLOR_REWARD);
    ui.printGameClear();
    cout << "\nCongratulations! You have saved the world!" << endl;

    SetColor(COLOR_NORMAL);
    cout << "\n\n [Credits]" << endl;
    cout << "- Main Director : Baek Rok dam -" << endl;
    cout << "- Player Mechanics : Kim Nam yun -" << endl;
    cout << "- Monster Mechanics : Kim Hyun jun -" << endl;
    cout << "- Core Logic (Combat Calculation) : Jo Yu hyeon -" << endl;
    cout << "- Growth Logic (Relic System) : Jeong Tae min -" << endl;
    cout << "- UI & Text Effects : Jeon Ji won -" << endl;

    return 0;
}