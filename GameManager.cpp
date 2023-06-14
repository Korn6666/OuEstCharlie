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
	for (auto const& cell : dyingCells) {
		m = cell->m;
		n = cell->n;
		DeadCell* deadCell = new DeadCell(m, n);
		grid[m][n] = deadCell;
	}
	//delete from livingCells and grid by isDying
	for (auto it = livingCells.rbegin(); it != livingCells.rend(); ) {
		LivingCell* cell = *it;

		if (cell->isDying) {
			m = cell->m;
			n = cell->n;
			// delete from grid and replace by a deadcell
			//DeadCell* deadCell = new DeadCell(m, n);
			//grid[m][n] = deadCell;
			// delete from livingCells
			delete *it;
			it = std::vector<LivingCell*>::reverse_iterator(livingCells.erase(std::next(it).base()));
		}
		else {
			++it;
		}
	}

	//add from livingCells to grid
	for (auto const& cell : livingCells) {
		m = cell->m;
		n = cell->n;
		LivingCell* livingCell = new LivingCell(m, n);
		livingCell->activated = false;
		grid[m][n] = livingCell;
	}

	for (auto const& cell : deadActivatedCells) {
		cell->activated = false;
	}
}

