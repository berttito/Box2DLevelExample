
/*
Author: Alberto Quesada Ibáñez
Date: 12/01/2018
Info:
*/

#include "Vehicle.hpp"

Vehicle::Vehicle(Scene & scene) : Gameobject(scene) 
{
	// Se añaden aqui todos los bodies (piezas) del vehiculo:	

	// CARROCERIA
	// Se crea el body a partir de una definición de sus características:
	b2BodyDef carroceria_BodyDef;

	carroceria_BodyDef.type = b2_dynamicBody;
	carroceria_BodyDef.position.Set(150.f, 450.f);

	bodies["carroceria"] = scene.getPhysicsWorld().CreateBody(&carroceria_BodyDef);

	b2PolygonShape carroceria_Shape;
	carroceria_Shape.SetAsBox(70.f, 20.f);

	// CARROCERIA PARTE 2
	// Se crea el body a partir de una definición de sus características:
	b2BodyDef carroceria2_BodyDef;

	carroceria2_BodyDef.type = b2_dynamicBody;
	carroceria2_BodyDef.position.Set(150.f, 500.f);

	bodies["carroceria2"] = scene.getPhysicsWorld().CreateBody(&carroceria2_BodyDef);

	b2PolygonShape carroceria2_Shape;
	carroceria2_Shape.SetAsBox(70.f, 10.f);

	//RECTANGULO PARTE IZQUIERDA
	
	b2Vec2 verticesParte1[4];
	verticesParte1[0].Set(carroceria2_BodyDef.position.x - 220, carroceria2_BodyDef.position.y - 450);
	verticesParte1[1].Set(carroceria2_BodyDef.position.x - 200, carroceria2_BodyDef.position.y - 450);
	verticesParte1[2].Set(carroceria2_BodyDef.position.x - 220, carroceria2_BodyDef.position.y - 510);
	verticesParte1[3].Set(carroceria2_BodyDef.position.x - 200, carroceria2_BodyDef.position.y - 510);
	b2PolygonShape parte1_Shape;
	parte1_Shape.Set(verticesParte1, 4);	

	//RECTANGULO PARTE DERECHA

	b2Vec2 verticesParte3[4];
	verticesParte3[0].Set(carroceria2_BodyDef.position.x - 100, carroceria2_BodyDef.position.y - 450);
	verticesParte3[1].Set(carroceria2_BodyDef.position.x - 80, carroceria2_BodyDef.position.y - 450);
	verticesParte3[2].Set(carroceria2_BodyDef.position.x - 100, carroceria2_BodyDef.position.y - 510);
	verticesParte3[3].Set(carroceria2_BodyDef.position.x - 80, carroceria2_BodyDef.position.y - 510);
	b2PolygonShape parte3_Shape;
	parte3_Shape.Set(verticesParte3, 4);	

	// Se añade una fixture a los bodies de las carrocerias:
	
	b2FixtureDef carroceria_FixtureDef;
	carroceria_FixtureDef.shape = &carroceria_Shape;	
	carroceria_FixtureDef.density = 3.f;

	b2FixtureDef carroceria2_FixtureDef;
	carroceria2_FixtureDef.shape = &carroceria2_Shape;	
	carroceria2_FixtureDef.density = 0.1f;

	//Fixtures rectangulos laterales

	b2FixtureDef parte1_FixtureDef;
	parte1_FixtureDef.shape = &parte1_Shape;	

	b2FixtureDef parte3_FixtureDef;
	parte3_FixtureDef.shape = &parte3_Shape;

	bodies["carroceria"]->CreateFixture(&carroceria_FixtureDef);
	bodies["carroceria2"]->CreateFixture(&carroceria2_FixtureDef);
	bodies["carroceria2"]->CreateFixture(&parte1_FixtureDef);	
	bodies["carroceria2"]->CreateFixture(&parte3_FixtureDef);

	//RUEDA IZQUIERDA
	// Se crea el body a partir de una definición de sus características:

	b2BodyDef left_wheel_BodyDef;	

	left_wheel_BodyDef.type = b2_dynamicBody;
	left_wheel_BodyDef.position.Set(bodies["carroceria"]->GetPosition().x + 80, bodies["carroceria"]->GetPosition().y - 50);	

	bodies["left_wheel"] = scene.getPhysicsWorld().CreateBody(&left_wheel_BodyDef);

	b2CircleShape body_left_wheel_Shape;
	body_left_wheel_Shape.m_radius = 25.f;
	
	// Se añade una fixture al body:

	b2FixtureDef body_left_wheel_Fixture;
	body_left_wheel_Fixture.shape = &body_left_wheel_Shape;
	body_left_wheel_Fixture.density = 1.00f;
	body_left_wheel_Fixture.restitution = 0.75f;
	body_left_wheel_Fixture.friction = 0.50f;

	bodies["left_wheel"]->CreateFixture(&body_left_wheel_Fixture);


	//RUEDA DERECHA
	// Se crea el body a partir de una definición de sus características:

	b2BodyDef right_wheel_BodyDef;

	right_wheel_BodyDef.type = b2_dynamicBody;
	right_wheel_BodyDef.position.Set(bodies["carroceria"]->GetPosition().x - 80, bodies["carroceria"]->GetPosition().y - 50);

	bodies["right_wheel"] = scene.getPhysicsWorld().CreateBody(&right_wheel_BodyDef);

	b2CircleShape body_right_wheel_Shape;
	body_right_wheel_Shape.m_radius = 25.f;

	// Se añade una fixture al body:

	b2FixtureDef body_right_wheel_Fixture;
	body_right_wheel_Fixture.shape = &body_right_wheel_Shape;
	body_right_wheel_Fixture.density = 1.00f;
	body_right_wheel_Fixture.restitution = 0.75f;
	body_right_wheel_Fixture.friction = 0.50f;

	bodies["right_wheel"]->CreateFixture(&body_right_wheel_Fixture);	

	//JOINTS

	//Joint de la cesta
	
	b2RevoluteJointDef revoluteJointCarroceriaDef;
	revoluteJointCarroceriaDef.Initialize(bodies["carroceria"], bodies["carroceria2"], bodies["carroceria"]->GetWorldCenter() + b2Vec2(-35, 5));	
	revoluteJointCarroceriaDef.enableLimit = false;
	revoluteJointCarroceriaDef.enableMotor = true;
	revoluteJointCarroceriaDef.maxMotorTorque = 1000000;
	revoluteJointCarroceriaDef.motorSpeed = 0;
	revoluteJointCarroceriaDef.collideConnected = false;
	joints["cesta"] = scene.getPhysicsWorld().CreateJoint(&revoluteJointCarroceriaDef);	

	//Joints de las ruedas

	b2RevoluteJointDef revoluteJointLeftWheelDef;
	revoluteJointLeftWheelDef.bodyA = bodies["carroceria"];
	revoluteJointLeftWheelDef.bodyB = bodies["left_wheel"];
	revoluteJointLeftWheelDef.collideConnected = false;
	revoluteJointLeftWheelDef.localAnchorA.Set(-50, -30);
	revoluteJointLeftWheelDef.localAnchorB.Set(0, 0);//center of the circle
	revoluteJointLeftWheelDef.enableMotor = true;	
	revoluteJointLeftWheelDef.maxMotorTorque = 4000000;
	joints["left_wheel"] = scene.getPhysicsWorld().CreateJoint(&revoluteJointLeftWheelDef);	


	b2RevoluteJointDef revoluteJointRightWheelDef;
	revoluteJointRightWheelDef.bodyA = bodies["carroceria"];
	revoluteJointRightWheelDef.bodyB = bodies["right_wheel"];
	revoluteJointRightWheelDef.collideConnected = false;
	revoluteJointRightWheelDef.localAnchorA.Set(50, -30);
	revoluteJointRightWheelDef.localAnchorB.Set(0, 0);//center of the circle
	revoluteJointLeftWheelDef.enableMotor = true;
	revoluteJointLeftWheelDef.maxMotorTorque = 4000000;
	joints["right_wheel"] = scene.getPhysicsWorld().CreateJoint(&revoluteJointRightWheelDef);

	
	bodies["right_wheel"]->SetUserData(this);
}

//Movimiento hacia la izquierda

void Vehicle::move_left(float speed)
{
	b2RevoluteJoint * jointLeftWheel = dynamic_cast <b2RevoluteJoint *>(joints["left_wheel"]);
	jointLeftWheel->SetMotorSpeed(speed);
}

//Movimiento hacia la derecha

void Vehicle::move_right(float speed)
{
	b2RevoluteJoint * jointRightWheel = dynamic_cast <b2RevoluteJoint *>(joints["right_wheel"]);
	jointRightWheel->SetMotorSpeed(speed);
}

//Frenado

void Vehicle::stop()
{
	b2Body  * bodycarroceria = dynamic_cast <b2Body *>(bodies["carroceria"]);
	bodycarroceria->SetLinearVelocity(-bodycarroceria->GetLinearVelocity() - b2Vec2(0, 5));	
	
}

//Mover cesta

void Vehicle::move_cesta()
{
	b2RevoluteJoint * jointCarroceria = dynamic_cast <b2RevoluteJoint *>(joints["cesta"]);
	jointCarroceria->SetMotorSpeed(10000000 );
	
}

void Vehicle::update()
{

}