
/*
Author: Alberto Quesada Ibáñez
Date: 12/01/2018
Info:
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "Gameobject.hpp"


/**
*  @class: Background
*  @brief: Clase background que hereda de gameobject,  aqui se crean todos los bodies con los que se interactua en el escenario.	
*/


class Background : public Gameobject
{

public:

	//bool para controlar cuando se accionan las particulas
	bool doParticles = false;

	//En el constructor es donde vamos a añadir tanto la parte grafica como la fisica
	Background(Scene & scene);

public:

	void update() override;

	//Metodo que controla el flipeo de la Y
	void flip();
	void collision()override;

};