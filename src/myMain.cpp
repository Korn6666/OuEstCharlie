#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "LivingCell.h"
#include "GameManager.h"
#include "Menu.h"
#include <iostream>
#include <windows.h>


using namespace std;

GameManager& gameManager = GameManager::getInstance();


//fct qui genere une grille de jeu aléatoirement 
void gameGenerate(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);
    gameManager.ResetGameManager();
    std::srand(std::time(nullptr));
    gameManager.SetCharlie();
}

int myMain()
{
    string inputFinished;
    int compteur = 0;

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


    sf::RenderWindow window(sf::VideoMode(1000, 1000), "OU EST CHARLIE !");
 

    sf::Vector2i mousePosition = sf::Mouse::getPosition(window); //Position de la mouse
    Menu menu(window.getSize().x, window.getSize().y);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                std::cout << "trigger" << std::endl;
                window.close();
                break;

            case sf::Event::KeyPressed:
                switch (event.key.code) //liste des input clavier détecté 
                {
                case sf::Keyboard::Up:
                    std::cout << "Only UP" << std::endl;
                    menu.MoveUp();
                    break;

                case sf::Keyboard::Down:
                    std::cout << "DOWN" << std::endl;
                    menu.MoveDown();
                    break;

                    // Ajoutez d'autres cas ici pour d'autres touches si nécessaire


                case sf::Keyboard::Enter:
                    std::cout << "ENTER" << std::endl;

                    if (menu.stateValue == "menu")
                    {
                        menu.OnClick();
                        if (menu.stateValue == "game") {
                            gameGenerate(window); //genere la grille du jeu
                        }
                    }      
                    break;

                case sf::Keyboard::Escape:
                    std::cout << "ECHAP" << std::endl;
                    menu.stateValue = "menu";
                    break;

                default:
                    break;
                }
                break;

            case sf::Event::MouseButtonPressed: //Si le joueur utilise le click gauche de la souris
                std::cout << "MOUSE" << std::endl;
                switch (event.mouseButton.button)
                {
                case sf::Mouse::Left:
                    std::cout << "CLICK" << std::endl;
                    mousePosition = sf::Mouse::getPosition(window);

                    if (menu.stateValue == "game") //Si le joueur clique pendant le jeu
                    {
                        //condition pour trouver charlie
                        std::cout << "xac" << gameManager.xaC << "xpos" << mousePosition.x << std::endl;
                        std::cout << "yac" << gameManager.yaC << "ypos" << mousePosition.y << std::endl;
                        if ((mousePosition.x > gameManager.xaC * 10 - 50) && (mousePosition.x < gameManager.xaC * 10 + 50) && (mousePosition.y > gameManager.yaC * 10 - 50) && (mousePosition.y < gameManager.yaC * 10 + 50))
                        {
                            std::cout << "GG" << std::endl;
                            menu.EndSelecteur("victoire");
                        }
                        else
                        {
                            menu.EndSelecteur("defaite");
                        }
                    }
                    else if (menu.stateValue == "end") //si le joueur clique pendant le message de victoire
                    {
                        menu.stateValue = "menu"; //on retourne au menu
                    }
                    
                    break;
                default:
                    break;
                }

            default:
                break;
            }
        }

        window.clear(sf::Color::Black);
        if (menu.stateValue == "menu") {
            menu.Draw(window);
        }
        else if (menu.stateValue == "game") {

            gameManager.drawLivingCells(window);
            gameManager.clearVectors();
            gameManager.actionCells();
            gameManager.majVectors();

            compteur += 1;
            if (compteur == 100) {
                compteur = 0;
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
                gameManager.SetLivingCell(88, 91);
                gameManager.SetLivingCell(89, 92);

                ////Vaisseau en bas à gauche
                gameManager.SetLivingCell(10, 90);
                gameManager.SetLivingCell(11, 90);
                gameManager.SetLivingCell(12, 90);
                gameManager.SetLivingCell(12, 91);
                gameManager.SetLivingCell(11, 92);


            }
        }
        else if (menu.stateValue == "end") {
            menu.DrawEnd(window);
        }
        else if (menu.stateValue == "close") {
            window.close();
        }

        //Sleep(50);
        //std::cout << "new Frame \n";


        window.display();
    }



    //testSFML();
    return 0;

}

