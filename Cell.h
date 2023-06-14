#pragma once
#include <vector>

class Cell
{
protected:


	//Voisins
	std::vector<std::vector<Cell*>> neighbours;

	void InitializeNeighbours();
public:
	//Coordonnées de la Cell
	int m;
	int n;
	bool activated;

	virtual void action() = 0;

	virtual bool isAlive() const = 0;

	virtual void SetNeighbours();

	virtual int nbNeighbours();

	static float squareSize;
};

