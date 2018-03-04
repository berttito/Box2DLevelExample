/*
Author: Alberto Quesada Ibáñez
Date: 12/01/2018
Info:
*/

#include <memory>
#include <vector>
#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "DemoScene.hpp"
#include "Particles.hpp"

int main(int argc, char *argv[])
{
	//Inicializamos la semilla para el random de las particulas
	srand(time(NULL));

	//Creamos la ventana
	sf::RenderWindow window(sf::VideoMode(1900, 1024), "Animation Examples: Box2D Rigid Bodies", sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings(32));

	window.setVerticalSyncEnabled(true);

	//Creamos la escena de demo
	DemoScene demo_scene(b2Vec2(0, -9.8f));

	//Vector de particulas
	std::vector<Particles*> Explosions;

	//Shape que van a tener las particulas
	sf::RectangleShape RectShape;
	RectShape.setSize(sf::Vector2f(2, 2));

	bool running = true;

	sf::Clock timer;
	float delta_time = 0.017f;          // ~60 fps

	do
	{
		// Process window events:

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				running = false;
			}

			//Eventos de teclado
			if (event.type == sf::Event::KeyPressed)
			{
				//Movimiento hacia la izquierda
				if (event.key.code == sf::Keyboard::Left)
					demo_scene.leftKeyPressed(delta_time);

				//Movimiento hacia la derecha
				if (event.key.code == sf::Keyboard::Right)
					demo_scene.rightKeyPressed(delta_time);

				//Movimiento de la cesta
				if (event.key.code == sf::Keyboard::Space)				
					demo_scene.movementCesta();						

				//Frenado
				if (event.key.code == sf::Keyboard::R)
					demo_scene.stopMovement();					
			}

		}

		//Accionado de las particulas
		if (demo_scene.getDoParticles())
		{
			for (int i = 0; i < 2; i++)
			{
				Explosions.push_back(new Particles(sf::Vector2f(1100, 404), sf::Color::Green));
				Explosions.push_back(new Particles(sf::Vector2f(900, 404), sf::Color::Yellow));
			}
		}

		// Update:

		//ejecuta los 4 pasos descritos en los apuntes.
		demo_scene.update(delta_time);

		// Render:

		window.clear(sf::Color(0, 0, 0));
	
		//Se recorren el vector de explosiones estableciendo la posicion y el color
		RectShape.setSize(sf::Vector2f(2, 2));
		for (std::vector<Particles*>::iterator it = Explosions.begin(); it != Explosions.end(); ++it)
		{
			RectShape.setFillColor((*it)->GetColor());
			RectShape.setPosition((*it)->GetPosition());
			window.draw(RectShape);
		}		

		if (timer.getElapsedTime().asMilliseconds() >= 50)
		{
			for (std::vector<Particles*>::iterator it = Explosions.begin(); it != Explosions.end();)
			{
				if (!(*it)->Poll())
				{					
					delete *it;
					it = Explosions.erase(it);
				}
				else
					++it;
			}
			timer.restart();
		}

		demo_scene.render(window);

		window.display();

		delta_time = (delta_time + timer.getElapsedTime().asSeconds()) * 0.5f;
	} while (running);

	return EXIT_SUCCESS;
}
