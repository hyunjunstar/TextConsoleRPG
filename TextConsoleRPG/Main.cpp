// Main.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>

// 아직 빌드가 안 되는 코드들은 주석처리 하겠습니다.
// 코드 표시 //*

 //* #include "Player.h"
 //* #include "Monster.h"
 //* #include "BattleManager.h"
 //* #include "Artifact.h"

using namespace std;

void NextStep(string message)
{
	//* cout << message << endl;
	cin.clear();
	if (cin.rdbuf()->in_avail() > 0)
	{
		cin.ignore(256, '\n'); 
	} // 오류 방지를 위해 버퍼 비우기!

	cin.get(); 
	// 엔터 입력되기 전까지 다음 스테이지로 넘어가는 거 방지하는 코드. 
}

int main(void)
{
	//* srand((unsigned int)time(NULL))
		// rand() 기능을 쓸 때 시작점을 바꿔주기 위해서 쓰는 코드.
		// time(NULL)은 "1970년 1월 1일부터 지금까지 몇 초나 지났어?"라고 컴퓨터의 시계를 확인하는 코드 -> 매 순간 변하는 걸 이용한 것!

	//* Player myPlayer;
	//* BattleManager battle;
	//* Artifact asrifactSystem;

	//* Monster slime("슬라임", 40, 5); // 체력 40, 공격력 5
	//* cout << "[Stage 1] " << slime.name << "이(가) 나타났다!" << endl;
	
	//* while (!myPlayer.isDead() && !slime.isDead())
	//* {
		//* battle.processTurn(myPlayer, slime);

		//* if (!myPlayer.isDead() && !slime.isDead())
		//* {
			//* NextStep("계속 싸우려면 엔터를 누르세요.");
		//* }
	//* }

	//* if (myPlayer.isDead())
	//* {
		//* cout << "으악...!" << endl;
		//* cout << "===================" << endl;
		//* cout << "GAME OVER" << endl;

		//* return 0;
	//* }

	//* cout << slime.name << "을 물리쳤습니다!" << endl;
	//* artifactSystem.chooseAndApply(myPlayer);
	//* myPlayer.showStatus();
	//* NextStep("다음 스테이지로 이동하려면 엔터를 누르세요.");
	
	
	return 0;
}