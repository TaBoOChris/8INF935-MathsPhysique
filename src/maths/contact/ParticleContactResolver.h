#pragma once
#include <vector>
#include <limits>
#include "ParticleContact.h"

class ParticleContactResolver
{
private :
	int iteration = 0;

public :
	// Determine l'ordre de resolutions des contacts dans le vecteur en fonction de leurs vitesse d'eloignement
	void resolveContact(std::vector<ParticleContact*> contacts, float duree);
};

