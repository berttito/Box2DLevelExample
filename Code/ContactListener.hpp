
/*
Author: Alberto Quesada Ibáñez
Date: 12/01/2018
Info:
*/

#pragma once


#include <Box2D/Box2D.h>
#include "Background.hpp"
#include "Vehicle.hpp"

	/**
	*	@class: ContactListener
	*   @brief: Clase que controla los sensores.
	*/
class ContactListener : public b2ContactListener

{

public:

	//En el constructor es donde vamos a añadir tanto la parte grafica como la fisica
	ContactListener() 
	{
	}

public:

	//Metodos para el inicio del contacto y el final del contacto
	void BeginContact(b2Contact * contact);
	void EndContact(b2Contact * contact) {}

};