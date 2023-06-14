#include "Cell.h"
#include "GameManager.h"
#include <iostream>
//Déclaration de la variable statique squareSize
float Cell::squareSize = 10;

void Cell::InitializeNeighbours() {
	neighbours.resize(9);
	for (int i = 0; i < 9; i++) {
		neighbours[i].resize(9);
		for (int j = 0; j < 9; j++) {
			neighbours[i][j] = nullptr;
		}
	}
}

void Cell::SetNeighbours() {
	GameManager& gameManager = GameManager::getInstance();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != 1 || j != 1) {
				//std::cout << "In Cell " << gameManager.grid[m + i -1][n + j - 1]->isAlive() << "\n";
				neighbours[i][j] = gameManager.grid[m+i-1][n+j-1];
			}
		}
	}
}

int Cell::nbNeighbours(){
	int count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != 1 || j != 1) {
				if (neighbours[i][j]->isAlive()) {
					count += 1;
				}

			}
		}
	}
	return count;
}



