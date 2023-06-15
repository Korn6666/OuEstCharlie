#include "GameManager.h"
#include "LivingCell.h"
#include "DeadCell.h"
#include <vector>
#include <iostream>

using namespace std;

//Déclaration du singleton
GameManager GameManager::instance;

void GameManager::SetLivingCell(int m, int n) {
	LivingCell* cell = new LivingCell(m, n);
	grid[m][n] = cell;
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
	for (auto const& cell : livingCells) {
		cell->action();
	}
}

void GameManager::majVectors() 
{
	int m;
	int n;
	livingCells = tempLivingCells;

	//add the dyingCells to grid
	for (auto const& cell : dyingCells) {
		m = cell->m;
		n = cell->n;

		if (grid[m][n]->isAlive())
		{
			DeadCell* deadCell = new DeadCell(m, n);
			grid[m][n] = deadCell;
		}
	}

	//add the livingCells to grid
	for (auto const& cell : livingCells) {
		m = cell->m;
		n = cell->n;


		cell->isDying = false;
		cell->activated = false;

		if ( m < grid.size() - 3 && n < grid.size() - 3 && m > 3 && n > 3 && !grid[m][n]->isAlive())
			grid[m][n] = cell;  
	}
	  
	//std::cout << "nb livingcells : " << livingCells.size() << "\n";
	// desactivate the deadcells
	for (auto const& cell : deadActivatedCells) {
		cell->activated = false;
	}
}

