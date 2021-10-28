#pragma once
#include <vector>
#include <limits>
#include "ParticleContact.h"

class ParticleContactResolver
{
private :
	int iteration = 0;

public :

	void resolveContact(std::vector<ParticleContact*> contacts, float duree);
};

