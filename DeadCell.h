#pragma once
#include "Cell.h"

class GameManager;

class DeadCell : public Cell
{
public:
	DeadCell(int _m, int _n);
	void action();
	bool isAlive() const{
		return false;
	}
};

