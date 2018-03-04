/*
Author: Alberto Quesada Ibáñez
Date: 12/01/2018
Info:
*/

#pragma once

#include <Box2D/Box2D.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Gameobject.hpp"

/**
 *	@class: Vehicle
 *  @brief: Clase vehicle que hereda de gameobject, aqui se crea el vehiculo.
*/

class Vehicle : public Gameobject
{

public:

	//En el constructor es donde vamos a añadir tanto la parte grafica como la fisica
	Vehicle(Scene & scene);

public:

	void update() override;
	void collision()override {}

	//Estos metodos llaman a los metodos que tiene implementada la clase vehicle

	//Metodo para el movimiento hacia la izquierda del vehiculo
	void move_left(float speed);

	//Metodo para el movimiento hacia al derecha del vehiculo
	void move_right(float speed);

	//Metodo para el frenado del vehiculo
	void stop();

	//Metodo para el movimiento de la cesta
	void move_cesta();


};