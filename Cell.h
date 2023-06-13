#pragma once
#include <vector>

class Cell
{
protected:
	//Coordonnées de la Cell
	int m;
	int n;
	bool isDying = false;

	//Voisins
	std::vector<std::vector<Cell*>> neighbours;
public:
	virtual void action();

	virtual bool isAlive();

	virtual void SetNeighbours();

	virtual int nbNeighbours();

};

