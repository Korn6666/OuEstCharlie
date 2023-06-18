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
	activated = false;
	isCharlie = false;
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

	if (isCharlie) {
		if (gameManager.grid[m][n]->isAlive())
			gameManager.tempLivingCells.push_back(gameManager.allLivingCells[m][n].get());
		return;
	}

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
	}

	//cout << dump();

	activateNeighbours();
}

void LivingCell::draw(sf::RenderWindow& window) {
	sf::RectangleShape square(sf::Vector2f(squareSize, squareSize));
	if (frameAlive == 0) {
		frameAlive += 1;
		square.setFillColor(sf::Color::Blue);
	}else 	if (frameAlive == 1) {
		frameAlive += 1;
		square.setFillColor(sf::Color::Cyan);
	}else 	if (frameAlive == 2) {
		frameAlive += 1;
		square.setFillColor(sf::Color::Green);
	}else 	if (frameAlive == 3) {
		frameAlive += 1;
		square.setFillColor(sf::Color::Yellow);
	}else 	if (frameAlive == 4) {
		square.setFillColor(sf::Color::Red);
	}
	//square.setFillColor(sf::Color::White);
	square.setPosition(m * squareSize, n * squareSize);
	window.draw(square);
}


std::string LivingCell::dump() {
	string baseString = Cell::dump();
	ostringstream oss;
	oss << baseString;

	return oss.str();
}


