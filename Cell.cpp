#include "Cell.h"
#include "GameManager.h"

void Cell::SetNeighbours() {

	GameManager& gameManager = GameManager::getInstance();

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i!=1 && j!=1)
				neighbours[i][j] = gameManager.grid[m + i][ n + j];
		}
	}
}

int Cell::nbNeighbours(){
	int count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != 1 && j != 1) {
				if (neighbours[i][j]->isAlive()) {
					count += 1;
				}
			}
		}
	}

	return count;
}

bool Cell::isAlive() {
	return false;
}

void Cell::action() {
	//RIEN
}
