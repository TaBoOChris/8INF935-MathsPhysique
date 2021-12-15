#pragma once

#include "Contact.h"
#include "Primitive.h"
#include "Box.h"
#include "Plane.h"
#include <vector>

class CollisionData
{
public:
	CollisionData();
	void generateContact(Box* prim1, Plane* prim2);
	void printContact_console();
	std::vector<Contact*> getContacts();
private:
	std::vector<Contact*> contacts;//A la base un array mais on préfère utiliser un vecteur
	int contactRestant;
};

