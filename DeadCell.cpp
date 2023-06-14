#include "DeadCell.h"
#include "LivingCell.h"
#include "GameManager.h"
#include <iostream>


DeadCell::DeadCell(int _m, int _n) {
	m = _m;
	n = _n;
	activated = false;
	InitializeNeighbours();
}

void DeadCell::action() {
	if (activated) {
		return;
	}
	else {
		activated = true;
	}
	SetNeighbours();

	GameManager& gameManager = GameManager::getInstance();
	if (nbNeighbours() == 3) {
		LivingCell* cell = new LivingCell(m, n);
		gameManager.tempLivingCells.push_back(cell);
	}
	else {
		gameManager.deadActivatedCells.push_back(this);
	}
}
