
/*
Author: Alberto Quesada Ibáñez
Date: 12/01/2018
Info:
*/

#include "Particles.hpp"

//Constructor donde inicializamos los valores
Particles::Particles(sf::Vector2f position, sf::Color color)
{
    Position = position;
    if(rand() % 2)
        Velocity.x = rand() % 10;
    else
        Velocity.x = (rand() % 10) * (-1);
    if(rand() % 2)
        Velocity.y = rand() % 10;
    else
        Velocity.y = (rand() % 10) * (-1);
    Color = color;
    AlphaSub = this->Color.a / (rand() % 50 + 5);
    Tick = 0;
    return;
};

//Destructor
Particles::~Particles()
{
    return;
};

//Getter del color
sf::Color Particles::GetColor( void )
{
    return Color;
};

//Getter de la posicion
sf::Vector2f Particles::GetPosition( void )
{
    return Position;
};

//Gestiona el comportamiento de la explosion de particulas
bool Particles::Poll ( void )
{
    if(Color.a - AlphaSub <= 0 || Tick >= 50)
        return false;
    Position = Position + Velocity;
    Color.a = Color.a - AlphaSub;
    if(Color.a > 200)
        Color.a = 200;
    Tick++;
    return true;
};
