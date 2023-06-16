#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "LivingCell.h"
#include "GameManager.h"
#include <iostream>
#include <windows.h>

using namespace std;

void testSFML() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}

int main()
{
    GameManager& gameManager = GameManager::getInstance();
    string inputFinished;
    int x;
    int y;
    std::cout << "Rentrez les coordonnées de la cellule vivante. Répondez par 'y' ou pas 'n': \n";
    std::cin >> inputFinished;

    while (inputFinished == "y") {
        std::cout << "Rentrez les coordonnées de la cellule vivante v\n";
        std::cout << "x: ";
        std::cin >> x;
        std::cout << "y: ";
        std::cin >> y;

        gameManager.SetLivingCell(x, y);
        std::cout << "Une cellule vivante est initialisé. Voulez vous en créer une autre. Répondez par 'y' ou pas 'n': ";
        std::cin >> inputFinished;
        
        while (inputFinished != "y" && inputFinished != "n") {
            std::cout << "Répondez par 'y' pour YES ou par 'n' pour NON: ";
            std::cin >> inputFinished;
        }
    }

    //Clignotant
    //gameManager.SetLivingCell(10, 10);
    //gameManager.SetLivingCell(11, 10);
    //gameManager.SetLivingCell(12, 10);

    //Grenouille
    //gameManager.SetLivingCell(10, 10);
    //gameManager.SetLivingCell(11, 10);
    //gameManager.SetLivingCell(12, 10);
    //gameManager.SetLivingCell(11, 9);
    //gameManager.SetLivingCell(12, 9);
    //gameManager.SetLivingCell(13, 9);

    ////Vaisseau en haut à gauche
    gameManager.SetLivingCell(10, 10);
    gameManager.SetLivingCell(11, 10);
    gameManager.SetLivingCell(12, 10);
    gameManager.SetLivingCell(12, 9);
    gameManager.SetLivingCell(11, 8);

    ////Vaisseau en haut à droite
    gameManager.SetLivingCell(90, 10);
    gameManager.SetLivingCell(89, 10);
    gameManager.SetLivingCell(88, 10);
    gameManager.SetLivingCell(88, 9);
    gameManager.SetLivingCell(89, 8);

    ////Vaisseau en bas à droite
    gameManager.SetLivingCell(90, 90);
    gameManager.SetLivingCell(89, 90);
    gameManager.SetLivingCell(88, 90);
    gameManager.SetLivingCell(88, 89);
    gameManager.SetLivingCell(89, 88);

    //Test bordure
    //gameManager.SetLivingCell(99, 99);


    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    window.clear(sf::Color::Black);
    std::srand(std::time(nullptr));
    int xaC = rand() % 80 + 10;
    int yaC = rand() % 50 + 25;
    gameManager.SetCharlie(xaC, yaC);
    int compteur = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        
        gameManager.drawLivingCells(window);
        gameManager.clearVectors();
        gameManager.actionCells();
        gameManager.majVectors();
        window.display();

        compteur += 1;
        if (compteur == 100) {
            compteur = 0;
            //////Vaisseau en haut à gauche
            //gameManager.SetLivingCell(10, 10);
            //gameManager.SetLivingCell(11, 10);
            //gameManager.SetLivingCell(12, 10);
            //gameManager.SetLivingCell(12, 9);
            //gameManager.SetLivingCell(11, 8);

            //////Vaisseau en haut à droite
            //gameManager.SetLivingCell(90, 10);
            //gameManager.SetLivingCell(89, 10);
            //gameManager.SetLivingCell(88, 10);
            //gameManager.SetLivingCell(88, 9);
            //gameManager.SetLivingCell(89, 8);

            //////Vaisseau en bas à droite
            //gameManager.SetLivingCell(90, 90);
            //gameManager.SetLivingCell(89, 90);
            //gameManager.SetLivingCell(88, 90);
            //gameManager.SetLivingCell(88, 91);
            //gameManager.SetLivingCell(89, 92);

            //////Vaisseau en bas à gauche
            //gameManager.SetLivingCell(10, 90);
            //gameManager.SetLivingCell(11, 90);
            //gameManager.SetLivingCell(12, 90);
            //gameManager.SetLivingCell(12, 91);
            //gameManager.SetLivingCell(11, 92);

            
        }
        //Sleep(50);
        //std::cout << "new Frame \n";
    }
    


    //testSFML();
    return 0;

}

