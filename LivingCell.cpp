#include "LivingCell.h"
#include "DeadCell.h"
#include "GameManager.h"

LivingCell::LivingCell(int _m, int _n) {
	m = _m;
	n = _n;
	isDying = false;
}


void LivingCell::action() {
	GameManager& gameManager = GameManager::getInstance();
	if (nbNeighbours() == 2 || nbNeighbours() == 3) {
		return;
	}
	else {
		gameManager.grid[m][n] = new DeadCell(m, n);
	}
}

