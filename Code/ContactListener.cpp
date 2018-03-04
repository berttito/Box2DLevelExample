#include "ContactListener.hpp"
#include "Gameobject.hpp"

void ContactListener::BeginContact(b2Contact * contact)
{
	//Utilizamos los userData de los bodies
	void * bodyUserDataA = contact->GetFixtureA()->GetBody()->GetUserData();
	void * bodyUserDataB = contact->GetFixtureB()->GetBody()->GetUserData();

	//Comprobamos la colision y llamamos al metodo collision()
	if (bodyUserDataA && bodyUserDataB) 
	{
		if (static_cast<Gameobject*>(bodyUserDataA))
		{
			static_cast<Gameobject*>(bodyUserDataA)->collision();
		}

		if (static_cast<Gameobject*>(bodyUserDataB))
		{
			static_cast<Gameobject*>(bodyUserDataB)->collision();
		}
			
	}

}
