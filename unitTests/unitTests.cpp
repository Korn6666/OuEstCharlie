#include <gtest/gtest.h>
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameManager.h"
#include "Menu.h"

//On test le fonctionnement du menu
TEST(MenuTest, TestTextMenu) {
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "OU EST CHARLIE !");
    Menu menu(window.getSize().x, window.getSize().y);

    menu.MoveUp();
    menu.OnClick();
    EXPECT_EQ(menu.stateValue, "game");

    menu.MoveDown();
    menu.MoveDown();
    menu.MoveDown();
    menu.OnClick();
    EXPECT_EQ(menu.stateValue, "close");
}

//On test la re generation de la grille
TEST(GameManagerTest, GridGenTest) {
    GameManager& gameManager = GameManager::getInstance();
    gameManager.livingCells.clear();
    EXPECT_TRUE(gameManager.livingCells.size() == 0);

    gameManager.ResetGameManager();
    std::cout << "nombre de living cells : " << gameManager.livingCells.size() << std::endl;
    EXPECT_TRUE(gameManager.livingCells.size() > 0);
}
