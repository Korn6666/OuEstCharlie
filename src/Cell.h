#pragma once
#include <vector>
#include <memory>
#include <string>

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

	bool isCharlie;

	virtual void action() = 0;

	virtual bool isAlive() const = 0;

	virtual void SetNeighbours();

	virtual int nbNeighbours();

	static float squareSize;

	virtual std::string dump();
};

