#pragma once
#include <vector>
#include "Cell.h"
#include "DeadCell.h"
#include "LivingCell.h"
#include <memory>  
#include <SFML/Graphics.hpp>

//class Cell;

class GameManager
{
public:
    GameManager(const GameManager&) = delete;
    static GameManager& getInstance() {
        
        return instance;
    }

    std::vector<std::vector<Cell*>> grid;

    // dyingCells presents the livingCells who are going to die
    // Frame ends by removing the members of dyingCells from grid. It also replaces them by DeadCells
    std::vector<LivingCell*> dyingCells;

    // livingCells presents all the livingCells
    // Frame begins by calling the members of livingCells
    // Frame ends by adding the new members of livingCells 
    std::vector<LivingCell*> livingCells;

    std::vector<LivingCell*> tempLivingCells;

    std::vector<DeadCell*> deadActivatedCells;

    void SetLivingCell(int m, int n);

    void drawLivingCells(sf::RenderWindow& window);

    void clearVectors();

    void actionCells();

    void majVectors();


private:
    int size = 100;
    static GameManager instance;
    GameManager() {
        int numRows = size;
        int numCols = size;

        grid.resize(numRows);

        for (int i = 0; i < numRows; i++) {

            grid[i].resize(numCols);

            for (int j = 0; j < numCols; j++) {
                grid[i][j] = new DeadCell(i, j);
            }
        }
    }

};
