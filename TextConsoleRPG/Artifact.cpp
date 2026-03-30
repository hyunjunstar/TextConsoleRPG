// Artifact.cpp

#include "Artifact.h"
#include <iostream>
#include "Player.h"


void Artifact::chooseAndApply(Player& player, std::string ArtifactName)
 {
     if (ArtifactName == "SlimeJuice")
     {
         Player::AddAtk(player, 5);//*3.30김남윤 수정, 사유:함수명 변경
         std::cout << "[Item Acquired] You drank 'SlimeJuice'. Base ATK increased by 5!" << std::endl;
     }
     else if (ArtifactName == "GoblinTotem")
     {
         Player::SetCrit(player, 20);
         std::cout << "[Item Acquired] You found 'GoblinTotem'. Crit Chance increased by 20%!" << std::endl;
     }
     else if (ArtifactName == "OrcHammer")
     {
         Player::MultiplyDamage(player, 1.5f);//*3.30김남윤 수정, 사유: 함수명 변경
         std::cout << "[Legendary Item] You acquired 'OrcHammer'. DMG Multiplier is now 1.5x!" << std::endl;
     }
 }