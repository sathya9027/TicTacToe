#pragma once
#include <iostream>
using namespace std;
class AIPath
{
private:
	string output;
	string row1, row2, row3;
	string column1, column2, column3;
	string diag1, diag2;
	string pos1, pos2, pos3;
	string pos4, pos5, pos6;
	string pos7, pos8, pos9;
public:
	bool IsWon = true;
	bool IsInputError = false;
	AIPath();
	~AIPath();
	void UpdateGame();
	void GetAIOutput(int aiOutput);
	void AssignPlayerPosition(int playerPosition);
	string UpdateBoard();
	void CheckWinningCondition();
	void GetPlayerInput(int playerInput);
	void ResetGame();
};

