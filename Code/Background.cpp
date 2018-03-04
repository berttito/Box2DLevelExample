
#include "Background.hpp"

Background::Background(Scene & scene) : Gameobject(scene)
{
	// ESTRUCTURA SUJECCION BOLAS

	// | definition
	// Se crea el body a partir de una definición de sus características:
	b2BodyDef struct_BodyDef;

	struct_BodyDef.type = b2_staticBody;
	struct_BodyDef.position.Set(1600.f, 275.f);

	bodies["struct"] = scene.getPhysicsWorld().CreateBody(&struct_BodyDef);

	b2PolygonShape struct_Shape;
	struct_Shape.SetAsBox(20.f, 200.f);

	// Se añade una fixture al body:

	b2FixtureDef struct_FixtureDef;
	struct_FixtureDef.shape = &struct_Shape;
	struct_FixtureDef.filter.maskBits = 0x0000;

	bodies["struct"]->CreateFixture(&struct_FixtureDef);

	/////////////////////////////////////////////////////////////

	// Y definition
	// Se crea el body a partir de una definición de sus características:
	b2BodyDef Y_definition;

	Y_definition.type = b2_dynamicBody;
	Y_definition.position.Set(1520.f, 320.f);
	
	bodies["struct2"] = scene.getPhysicsWorld().CreateBody(&Y_definition);

	b2PolygonShape yleft_shape;
	b2PolygonShape yright_shape;

	yleft_shape.SetAsBox(20.f, 50.f, b2Vec2(30, 180), 180);
	yright_shape.SetAsBox(20.f, 50.f, b2Vec2(130, 180), -180);

	// Se añaden las fixtures al body:

	b2FixtureDef yleft_fixture;

	yleft_fixture.shape = &yleft_shape;
	yleft_fixture.density = 1.0f;
	yleft_fixture.restitution = 0.50f;
	yleft_fixture.friction = 0.50f;

	b2FixtureDef yright_fixture;

	yright_fixture.shape = &yright_shape;
	yright_fixture.density = 1.0f;
	yright_fixture.restitution = 0.50f;
	yright_fixture.friction = 0.50f;

	bodies["struct2"]->CreateFixture(&yleft_fixture);
	bodies["struct2"]->CreateFixture(&yright_fixture);


	//BOLAS
	/////////////////////////////////////////////////////////////

	// Se crea el body a partir de una definición de sus características:
	b2BodyDef ball_BodyDef;

	ball_BodyDef.type = b2_dynamicBody;
	ball_BodyDef.position.Set(1630.f, 630.f);

	bodies["ball"] = scene.getPhysicsWorld().CreateBody(&ball_BodyDef);

	b2CircleShape body_ball_Shape;
	body_ball_Shape.m_radius = 15.f;

	// Se añade una fixture al body:

	b2FixtureDef body_ball_Fixture;
	body_ball_Fixture.shape = &body_ball_Shape;
	

	bodies["ball"]->CreateFixture(&body_ball_Fixture);

	/////////////////////////////////////////////////////////////

	// Se crea el body a partir de una definición de sus características:
	b2BodyDef ball2_BodyDef;

	ball2_BodyDef.type = b2_dynamicBody;
	ball2_BodyDef.position.Set(1630.f, 630.f);

	bodies["ball2"] = scene.getPhysicsWorld().CreateBody(&ball2_BodyDef);

	b2CircleShape body2_ball_Shape;
	body2_ball_Shape.m_radius = 15.f;

	// Se añade una fixture al body:

	b2FixtureDef body2_ball_Fixture;
	body2_ball_Fixture.shape = &body2_ball_Shape;


	bodies["ball2"]->CreateFixture(&body2_ball_Fixture);

	/////////////////////////////////////////////////////////////

	// Se crea el body a partir de una definición de sus características:
	b2BodyDef ball3_BodyDef;

	ball3_BodyDef.type = b2_dynamicBody;
	ball3_BodyDef.position.Set(1630.f, 630.f);

	bodies["ball3"] = scene.getPhysicsWorld().CreateBody(&ball3_BodyDef);

	b2CircleShape body3_ball_Shape;
	body3_ball_Shape.m_radius = 15.f;

	// Se añade una fixture al body:

	b2FixtureDef body3_ball_Fixture;
	body3_ball_Fixture.shape = &body3_ball_Shape;


	bodies["ball3"]->CreateFixture(&body3_ball_Fixture);

	/////////////////////////////////////////////////////////////

	// Se crea el body a partir de una definición de sus características:
	b2BodyDef ball4_BodyDef;

	ball4_BodyDef.type = b2_dynamicBody;
	ball4_BodyDef.position.Set(1630.f, 630.f);

	bodies["ball4"] = scene.getPhysicsWorld().CreateBody(&ball4_BodyDef);

	b2CircleShape body4_ball_Shape;
	body4_ball_Shape.m_radius = 15.f;

	// Se añade una fixture al body:

	b2FixtureDef body4_ball_Fixture;
	body4_ball_Fixture.shape = &body4_ball_Shape;


	bodies["ball4"]->CreateFixture(&body4_ball_Fixture);

	/////////////////////////////////////////////////////////////

	// Se crea el body a partir de una definición de sus características:
	b2BodyDef ball5_BodyDef;

	ball5_BodyDef.type = b2_dynamicBody;
	ball5_BodyDef.position.Set(1630.f, 630.f);

	bodies["ball5"] = scene.getPhysicsWorld().CreateBody(&ball5_BodyDef);

	b2CircleShape body5_ball_Shape;
	body5_ball_Shape.m_radius = 15.f;

	// Se añade una fixture al body:

	b2FixtureDef body5_ball_Fixture;
	body5_ball_Fixture.shape = &body5_ball_Shape;


	bodies["ball5"]->CreateFixture(&body5_ball_Fixture);


	/////////////////////////////////////////////////////////////

	// \/- definition
	// Se crea el body a partir de una definición de sus características:
	b2BodyDef struct3_BodyDef;

	struct3_BodyDef.type = b2_staticBody;
	struct3_BodyDef.position.Set(700, 530.f);
	struct3_BodyDef.angle = 290;

	bodies["struct3"] = scene.getPhysicsWorld().CreateBody(&struct3_BodyDef);

	b2PolygonShape struct3_Shape;
	struct3_Shape.SetAsBox(20.f, 100.f);

	// Se añade una fixture al body:

	b2FixtureDef struct3_FixtureDef;
	struct3_FixtureDef.shape = &struct3_Shape;

	bodies["struct3"]->CreateFixture(&struct3_FixtureDef);

	/////////////////////////////////////////////////////////////

	// Se crea el body a partir de una definición de sus características:
	b2BodyDef struct4_BodyDef;

	struct4_BodyDef.type = b2_staticBody;
	struct4_BodyDef.position.Set(835.f, 535.f);
	struct4_BodyDef.angle = 149.9;

	bodies["struct4"] = scene.getPhysicsWorld().CreateBody(&struct4_BodyDef);

	b2PolygonShape struct4_Shape;
	struct4_Shape.SetAsBox(20.f, 100.f);

	// Se añade una fixture al body:

	b2FixtureDef struct4_FixtureDef;
	struct4_FixtureDef.shape = &struct4_Shape;

	bodies["struct4"]->CreateFixture(&struct4_FixtureDef);

	/////////////////////////////////////////////////////////////

	// Se crea el body a partir de una definición de sus características:
	b2BodyDef struct5_BodyDef;

	struct5_BodyDef.type = b2_staticBody;
	struct5_BodyDef.position.Set(1000.f, 594.f);
	

	bodies["struct5"] = scene.getPhysicsWorld().CreateBody(&struct5_BodyDef);

	b2PolygonShape struct5_Shape;
	struct5_Shape.SetAsBox(100.f, 20.f);

	// Se añade una fixture al body:

	b2FixtureDef struct5_FixtureDef;
	struct5_FixtureDef.shape = &struct5_Shape;

	bodies["struct5"]->CreateFixture(&struct5_FixtureDef);

	/////////////////////////////////////////////////////////////

	//JOINTS
	
	//JOINT DE LA ESTRUCTURA

	b2RevoluteJointDef revoluteJointDef;

	revoluteJointDef.Initialize(bodies["struct"], bodies["struct2"], bodies["struct"]->GetWorldCenter() + b2Vec2(0, 200));	
	revoluteJointDef.enableLimit = false;
	revoluteJointDef.enableMotor = true;
	revoluteJointDef.maxMotorTorque = 1000000;
	revoluteJointDef.motorSpeed = 0;
	revoluteJointDef.collideConnected = true;	

	joints["joint1"] = scene.getPhysicsWorld().CreateJoint(&revoluteJointDef);

	/////////////////////////////////////////////////////////////

	//SENSOR

	b2FixtureDef trigger;
	b2CircleShape circleShape;
	circleShape.m_p.Set(150, -50);
	circleShape.m_radius = 100;	
	trigger.shape = &circleShape;
	trigger.isSensor = true;
	bodies["struct"]->CreateFixture(&trigger);	

	bodies["struct"]->SetUserData(this);	

}

//Metodo para el flipeo del joint de la Y

void Background::flip()
{
	b2RevoluteJoint * revoluteJointDef = dynamic_cast <b2RevoluteJoint *>(joints["joint1"]);	
	revoluteJointDef->SetMotorSpeed(-100000);

	printf("entra");
}

//Metodo al que llama el contact listener

void Background::collision()
{
	flip();
	doParticles = true;
}

void Background::update()
{
}