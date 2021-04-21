#include <iostream>
#include <stdexcept> 
#include "Headers\Generation.hpp"
#include "Headers\Regle.hpp"
#include <SFML/Graphics.hpp>

// SFML : v2.5.1

const int POSITION = 30;
const float SIZE = 10.0f;
const float REFRESH_SPEED = 0.01f;

const bool GAMELIFE = true;
const bool HIGHLIFE = !GAMELIFE;

int main ()
{
	// Récupère les informations de la taille de l'écran (largeur, hauteur) et du nombre de bits par pixel
	sf::VideoMode mDesktop = sf::VideoMode (800, 600);
	sf::RenderWindow mWindow (mDesktop, "Automate cellulaire", sf::Style::Default);
	sf::WindowHandle handle = mWindow.getSystemHandle ();

	// Vue de l'animation du LifeGame
	sf::View viewAnimation (sf::FloatRect (0, 0, mWindow.getSize ().x*0.8f, mWindow.getSize ().y));
	viewAnimation.setViewport (sf::FloatRect (0.0f, 0.0f, 0.8f, 1.0f));

	sf::Texture textureBackgroundAnimation;
	
	sf::Image imageBackgroundAnimation;
	imageBackgroundAnimation.create (mWindow.getSize ().x, mWindow.getSize ().y, sf::Color::Green);
	textureBackgroundAnimation.loadFromImage (imageBackgroundAnimation);

	sf::Sprite spriteBackgroundAnimation;
	spriteBackgroundAnimation.setTexture (textureBackgroundAnimation);
	spriteBackgroundAnimation.setTextureRect (sf::IntRect (0, 0, mWindow.getSize ().x * 0.8f, mWindow.getSize ().y));
	spriteBackgroundAnimation.setPosition (sf::Vector2f(0, 0));

	// Ihm sur la droite de l'écran
	sf::View viewIHM (sf::FloatRect (mWindow.getSize ().x * 0.8f, 0, mWindow.getSize ().x, mWindow.getSize ().y));
	viewIHM.setViewport (sf::FloatRect (0.8f, 0.0f, 1.0f, 1.0f));

	sf::Texture textureBackgroundIHM;

	sf::Image imageBackgroundIhm;
	imageBackgroundIhm.create (mWindow.getSize ().x, mWindow.getSize ().y, sf::Color::Blue);
	textureBackgroundIHM.loadFromImage (imageBackgroundIhm);

	sf::Sprite spriteBackgroundIhm;
	spriteBackgroundIhm.setTexture (textureBackgroundIHM);
	spriteBackgroundIhm.setTextureRect (sf::IntRect (mWindow.getSize ().x * 0.8f, 0, mWindow.getSize ().x, mWindow.getSize ().y));
	spriteBackgroundIhm.setPosition (sf::Vector2f (0, 0));

	while (mWindow.isOpen ())
	{
		sf::Event event;
		while (mWindow.pollEvent (event))
		{
			if (event.type == sf::Event::Resized)
			{
				viewAnimation.reset (sf::FloatRect (0, 0, mWindow.getSize ().x * 0.8f, mWindow.getSize ().y));
				spriteBackgroundAnimation.setTextureRect (sf::IntRect (0, 0, mWindow.getSize ().x * 0.8f, mWindow.getSize ().y));
				spriteBackgroundAnimation.setPosition (sf::Vector2f (0, 0));

				viewIHM.reset (sf::FloatRect (mWindow.getSize ().x * 0.8f, 0, mWindow.getSize ().x, mWindow.getSize ().y));
				spriteBackgroundIhm.setTextureRect (sf::IntRect (mWindow.getSize ().x * 0.8f, 0, mWindow.getSize ().x, mWindow.getSize ().y));
				spriteBackgroundIhm.setPosition (sf::Vector2f (0, 0));
				
			}
			if (event.type == sf::Event::Closed)
				mWindow.close ();

			if (sf::Keyboard::isKeyPressed (sf::Keyboard::Escape))
				mWindow.close ();
		}		

		mWindow.clear ();
		mWindow.setView (viewAnimation);
		mWindow.draw (spriteBackgroundAnimation);
		mWindow.setView (viewIHM);
		mWindow.draw (spriteBackgroundIhm);
		mWindow.display ();
	}

	return 0;
}