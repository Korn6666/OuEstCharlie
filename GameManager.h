#pragma once
#include <vector>
#include "Cell.h"
#include <memory>  

//class Cell;

class GameManager
{
public:
    //GameManager(const GameManager&) = delete;
    static GameManager& getInstance() {
        
        return instance;
    }

    std::vector<std::vector<Cell*>> grid;

    std::vector<Cell*> dyingCells;

    void SetLivingCell(int m, int n);
private:
    int size = 100;
    static GameManager instance;
    GameManager() {
        grid.resize(size, std::vector<Cell*>(size, nullptr));
    }

};
