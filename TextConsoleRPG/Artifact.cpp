// Artifact.cpp

#include "Artifact.h"
#include <iostream>
#include <string>
#include "Player.h"


// Artifact::Artifact(std::string ArtifactName)
// 메인 함수에서 console in을 받아야 합니다.
// ex. 사용하실 유물의 이름을 입력해주십시오.
// {
//	if (IsBoss1Eliminated == true && ArtifactName == "SlimeJuice")
//	{
//		//Player::SetAtk(플레이어객체이름, 5);
//		std::cout << "You got a SlimeJuice. Your Attack Damage has been increased." << std::endl;
//	}
//	if (IsBoss1Eliminated == true && IsBoss2Eliminated == true && ArtifactName == "GoblinTotem")
//	{
//		//Player::SetCrit(플레이어객체이름, 20);
//		std::cout << "You got a GoblinTotem. You got a Critical Strike Chance." << std::endl;
//	}
//	if (IsBoss1Eliminated == true && IsBoss2Eliminated == true && IsBoss3Eliminated == true && ArtifactName == "OrcHammer")
//	{
//		//Player::SetAtk(플레이어객체이름, 2.0f);
//		std::cout << "You got a OrcHammer. Your Attack Damage has been multipled." << std::endl;
//	}
//	else
//	{
//		return;
//	}
//}



// Global Variation
// 플레이어가 보스1을 죽이고 보스3 보상을 얻지 못하게 만든 안전장치입니다.
// 메인 함수에서 해당 보스 처치 시 true 혹은 0이 아닌 값으로 초기화 해주세요.
// bool IsBoss1Eliminated = 0;
// bool IsBoss2Eliminated = 0;
// bool IsBoss3Eliminated = 0;