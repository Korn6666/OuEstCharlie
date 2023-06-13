#pragma once
#include "Cell.h"

class GameManager;


class LivingCell : public Cell
{
public:
	LivingCell(int _m, int _n);
	void action() override;
	bool isAlive() const{
		return true;
	}
};

