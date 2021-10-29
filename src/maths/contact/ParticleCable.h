#pragma once
#include "ParticleLink.h"
#include <vector>

class ParticleCable :
    public ParticleLink
{
private:
    float maxLen;
    float restitution;

public:
    ParticleCable(Particule* partA, Particule* partB, float maxLen, float rest);

    void ajouterContact(std::vector<ParticleContact*> particleContacts);
};

