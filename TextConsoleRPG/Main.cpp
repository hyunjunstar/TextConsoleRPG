// Main.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "Player.h"
#include "BasicMonster.h"
#include "BattleManager.h"
#include "MonsterFactory.h"
#include "Artifact.h"
#include "UI.h"

using namespace std;

extern Player CreatePlayer();

void NextStep(string message) 
{
    cout << "\n" << message << endl;
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
            cout << "  [Stage " << stage << "] Mid-Boss appeared!" << endl;
        }
        else if (stage == 10)
        {
            cout << "  [Stage " << stage << "] Final Boss appeared!!" << endl;
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
            ui.printAttack();
            battle.processTurn(myPlayer, *monster);

            if (myPlayer.HP > 0 && !monster->isDead())
            {
                NextStep("(Press Enter to continue to the next turn...)");
            }
        }

        // game over check
        if (myPlayer.HP <= 0)
        {
            ui.printGameOver();
            return 0;
        }

        // stage clear
        cout << "\n--- Stage " << stage << " Cleared! ---" << endl;

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
    ui.printGameClear();
    cout << "\nCongratulations! You have saved the world!" << endl;

    cout << "\n\n [Credits]" << endl;
    cout << "- Main Director : Baek Rok dam -" << endl;
    cout << "- Player Mechanics : Kim Nam yun -" << endl;
    cout << "- Monster Mechanics : Kim Hyun jun -" << endl;
    cout << "- Core Logic (Combat Calculation) : Jo Yu hyeon -" << endl;
    cout << "- Growth Logic (Relic System) : Jeong Tae min -" << endl;
    cout << "- UI & Text Effects : Jeon Ji won -" << endl;


    return 0;
}