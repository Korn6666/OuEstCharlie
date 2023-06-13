#include "GameManager.h"
#include "LivingCell.h"
#include <vector>

using namespace std;

void GameManager::SetLivingCell(int m, int n) {
	LivingCell cell(m, n);
	grid[m][n] = new LivingCell(m,n);
}

GameManager GameManager::instance;

