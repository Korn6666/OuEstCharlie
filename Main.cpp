#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "LivingCell.h"
#include "GameManager.h"
#include <iostream>

using namespace std;

/*void testSFML() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

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
}*/

int main()
{
    GameManager gameManager = GameManager::getInstance();
    string inputFinished = "y";
    int x;
    int y;
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

    //testSFML();
    return 0;

}

