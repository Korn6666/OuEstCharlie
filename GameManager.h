#pragma once
#include <vector>
#include "Cell.h"
#include "DeadCell.h"
#include "LivingCell.h"
#include <memory>  
#include <SFML/Graphics.hpp>
#include <iostream>

//class Cell;

class GameManager
{
public:
    GameManager(const GameManager&) = delete;
    static GameManager& getInstance() {
        return instance;
    }

    //All possible living cells
    std::vector<std::vector<std::unique_ptr<LivingCell>>> allLivingCells;
    //All possible dead cells
    std::vector<std::vector<std::unique_ptr<DeadCell>>> allDeadCells;

    // Grid with all the LivingCells and DeadCells
    std::vector<std::vector<Cell*>> grid;

    // dyingCells presents the livingCells who are going to die
    // Frame ends by remplacing the members of dyingCells by DeadCells in the grid
    std::vector<LivingCell*> dyingCells;

    // livingCells presents all the livingCells at the beginning of the frame and at the end
    // Frame begins by calling the members of livingCells to draw and to action the cells
    // Frame ends by livingCells = tempLivingCells to maj the living cells
    std::vector<LivingCell*> livingCells;

    // tempLivingCells represents the livingCells from the current actions of the cells
    std::vector<LivingCell*> tempLivingCells;

    // All the deadCells who need to have activated = false for the next frame
    std::vector<DeadCell*> deadActivatedCells;

    void SetLivingCell(int m, int n);

    void drawLivingCells(sf::RenderWindow& window);

    void clearVectors();

    void actionCells();

    void majVectors();
    void SetCharlie(int m, int n);
    void SetCharlieLivingCell(int i, int j);
    void SetCharlieDeadCell(int i, int j);


private:
    int size = 100;
    int randint = 1;
    static GameManager instance;

    GameManager() {
        int numRows = size;
        int numCols = size;

        grid.resize(numRows);
        allLivingCells.resize(numRows);
        allDeadCells.resize(numRows);


        for (int i = 0; i < numRows; i++) {

            grid[i].resize(numCols);
            allLivingCells[i].resize(numCols);
            allDeadCells[i].resize(numCols);

            for (int j = 0; j < numCols; j++) {

                allLivingCells[i][j] = std::make_unique<LivingCell>(i, j);
                allDeadCells[i][j] = std::make_unique<DeadCell>(i, j);
                grid[i][j] = allDeadCells[i][j].get();
                grid[i][j] = allDeadCells[i][j].get();
                randint = rand() % 100;
                if (randint > 30)
                {
                    //grid[i][j] = allDeadCells[i][j].get();
                }
                else {
                    SetLivingCell(i, j);
                }
            }
        }
        SetLivingCell(50, 50);
    }

};
