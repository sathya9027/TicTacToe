#include "AIPath.h"
#include <iostream>
#include <string>
using namespace std;
AIPath::AIPath() {
	pos1 = "-", pos2 = "-", pos3 = "-";
	pos4 = "-", pos5 = "-", pos6 = "-";
	pos7 = "-", pos8 = "-", pos9 = "-";
}
AIPath::~AIPath() {
}
void AIPath::GetPlayerInput(int playerInput) {
	int aiInput = 0;
	switch (playerInput)
	{
	case 1:
		if (pos2 == "X" || pos2 == "O") {
			if (pos4 == "X" || pos4 == "O") {
				if (pos5 == "X" || pos5 == "O") {
					aiInput = 3;
				}
				else {
					aiInput = 5;
				}
			}
			else {
				aiInput = 4;
			}
		}
		else {
			aiInput = 2;
		}
		break;
	case 2:
		if (pos3 == "X" || pos3 == "O") {
			if (pos6 == "X" || pos6 == "O") {
				if (pos4 == "X" || pos4 == "O") {
					aiInput = 5;
				}
				else {
					aiInput = 4;
				}
			}
			else {
				aiInput = 6;
			}
		}
		else if(pos1 != "X" || pos1 != "O") {
			aiInput = 1;
		}
		else {
			aiInput = 3;
		}
		break;
	case 3:
		if (pos2 == "X" || pos2 == "O") {
			if (pos5 == "X" || pos5 == "O") {
				if (pos1 == "X" || pos1 == "O") {
				}
				else {
					aiInput = 1;
				}
			}
			else {
				aiInput = 5;
			}
		}
		else {
			aiInput = 2;
		}
		break;
	case 4:
		if (pos7 != "-") {
			if (pos5 != "-") {
				if (pos2 != "-") {
					aiInput = 1;
				}
				else {
					aiInput = 2;
				}
			}
			else {
				aiInput = 5;
			}
		}
		else if (pos7 == "-") {
			aiInput = 7;
		}
		else {
			aiInput = 8;
		}
		break;
	case 5:
		if (pos1 == "X" || pos1 == "O") {
			if (pos2 == "X" || pos2 == "O") {
				aiInput = 6;
			}
			else {
				if (pos1 == "X" || pos1 == "O") {
					aiInput = 2;
				}
				else {
					aiInput = 9;
				}
			}
		}
		else if (pos1 != "X" || pos1 != "O") {
			aiInput = 1;
		}
		else {
			if (pos3 == "X" || pos3 == "O") {
				if (pos4 == "X" || pos4 == "O") {
					aiInput = 7;
				}
				else {
					if (pos8 == "X" || pos8 == "O") {
						aiInput = 4;
					}
					else {
						aiInput = 8;
					}
				}
			}
			else {
				aiInput = 3;
			}
		}
		break;
	case 6:
		if (pos3 != "-") {
			if (pos5 != "-") {
				if (pos2 != "-") {
					aiInput = 9;
				}
				else {
					aiInput = 2;
				}
			}
			else {
				aiInput = 5;
			}
		}
		else if (pos8 == "-") {
			aiInput = 8;
		}
		else {
			aiInput = 3;
		}
		break;
	case 7:
		if (pos8 == "X" || pos8 == "O") {
			if (pos4 == "X" || pos4 == "O") {
				if (pos5 == "X" || pos5 == "O") {
					aiInput = 9;
				}
				else {
					aiInput = 5;
				}
			}
			else {
				aiInput = 4;
			}
		}
		else {
			aiInput = 8;
		}
		break;
	case 8:
		if (pos9 != "-") {
			if (pos5 != "-") {
				if (pos7 != "-") {
					aiInput = 6;
				}
				else {
					aiInput = 7;
				}
			}
			else {
				aiInput = 5;
			}
		}
		else if (pos4 == "-") {
			aiInput = 4;
		}
		else {
			aiInput = 9;
		}
		break;
	case 9:
		if (pos8 == "X" || pos8 == "O") {
			if (pos6 == "X" || pos6 == "O") {
				if (pos5 == "X" || pos5 == "O") {
					aiInput = 1;
				}
				else {
					aiInput = 5;
				}
			}
			else {
				aiInput = 6;
			}
		}
		else {
			aiInput = 8;
		}
		break;
	default:
		cout << "Invalid Output" << endl;
		break;
	}
	this->GetAIOutput(aiInput);
}
void AIPath::UpdateGame() {
	row1 = pos1 + pos2 + pos3;
	row2 = pos4 + pos5 + pos6;
	row3 = pos7 + pos8 + pos9;
	column1 = pos1 + pos4 + pos7;
	column2 = pos2 + pos5 + pos8;
	column3 = pos3 + pos6 + pos9;
	diag1 = pos1 + pos5 + pos9;
	diag2 = pos3 + pos5 + pos7;
	this->CheckWinningCondition();
}
void AIPath::GetAIOutput(int aiOutput) {
	switch (aiOutput)
	{
	case 1:
		pos1 = "O";
		break;
	case 2:
		pos2 = "O";
		break;
	case 3:
		pos3 = "O";
		break;
	case 4:
		pos4 = "O";
		break;
	case 5:
		pos5 = "O";
		break;
	case 6:
		pos6 = "O";
		break;
	case 7:
		pos7 = "O";
		break;
	case 8:
		pos8 = "O";
		break;
	case 9:
		pos9 = "O";
		break;
	default:
		cout << "Invalid Output" << endl;
		break;
	}
	this->UpdateGame();
}
void AIPath::AssignPlayerPosition(int playerPosition) {
	switch (playerPosition)
	{
	case 1:
		if (pos1 != "-") {
			cout << "Position " + to_string(playerPosition) + " has been ocupied. Try Again...." << endl;
			IsInputError = true;
			break;
		}
		pos1 = "X";
		break;
	case 2:
		if (pos2 != "-") {
			cout << "Position " + to_string(playerPosition) + " has been ocupied. Try Again...." << endl;
			IsInputError = true;
			break;
		}
		pos2 = "X";
		break;
	case 3:
		if (pos3 != "-") {
			cout << "Position " + to_string(playerPosition) + " has been ocupied. Try Again...." << endl;
			IsInputError = true;
			break;
		}
		pos3 = "X";
		break;
	case 4:
		if (pos4 != "-") {
			cout << "Position " + to_string(playerPosition) + " has been ocupied. Try Again...." << endl;
			IsInputError = true;
			break;
		}
		pos4 = "X";
		break;
	case 5:
		if (pos5 != "-") {
			cout << "Position " + to_string(playerPosition) + " has been ocupied. Try Again...." << endl;
			IsInputError = true;
			break;
		}
		pos5 = "X";
		break;
	case 6:
		if (pos6 != "-") {
			cout << "Position " + to_string(playerPosition) + " has been ocupied. Try Again...." << endl;
			IsInputError = true;
			break;
		}
		pos6 = "X";
		break;
	case 7:
		if (pos7 != "-") {
			cout << "Position " + to_string(playerPosition) + " has been ocupied. Try Again...." << endl;
			IsInputError = true;
			break;
		}
		pos7 = "X";
		break;
	case 8:
		if (pos8 != "-") {
			cout << "Position " + to_string(playerPosition) + " has been ocupied. Try Again...." << endl;
			IsInputError = true;
			break;
		}
		pos8 = "X";
		break;
	case 9:
		if (pos9 != "-") {
			cout << "Position " + to_string(playerPosition) + " has been ocupied. Try Again...." << endl;
			IsInputError = true;
			break;
		}
		pos9 = "X";
		break;
	default:
		cout << "Invalid Output" << endl;
		break;
	}
	this->UpdateGame();
}
string AIPath::UpdateBoard() {
	output = "\t      " + pos1 + " | " + pos2 + " | " + pos3 + "\n";
	output += "\t     -----------\n";
	output += "\t      " + pos4 + " | " + pos5 + " | " + pos6 + "\n";
	output += "\t     -----------\n";
	output += "\t      " + pos7 + " | " + pos8 + " | " + pos9 + "\n";
	return output;
}
void AIPath::CheckWinningCondition() {
	if ((row1 == "XXX") || (row2 == "XXX") || (row3 == "XXX")) {
		cout << "\tYou won the game!!!!" << endl;
		cout << UpdateBoard();
		IsWon = false;
	}
	else if ((column1 == "XXX") || (column2 == "XXX") || (column3 == "XXX")) {
		cout << "\tYou won the game!!!!" << endl;
		cout << UpdateBoard();
		IsWon = false;
	}
	else if ((diag1 == "XXX") || (diag2 == "XXX")) {
		cout << "\tYou won the game!!!!" << endl;
		cout << UpdateBoard();
		IsWon = false;
	}
	else if ((row1 == "OOO") || (row2 == "OOO") || (row3 == "OOO")) {
		cout << "\tYou lost the game!!!!" << endl;
		cout << UpdateBoard();
		IsWon = false;
	}
	else if ((column1 == "OOO") || (column2 == "OOO") || (column3 == "OOO")) {
		cout << "\tYou lost the game!!!!" << endl;
		cout << UpdateBoard();
		IsWon = false;
	}
	else if ((diag1 == "OOO") || (diag2 == "OOO")) {
		cout << "\tYou lost the game!!!!" << endl;
		cout << UpdateBoard();
		IsWon = false;
	}
	else if ((pos1 != "-") && (pos2 != "-") && (pos3 != "-") && (pos4 != "-") && (pos5 != "-") && (pos6 != "-") && (pos7 != "-") && (pos8 != "-") && (pos9 != "-")) {
		cout << "\tYou tie the game!!!!" << endl;
		IsWon = false;
	}
}
void AIPath::ResetGame() {
	pos1 = "-", pos2 = "-", pos3 = "-";
	pos4 = "-", pos5 = "-", pos6 = "-";
	pos7 = "-", pos8 = "-", pos9 = "-";
	row1 = pos1 + pos2 + pos3;
	row2 = pos4 + pos5 + pos6;
	row3 = pos7 + pos8 + pos9;
	column1 = pos1 + pos4 + pos7;
	column2 = pos2 + pos5 + pos8;
	column3 = pos3 + pos6 + pos9;
	diag1 = pos1 + pos5 + pos9;
	diag2 = pos3 + pos5 + pos7;
	IsWon = true;
	IsInputError = false;
}