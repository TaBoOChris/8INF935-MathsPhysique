#pragma once

#include "Contact.h"
#include "Primitive.h"

class CollisionData
{
public:
	CollisionData();
	void generateContact(Primitive prim1, Primitive prim2, CollisionData *data);


private:
	Contact* contacts;
	int contactRestant;
};

