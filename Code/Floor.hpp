/*
Author: Alberto Quesada Ibáñez
Date: 12/01/2018
Info:
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "Gameobject.hpp"

/**
*	@class: Floor
*   @brief: Clase floor que hereda de gameobject, aqui se crean todos los suelos del escenario.
*/

class Floor : public Gameobject
{

public:

	//En el constructor es donde vamos a añadir tanto la parte grafica como la fisica
	Floor(Scene & scene);

public:


	void update() override;

	void collision()override {}
};