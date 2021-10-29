#pragma once
#include <vector>
#include "../Particule.h"
#include "ParticleContact.h"

class ParticleContactGenerator
{
public:
	virtual void ajouterContact(std::vector<ParticleContact*> particleContacts) = 0;
};

