#include "Game.h"
Game::Game() {
	playerInput = NULL;
	outputDisplay = new OutputDisplay;
	aiPath = new AIPath;
}
Game::~Game() {
	delete outputDisplay;
	delete aiPath;
}
void Game::Play() {
	cout << "\tNOUGHTS AND CROSSES" << endl;
	this->PlayerInput();
}
void Game::PlayerInput() {
	int playerPositionInput;
	do
	{
		cout << "Enter the position to place (X/O) : ";cin >> playerPositionInput;
		playerInput = playerPositionInput;
		aiPath->AssignPlayerPosition(playerPositionInput);
		if (aiPath->IsInputError == true) {
			aiPath->IsInputError = false;
			this->PlayerInput();
			break;
		}
		if (aiPath->IsWon == false) {
			this->ReplayGame();
			break;
		}
		this->aiPath->GetPlayerInput(playerInput);
		cout << this->outputDisplay->PrintOutput(this->aiPath->UpdateBoard());
	}
	while (aiPath->IsWon);
}
void Game::ReplayGame() {
	char choice;
	cout << "Do You Want to play Again?(Y/N) : ";
	cin >> choice;
	if (choice == 'Y' || choice == 'y') {
		this->aiPath->ResetGame();
		this->Play();
	}
	else {
		cout << "\tThanks For Playing....";
		int input;
		cin >> input;
	}
}
