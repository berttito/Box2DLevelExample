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
#include "Scene.hpp"


/**
 *	@class: Gameobject
 *  @brief: Clase gameobject que va a contener una referencia a la escena,
 *	una lista de bodies, de joints y de shapes
 *	Va a ser la clase base sobre la que vamos a construir cualquier gameobject.
*/

class Gameobject 
{	

protected:

	Scene & scene;
	std::map< std::string, b2Body * > bodies;
	std::map< std::string, b2Joint * > joints;
	std::map< std::string,std::shared_ptr< sf::Shape > > gfxShapes;


public:

	Gameobject(Scene & scene) : scene(scene)
	{
	}

	//Metodo virtual puro
	virtual void update() = 0;

	
	//Esta función se encarga de convertir el sistema de coordenadas para que la escena no se vea invertida.
	inline sf::Vector2f box2d_position_to_sfml_position(const b2Vec2 & box2d_position, float window_height)
	{
		return sf::Vector2f(box2d_position.x, window_height - box2d_position.y);
	}


	//Para cada body, se coge el transform del body y para cada fixture se aplica la shape
	//correspondiente al transform del body y se dibuja la shape
	void render(sf::RenderWindow & renderer);

	void virtual collision() = 0;
	
};