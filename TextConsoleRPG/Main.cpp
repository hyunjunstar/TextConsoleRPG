// Main.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "Player.h"
#include "Monster.h"
#include "Slime.h"
#include "Goblin.h"
#include "Orc.h"
#include "BattleManager.h"
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


    cout << "\n========================================" << endl;
    ui.printSlime();
    Slime slime;

    while (myPlayer.HP > 0 && !slime.isDead()) {
        ui.printAttack();
        battle.processTurn(myPlayer, slime);

        if (myPlayer.HP > 0 && !slime.isDead()) {
            NextStep("(Press Enter to continue to the next turn...)");
        }
    }

    if (myPlayer.HP <= 0) {
        ui.printGameOver();
        return 0;
    }

    
    cout << "\n--- Stage 1 Cleared! ---" << endl;
    // artifactSystem.chooseAndApply(myPlayer, "SlimeJuice");
    myPlayer.ShowStatus();
    NextStep("(Press Enter to proceed to the next stage...)");



    cout << "\n========================================" << endl;
    ui.printGoblin();
    Goblin goblin;

    while (myPlayer.HP > 0 && !goblin.isDead()) {
        ui.printAttack();
        battle.processTurn(myPlayer, goblin);

        if (myPlayer.HP > 0 && !goblin.isDead()) {
            NextStep("(Press Enter to continue to the next turn...)");
        }
    }

    if (myPlayer.HP <= 0) {
        ui.printGameOver();
        return 0;
    }

  
    cout << "\n--- Stage 2 Cleared! ---" << endl;
    // artifactSystem.chooseAndApply(myPlayer, "GoblinTotem");
    myPlayer.ShowStatus();
    NextStep("(Press Enter to enter the Boss Room...)");



    cout << "\n========================================" << endl;
    cout << "  [WARNING] Entering the Boss Room! " << endl;
    cout << "========================================" << endl;
    ui.printOrk();
    Orc orc;

    while (myPlayer.HP > 0 && !orc.isDead()) {
        ui.printAttack();
        battle.processTurn(myPlayer, orc);

        if (myPlayer.HP > 0 && !orc.isDead()) {
            NextStep("(Press Enter to continue to the next turn...)");
        }
    }

    if (myPlayer.HP <= 0) {
        ui.printGameOver();
        return 0;
    }

    cout << "\n--- Boss Defeated! ---" << endl;
    // artifactSystem.chooseAndApply(myPlayer, "OrcHammer");
    myPlayer.ShowStatus();

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