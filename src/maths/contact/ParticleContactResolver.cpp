#include "ParticleContactResolver.h"



void ParticleContactResolver::resolveContact(std::vector<ParticleContact*> contacts, float duree)
{
	float nbIterationMax = contacts.size() * 2;

	while (this->iteration < nbIterationMax) {

		float minVs = std::numeric_limits<float>::max();
		int vsFinalIndex = 0;
		int vsIndex = 0;

		for (ParticleContact* contact : contacts) {
			float newVs = contact->calculVs();

			if (newVs < minVs) {

				minVs = newVs;
				vsFinalIndex = vsIndex;
			}

			vsIndex++;
		}

		if (minVs >= 0 && !(contacts[vsFinalIndex]->getIsRod())) { return; }

		contacts[vsFinalIndex]->resolve(duree);

		if (minVs >= 0) { return; }

		this->iteration++;
	}

	//this->iteration = 0;
}
