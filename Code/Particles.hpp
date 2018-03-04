
/*
Author: Alberto Quesada Ibáñez
Date: 12/01/2018
Info:
*/

#pragma once

#include <SFML/Graphics.hpp>

/**
 *	@class: Particles
 *  @brief: Clase particles que va a contener los atributos basicos de la explosion.
*/
class Particles{

private:

	//Atributos basicos 
    sf::Color Color;

    sf::Vector2f Position;

    sf::Vector2f Velocity;

    float AlphaSub;

    unsigned short int Tick;

public:

	//Constructor
	Particles(sf::Vector2f,sf::Color);

    ~Particles();

    sf::Color GetColor ( void );   

    sf::Vector2f GetPosition ( void );

    bool Poll ( void );
};
