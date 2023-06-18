#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#define MENU_TAB 3

class Menu
{
public:
	Menu(float width, float height);

	std::string stateValue;

	void Draw(sf::RenderWindow& window);
	void DrawEnd(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	void OnClick();

	void EndSelecteur(std::string value);

private:
	int selected;
	sf::Font font;
	sf::Text menu[MENU_TAB];
	sf::Text endMenu;


};

