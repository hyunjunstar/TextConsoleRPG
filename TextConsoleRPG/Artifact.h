// Artifact.h

#pragma once
#include <string>

class Player;

class Artifact
{
public:
	void chooseAndApply(Player& player, std::string ArtifactName);
};
