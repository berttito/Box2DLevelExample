
/*
Author: Alberto Quesada Ibáñez
Date: 12/01/2018
Info:
*/

#pragma once

#include <memory>
#include <vector>
#include <string>
#include <map>
#include "Scene.hpp"
#include "Vehicle.hpp"
#include "Floor.hpp";
#include "Background.hpp"
#include "Platform.hpp"
#include "ContactListener.hpp"


/**
 *	@class: Demo_Scene
 *  @brief: Clase demo que hereda de escena, aqui se van añadir los gameobject.
 *	Llama al update y render de los gameobject
*/

class DemoScene : public Scene
{
public:


	ContactListener contactlistener;

	//Constructor donde añadimos los elementos de la escena al mapa de gameobject
	DemoScene(b2Vec2 gravity) : Scene(gravity)
	{
		add_game_object("vehicle", std::shared_ptr< Gameobject >(new Vehicle(*this)));
		add_game_object("floor", std::shared_ptr< Gameobject >(new Floor(*this)));
		add_game_object("background", std::shared_ptr< Gameobject >(new Background(*this)));
		add_game_object("platform", std::shared_ptr< Gameobject >(new Platform(*this)));

		getPhysicsWorld().SetContactListener(&contactlistener);
	}

	// Llama al metodo update() de cada gameobject 
	void update(float deltaTime) override;
	

	// Llama al metodo render() de cada gameobject 
	void render(sf::RenderWindow & renderer) override;

	//Segun la tecla se mueve
	void leftKeyPressed(float delta_time);

	//Segun la tecla se mueve
	void rightKeyPressed(float delta_time);

	//Funcion de freno
	void stopMovement();

	//Funcion para el movimiento de la cesta
	void movementCesta();

	//Funcion para el movimiento de la Y
	void movementTorreta();
		
	//Devuelve el booleano doParticles para saber cuando accionar las particulas
	bool getDoParticles();
	
	
};