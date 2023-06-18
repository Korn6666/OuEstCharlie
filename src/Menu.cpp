#include "Menu.h"

Menu::Menu(float width, float height) {

	if (!font.loadFromFile("resources/arial.ttf"))
	{
		//error
	}

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Blue);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MENU_TAB + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Settings");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MENU_TAB + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MENU_TAB + 1) * 3));

	endMenu.setFont(font);
	endMenu.setFillColor(sf::Color::Green);
	endMenu.setString("Vous avez trouvé Charlie !");
	endMenu.setPosition(sf::Vector2f(width / 4, height / 2));


	selected = 0;
	stateValue = "menu";
}



void Menu::Draw(sf::RenderWindow& window) {

	for (int i = 0; i < MENU_TAB; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::DrawEnd(sf::RenderWindow& window) {

	window.draw(endMenu);
}


void Menu::MoveUp() {

	if (selected - 1 >= 0)
	{
		menu[selected].setFillColor(sf::Color::White);
		selected--;
		menu[selected].setFillColor(sf::Color::Blue);
		std::cout << "trigger UP" << std::endl;
	}
}


void Menu::MoveDown() {

	if (selected + 1 < MENU_TAB)
	{
		menu[selected].setFillColor(sf::Color::White);
		selected++;
		menu[selected].setFillColor(sf::Color::Blue);
		std::cout << "trigger DOWN" << std::endl;
	}
}


void Menu::OnClick() {
	switch (selected)
	{
	case 0:
		std::cout << "Play" << std::endl;
		//call la fonction d'affichage de la grille
		stateValue = "game";
		break;

	case 1:
		std::cout << "Settings" << std::endl;
		break;

	case 2:
		std::cout << "Exit" << std::endl;
		stateValue = "close";
		break;

	default:
		break;
	}
}


void Menu::EndSelecteur(std::string value) {
	if (value == "victoire")
	{
		endMenu.setFillColor(sf::Color::Green);
		endMenu.setString("Vous avez trouvé Charlie !");
	} 
	else if (value == "defaite") 
	{
		endMenu.setFillColor(sf::Color::Red);
		endMenu.setString("Vous n'avez pas trouvé Charlie...");
	}

	stateValue = "end";
}
