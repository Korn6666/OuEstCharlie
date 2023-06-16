#include "GameManager.h"
#include "LivingCell.h"
#include "DeadCell.h"
#include <vector>
#include <iostream>

using namespace std;

//Déclaration du singleton
GameManager GameManager::instance;

void GameManager::SetLivingCell(int m, int n) {
	if (!(m < 100 - 3 && n < 100 - 3 && m > 3 && n > 3))
		return;
	LivingCell* cell = allLivingCells[m][n].get();
	//LivingCell* cell = new LivingCell(m, n);
	grid[m][n] = cell;
	//std::cout << "yap" << endl;
	livingCells.push_back(cell);
}

void GameManager::drawLivingCells(sf::RenderWindow& window) {
	for (auto const& cell : livingCells) {
		cell->draw(window);
	}
}

void GameManager::clearVectors(){

	//Clear la list dyingCell
	dyingCells.clear();
}

void GameManager::actionCells() {
	tempLivingCells.clear();
	int m;
	int n;

	//std::cout << "nb livingcells : " << livingCells.size() << "\n";

	for (auto const& cell : livingCells) {
		m = cell->m;
		n = cell->n;
		allLivingCells[m][n]->action();
	}
	livingCells = tempLivingCells;
}

void GameManager::majVectors() 
{
	int m;
	int n;

	//add the dyingCells to grid
	for (auto const& cell : dyingCells) {
		m = cell->m;
		n = cell->n;
		if (grid[m][n]->isAlive())
		{
			allLivingCells[m][n]->isDying = false;
			allLivingCells[m][n]->activated = false;
			allLivingCells[m][n]->frameAlive = 0;
			grid[m][n] = allDeadCells[m][n].get();
		}
	}


	//add the tempLivingCells to grid
	for (auto& cell : livingCells) {
		m = cell->m;
		n = cell->n;

		allLivingCells[m][n]->isDying = false;
		allLivingCells[m][n]->activated = false;

		if ( m < grid.size() - 3 && n < grid.size() - 3 && m > 3 && n > 3 && !grid[m][n]->isAlive())
			grid[m][n] = allLivingCells[m][n].get();
	}

	// desactivate the deadcells
	for (auto const& cell : deadActivatedCells) {
		m = cell->m;
		n = cell->n;
		allDeadCells[m][n]->activated = false;
	}
}

