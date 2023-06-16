#include "LivingCell.h"
#include "DeadCell.h"
#include "GameManager.h"
#include <iostream>
#include <sstream>

using namespace std;

LivingCell::LivingCell(int _m, int _n) {
	m = _m;
	n = _n;
	GameManager& gameManager = GameManager::getInstance();
	isDying = false;
	activated = false;
	InitializeNeighbours();
}

void LivingCell::activateNeighbours() {
	GameManager& gameManager = GameManager::getInstance();

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if ((i != 1 || j != 1)){
				//std::cout << "activate neighbour from " << m << " " << n << "\n";
				neighbours[i][j]->action();
			}
		}
	}
}

void LivingCell::action() {
	if (activated) {
		return;
	}
	else {
		activated = true;
	}

	SetNeighbours();
	GameManager& gameManager = GameManager::getInstance();

	//std::cout << "nb neighbours of " << m << " " << n << " " << nbNeighbours() << "\n";
	//std::cout << "neighbours" << m << " " << n << "\n";
	int nbNeigboursInt = nbNeighbours();
	int i = this->m;
	int j = this->n;
	if (nbNeigboursInt == 2 || nbNeigboursInt == 3) {
		gameManager.tempLivingCells.push_back(gameManager.allLivingCells[i][j].get());
		
	}
	else {
		//to delete from grid
		gameManager.dyingCells.push_back(gameManager.allLivingCells[i][j].get());
		//to delete from livingCells
		isDying = true;
	}

	//cout << dump();

	activateNeighbours();
}

void LivingCell::draw(sf::RenderWindow& window) {
	sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
	square.setFillColor(sf::Color::Black);
	square.setPosition(m * squareSize, n * squareSize);
	window.draw(square);
}


std::string LivingCell::dump() {
	string baseString = Cell::dump();
	ostringstream oss;
	oss << baseString;
	oss << "isDying: " << isDying << endl << endl;

	return oss.str();
}


