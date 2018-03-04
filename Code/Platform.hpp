
/*
Author: Alberto Quesada Ibáñez
Date: 12/01/2018
Info:
*/

#pragma once


#include <SFML/Graphics.hpp>
#include "Gameobject.hpp"

/**
*	@class: Platform
*   @brief: Clase platform que hereda de gameobject, aqui se crea la plataforma sobre la que 
*   se tiene que depositar el vehiculo.
*/

class Platform : public Gameobject
{
public: 

	//Bool que permite controlar cuando se acciona el movimiento de la plataforma
	bool activeMovement = false;

public:

	//En el constructor es donde vamos a añadir tanto la parte grafica como la fisica
	Platform(Scene & scene);

public:

	void update() override;

	//Metodo para mover la plataforma
	void move();
	void collision();

};