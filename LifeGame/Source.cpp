#include <iostream>
#include <chrono>
#include <thread>
#include <stdexcept> 
#include "Headers\Generation.hpp"
#include "Headers\Regle.hpp"
#include <SFML/Graphics.hpp>

// SFML : v2.5.1
const int POSITION = 30;
const float SIZE = 10.0f;
const float REFRESH_SPEED = 0.001f;

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
	imageBackgroundAnimation.create (mWindow.getSize ().x * 0.8f, mWindow.getSize ().y, sf::Color::Black);
	textureBackgroundAnimation.loadFromImage (imageBackgroundAnimation);

	sf::Sprite spriteBackgroundAnimation;
	spriteBackgroundAnimation.setTexture (textureBackgroundAnimation);
	spriteBackgroundAnimation.setTextureRect (sf::IntRect (0, 0, mWindow.getSize ().x * 0.8f, mWindow.getSize ().y));
	spriteBackgroundAnimation.setPosition (sf::Vector2f(0, 0));
	spriteBackgroundAnimation.setScale(sf::Vector2f((mWindow.getSize().x * 0.8f) / MAXX, mWindow.getSize().y / MAXY));

	// Ihm sur la droite de l'écran
	sf::View viewIHM (sf::FloatRect (mWindow.getSize ().x * 0.8f, 0, mWindow.getSize ().x, mWindow.getSize ().y));
	viewIHM.setViewport (sf::FloatRect (0.8f, 0.0f, 1.0f, 1.0f));

	sf::Texture textureBackgroundIHM;

	sf::Image imageBackgroundIhm;
	imageBackgroundIhm.create (mWindow.getSize ().x - (mWindow.getSize ().x * 0.8f), mWindow.getSize ().y, sf::Color::Blue);
	textureBackgroundIHM.loadFromImage (imageBackgroundIhm);

	sf::Sprite spriteBackgroundIhm;
	spriteBackgroundIhm.setTexture (textureBackgroundIHM);
	spriteBackgroundIhm.setTextureRect (sf::IntRect (mWindow.getSize ().x * 0.8f, 0, mWindow.getSize ().x, mWindow.getSize ().y));
	spriteBackgroundIhm.setPosition (sf::Vector2f (0, 0));


	sf::Font font;
	if (!font.loadFromFile ("Assets/Fonts/Spring Garden.ttf"))
	{
		// error...
	}

	sf::Text text;
	text.setFont (font);
	text.setString ("Lifegame");
	text.setFillColor (sf::Color::White);

	text.setCharacterSize ((mWindow.getSize ().x - (mWindow.getSize ().x * 0.8f)) / 5);
	int position = (mWindow.getSize ().x - (mWindow.getSize ().x * 0.8f) - text.getGlobalBounds ().width) / 2;
	text.setPosition (sf::Vector2f (mWindow.getSize ().x * 0.8f + position, 0));

	// Lifegame
	int* tableau = new int[MAXX * MAXY];

	for (int i = 0; i < MAXX; i++)
	{
		for (int j = 0; j < MAXY; j++)
		{
			tableau[i * MAXY + j] = 0;
		}
	}

	//generationAleatoire (tableau);
	prototypeCanonPlaneur30(tableau);

	sf::Color mColor;
	int alea = 0;

	while (mWindow.isOpen ())
	{
		for (int i = 0; i < MAXY; i++)
			for (int j = 0; j < MAXX; j++)
			{
				alea = std::rand() % 4 + 1;
				switch (tableau[i * MAXX + j])
				{
				case 0:
					mColor = sf::Color::Black;
					break;
				default:
					if (alea == 1)
						mColor = sf::Color::Green;
					else if (alea == 2)
						mColor = sf::Color::Blue;
					else if (alea == 3)
						mColor = sf::Color::Magenta;
					else if (alea == 4)
						mColor = sf::Color::Yellow;
					else
						mColor = sf::Color::Magenta;
					break;
				}

				imageBackgroundAnimation.setPixel (j, i, mColor);
			}

		textureBackgroundAnimation.loadFromImage (imageBackgroundAnimation);

		sf::Event event;
		while (mWindow.pollEvent (event))
		{
			if (event.type == sf::Event::Resized)
			{
				viewAnimation.reset (sf::FloatRect (0, 0, mWindow.getSize ().x * 0.8f, mWindow.getSize ().y));
				spriteBackgroundAnimation.setTextureRect (sf::IntRect (0, 0, MAXX, MAXY));
				spriteBackgroundAnimation.setPosition (sf::Vector2f (0, 0));
				spriteBackgroundAnimation.setScale (sf::Vector2f ((mWindow.getSize ().x * 0.8f) / MAXX, mWindow.getSize ().y / MAXY));

				viewIHM.reset (sf::FloatRect (mWindow.getSize ().x * 0.8f, 0, mWindow.getSize ().x, mWindow.getSize ().y));
				spriteBackgroundIhm.setTextureRect (sf::IntRect (mWindow.getSize ().x * 0.8f, 0, mWindow.getSize ().x, mWindow.getSize ().y));
				spriteBackgroundIhm.setPosition (sf::Vector2f (0, 0));
				
				text.setCharacterSize ((mWindow.getSize ().x - (mWindow.getSize ().x * 0.8f))/5);
				int position = (mWindow.getSize ().x - (mWindow.getSize ().x * 0.8f) - text.getGlobalBounds ().width) / 2;
				text.setPosition (sf::Vector2f (mWindow.getSize ().x * 0.8f + position, 0));
			}

			if (event.type == sf::Event::Closed)
				mWindow.close ();

			if (sf::Keyboard::isKeyPressed (sf::Keyboard::Escape))
				mWindow.close ();
		}		

		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		mWindow.clear ();
		mWindow.setView (viewAnimation);
		mWindow.draw (spriteBackgroundAnimation);
		mWindow.setView (viewIHM);
		mWindow.draw (spriteBackgroundIhm);
		mWindow.draw (text);
		mWindow.display ();

		jeuDeLaVie (tableau);
	}

	return 0;
}