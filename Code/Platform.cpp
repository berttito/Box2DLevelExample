#include "Platform.hpp"

Platform::Platform(Scene & scene) : Gameobject(scene)
{	
	//PLATAFORMA

	// Se crea el body a partir de una definición de sus características:
	b2BodyDef platform_BodyDef;

	platform_BodyDef.type = b2_kinematicBody;
	platform_BodyDef.position.Set(1200.f, 50.f);

	bodies["platform"] = scene.getPhysicsWorld().CreateBody(&platform_BodyDef);

	b2PolygonShape platform_Shape;
	platform_Shape.SetAsBox(100.f, 20.f);

	// Se añade una fixture al body:

	b2FixtureDef platform_FixtureDef;
	platform_FixtureDef.shape = &platform_Shape;

	bodies["platform"]->CreateFixture(&platform_FixtureDef);

	bodies["platform"]->SetUserData(this);
}

 // Movimiento de la plataforma

void Platform::move()
{
	
	b2Body * bodyPlatform = dynamic_cast <b2Body *>(bodies["platform"]);

	if (bodies["platform"]->GetPosition().y > 594.f)
		bodyPlatform->SetLinearVelocity(b2Vec2(0, 0));
	if (bodies["platform"]->GetPosition().y <= 50.f)
		bodyPlatform->SetLinearVelocity(b2Vec2(0, 30));		
}

//Metodo al que llama el contact listener

void Platform::collision()
{
	activeMovement = true;
}

void Platform::update()
{

}