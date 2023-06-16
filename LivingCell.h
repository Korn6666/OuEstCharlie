#pragma once
#include <SFML/Graphics.hpp>
#include "Cell.h"


class GameManager;


class LivingCell : public Cell
{
public:
	bool isDying = false;

	LivingCell(int _m, int _n);

	void action();

	bool isAlive() const{
		return true;
	}

	void draw(sf::RenderWindow& window);

	std::string dump();

	int frameAlive = 0;

private:
	void activateNeighbours();

};

