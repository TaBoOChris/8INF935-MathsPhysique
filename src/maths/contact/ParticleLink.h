#pragma once
#include "ParticleContactGenerator.h"
#include <vector>

class ParticleLink :
    public ParticleContactGenerator
{

protected:
    Particule* particules[2];

public:
    float currentLen() const;
    ParticleLink(Particule* partA, Particule* partB);

    void ajouterContact(std::vector<ParticleContact*> &particleContacts);
};

