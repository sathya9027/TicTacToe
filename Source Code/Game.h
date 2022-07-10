#pragma once
#include <iostream>
#include "OutputDisplay.h"
#include "AIPath.h"
using namespace std;
class Game
{
private:
	int playerInput;
	OutputDisplay* outputDisplay;
	AIPath* aiPath;
public:
	Game();
	~Game();
	void Play();
	void ReplayGame();
	void PlayerInput();
};