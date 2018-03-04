
/*
Author: Alberto Quesada Ibáñez
Date: 12/01/2018
Info:
*/

#pragma once

#include <memory>
#include <vector>
#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

/**
 *	@class: Gameobject
 *  @brief: Clase escena que va a contener el mundo y la lista de gameobjects.
 *	Es la base de la escena demo que vamos a construir.
*/

class Gameobject;

class Scene
{
protected:

	//Creamos un mundo físico
	b2World phxWorld;

	//Mapa de gameobjects
	std::map< std::string, std::shared_ptr< Gameobject > > game_objects;

public:

	Scene(b2Vec2 gravity) : phxWorld(gravity)
	{
	}

public:

	//Añadir un gameobject al mapa
	void add_game_object(const std::string & name, std::shared_ptr< Gameobject > & game_object)
	{
		game_objects[name] = game_object;
	}

	//Getter del mundo
	b2World & getPhysicsWorld()
	{
		return phxWorld;
	}

	//Getter de los gameobject
	Gameobject * get_game_object(const std::string & name)
	{
		// Si lo encuentra retorna un puntero o null en otro caso 
		if (game_objects.count(name))
		{
			return game_objects[name].get();
		}
		else
		{
			return nullptr;
		}
	}

	//Update que va a llamar a la funcion step del mundo fisico
	virtual void update(float deltaTime)
	{
		phxWorld.Step(deltaTime, 8, 4);
	}

	//Metodo virtual puro de render
	virtual void render(sf::RenderWindow & renderer) = 0;
};
