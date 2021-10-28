#include "ParticleContactResolver.h"



void ParticleContactResolver::resolveContact(std::vector<ParticleContact*> contacts, float duree)
{
	float nbIterationMax = contacts.size() * 2;

	while (this->iteration < nbIterationMax) {

		float minVs = std::numeric_limits<float>::max();
		int vsFinalIndex = 0;
		int vsIndex = 0;

		for (ParticleContact* contact : contacts) {
			float newVs = contact->getVelociteEloignement();

			if (newVs < minVs) {

				minVs = newVs;
				vsFinalIndex = vsIndex;
			}

			vsIndex++;
		}

		if (minVs >= 0) { return; }

		contacts[vsFinalIndex]->resolve(duree);

		this->iteration++;
	}

}
