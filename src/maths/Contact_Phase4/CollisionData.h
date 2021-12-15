#pragma once

#include "Contact.h"
#include "Primitive.h"
#include "Box.h"
#include "Plane.h"
#include <vector>

class CollisionData
{
private:
	std::vector<Contact*> contacts;//A la base un array mais on préfère utiliser un vecteur
	int contactRestant;

public:

	// ------ Constructor ----------
	CollisionData();

	// ------ Getters ----------
	std::vector<Contact*> getContacts();

	// ------ Methode  ----------
	void generateContact(Box* prim1, Plane* prim2);				// Generate Contact with Box and plan
	void generateContact(Primitive* prim1, Primitive* prim2);	// Generate Contact between 2 primitives	


	// ------ Print  ----------
	void printContact_console();								
};

