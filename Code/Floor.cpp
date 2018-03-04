/*
Author: Alberto Quesada Ibáñez
Date: 12/01/2018
Info:
*/

#include "Floor.hpp"

Floor::Floor(Scene & scene) : Gameobject(scene)
{
	// SUELO

	// Se crea el body a partir de una definición de sus características:

	b2BodyDef floor_BodyDef;

	floor_BodyDef.type = b2_staticBody;
	floor_BodyDef.position.Set(0.f, 50.f);                                      // Posición inicial absoluta		

	bodies["floor"] = scene.getPhysicsWorld().CreateBody(&floor_BodyDef);

	// Se añande una fixture al body:

	b2EdgeShape floor_Shape;
	floor_Shape.Set(b2Vec2(0.f, 300.f), b2Vec2(300, 300.f));                    // Coordenadas locales respecto al centro del body

	b2FixtureDef floor_Fixture;
	floor_Fixture.shape = &floor_Shape;
	floor_Fixture.friction = 1.f;

	bodies["floor"]->CreateFixture(&floor_Fixture);

	///////////////////////////////////////////////////////////

	// Se crea el body a partir de una definición de sus características:

	b2BodyDef floor2_BodyDef;

	floor2_BodyDef.type = b2_staticBody;
	floor2_BodyDef.position.Set(0.f, 50.f);                                      // Posición inicial absoluta		

	bodies["floor2"] = scene.getPhysicsWorld().CreateBody(&floor2_BodyDef);

	// Se añande una fixture al body:

	b2EdgeShape floor2_Shape;
	floor2_Shape.Set(b2Vec2(300, 300.f), b2Vec2(500, 200.f));                    // Coordenadas locales respecto al centro del body

	b2FixtureDef floor2_Fixture;
	floor2_Fixture.shape = &floor2_Shape;
	floor2_Fixture.friction = 1.f;

	bodies["floor2"]->CreateFixture(&floor2_Fixture);

	///////////////////////////////////////////////////////////

	// Se crea el body a partir de una definición de sus características:

	b2BodyDef floor3_BodyDef;

	floor3_BodyDef.type = b2_staticBody;
	floor3_BodyDef.position.Set(0.f, 50.f);                                      // Posición inicial absoluta		

	bodies["floor3"] = scene.getPhysicsWorld().CreateBody(&floor3_BodyDef);

	// Se añande una fixture al body:

	b2EdgeShape floor3_Shape;
	floor3_Shape.Set(b2Vec2(500, 200), b2Vec2(700, 130.f));                    // Coordenadas locales respecto al centro del body

	b2FixtureDef floor3_Fixture;
	floor3_Fixture.shape = &floor3_Shape;
	floor3_Fixture.friction = 1.f;

	bodies["floor3"]->CreateFixture(&floor3_Fixture);

	//////////////////////////////////////////////////////////

	// Se crea el body a partir de una definición de sus características:

	b2BodyDef floor4_BodyDef;

	floor4_BodyDef.type = b2_staticBody;
	floor4_BodyDef.position.Set(0.f, 50.f);                                      // Posición inicial absoluta		

	bodies["floor4"] = scene.getPhysicsWorld().CreateBody(&floor4_BodyDef);

	// Se añande una fixture al body:

	b2EdgeShape floor4_Shape;
	floor4_Shape.Set(b2Vec2(700, 130.f), b2Vec2(900, 130.f));                    // Coordenadas locales respecto al centro del body

	b2FixtureDef floor4_Fixture;
	floor4_Fixture.shape = &floor4_Shape;
	floor4_Fixture.friction = 1.f;

	bodies["floor4"]->CreateFixture(&floor4_Fixture);

	/////////////////////////////////////////////////////////

	// Se crea el body a partir de una definición de sus características:

	b2BodyDef floor5_BodyDef;

	floor5_BodyDef.type = b2_staticBody;
	floor5_BodyDef.position.Set(0.f, 50.f);                                      // Posición inicial absoluta		

	bodies["floor5"] = scene.getPhysicsWorld().CreateBody(&floor5_BodyDef);

	// Se añande una fixture al body:

	b2EdgeShape floor5_Shape;
	floor5_Shape.Set(b2Vec2(900, 130.f), b2Vec2(1100, 150.f));                    // Coordenadas locales respecto al centro del body

	b2FixtureDef floor5_Fixture;
	floor5_Fixture.shape = &floor5_Shape;
	floor5_Fixture.friction = 1.f;

	bodies["floor5"]->CreateFixture(&floor5_Fixture);

	////////////////////////////////////////////////////////

	// Se crea el body a partir de una definición de sus características:

	b2BodyDef floor6_Body2Def;

	floor6_Body2Def.type = b2_staticBody;
	floor6_Body2Def.position.Set(0.f, 50.f);                                      // Posición inicial absoluta		

	bodies["floor6"] = scene.getPhysicsWorld().CreateBody(&floor6_Body2Def);

	// Se añande una fixture al body:

	b2EdgeShape floor6_Shape;
	floor6_Shape.Set(b2Vec2(1300.f, 20.f), b2Vec2(1950, 40.f));                    // Coordenadas locales respecto al centro del body

	b2FixtureDef floor6_Fixture;
	floor6_Fixture.shape = &floor6_Shape;
	floor6_Fixture.friction = 1.f;

	bodies["floor6"]->CreateFixture(&floor6_Fixture);
}

void Floor::update()
{
}

