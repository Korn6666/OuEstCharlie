#include "DeadCell.h"
#include "LivingCell.h"
#include "GameManager.h"
#include <iostream>
#include <memory>

using namespace std;

DeadCell::DeadCell(int _m, int _n) {
	m = _m;
	n = _n;
	activated = false;
	isCharlie = false;
	InitializeNeighbours();
}

void DeadCell::action() {
	if (isCharlie)
		return;
	if (activated) {
		return;
	}
	else {
		activated = true;
	}
	SetNeighbours();

	GameManager& gameManager = GameManager::getInstance();
	if (nbNeighbours() == 3) {
		LivingCell* cell = gameManager.allLivingCells[m][n].get();
		//LivingCell* cell = new LivingCell(m, n);
		gameManager.tempLivingCells.push_back(cell);
		//cout << dump();
	}
	
	gameManager.deadActivatedCells.push_back(gameManager.allDeadCells[m][n].get());
	
}
