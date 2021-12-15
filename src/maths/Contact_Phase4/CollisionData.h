#pragma once

#include "Contact.h"
#include "Primitive.h"
#include <vector>

class CollisionData
{
public:
	CollisionData();
	void generateContact(Primitive prim1, Primitive prim2, CollisionData *data);
private:
	std::vector<Contact*> contacts;//A la base un array mais on préfère utiliser un vecteur
	int contactRestant;
};

