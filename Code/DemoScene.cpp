#include "DemoScene.hpp"

//Se hace el update de la escena y a la vez se controla cuando se activa la plataforma  
void DemoScene::update(float deltaTime) 
{
	Scene::update(deltaTime);

	Platform * platform = dynamic_cast<Platform *>(get_game_object("platform"));

	//Cuando el sensor pone el booleano a true se acciona el movimiento de la plataforma
	if (platform->activeMovement) 
	{	
		platform->move();				
	}

	//Se llama al metodo update de todos los game_objects
	for (auto it = game_objects.begin(); it != game_objects.end(); it++)
	{
		//Llamar metodo update
		auto key = it->first;
		game_objects[key]->update();
	}
}

//Se llama al metodo render de todos los game_objects
void DemoScene::render(sf::RenderWindow & renderer)
{
	for (auto it = game_objects.begin(); it != game_objects.end(); it++)
	{
		//Llamar metodo render
		auto key = it->first;
		game_objects[key]->render(renderer);
	}
}

//Metodo que le pasa la velocidad al vehiculo cuando se acciona la tecla adecuada
void DemoScene::leftKeyPressed(float delta_time)
{
	Vehicle * vehicle = dynamic_cast<Vehicle *>(get_game_object("vehicle"));

	if (vehicle)
	{
		vehicle->move_left(300 * delta_time);
	}
}

//Metodo que le pasa la velocidad al vehiculo cuando se acciona la tecla adecuada
void DemoScene::rightKeyPressed(float delta_time)
{
	Vehicle * vehicle = dynamic_cast<Vehicle *>(get_game_object("vehicle"));

	if (vehicle)
	{
		vehicle->move_left(-300 * delta_time);
	}
}

//void DemoScene::movementTorreta()
//{
//	Background * background = dynamic_cast<Background *>(get_game_object("background"));
//
//	if (background)
//	{
//		background->flip();
//	}
//}

//Metodo para accionar las particulas
bool DemoScene::getDoParticles()
{
	Background * background = dynamic_cast<Background *>(get_game_object("background"));
	Platform * platform = dynamic_cast<Platform *>(get_game_object("platform"));

	if (platform->activeMovement)
		return background->doParticles;
	else
		return false;
}

//Metodo que frena al vehiculo cuando se acciona la tecla adecuada
void DemoScene::stopMovement() 
{
	Vehicle * vehicle = dynamic_cast<Vehicle *>(get_game_object("vehicle"));

	if (vehicle)
	{
		vehicle->stop();
	}
}

//Metodo que realiza el movimiento de volcado de la cesta dle vehiculo cuando se acciona la tecla adecuada
void DemoScene::movementCesta()
{
	Vehicle * vehicle = dynamic_cast<Vehicle *>(get_game_object("vehicle"));

	if (vehicle)
	{
		vehicle->move_cesta();
	}
}