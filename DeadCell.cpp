#include "DeadCell.h"
#include "LivingCell.h"
#include "GameManager.h"


DeadCell::DeadCell(int _m, int _n) {
	m = _m;
	n = _n;
}

void DeadCell::action() {
	GameManager& gameManager = GameManager::getInstance();
	if (nbNeighbours() == 3) {
		gameManager.grid[m][n] = new LivingCell(m, n);
	}
	gameManager.dyingCells.push_back(this);
}
