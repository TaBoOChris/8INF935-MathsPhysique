#pragma once
#include "ParticleLink.h"
#include <vector>

class ParticleRod :
    public ParticleLink
{
private:
    // Longueur de la tige
    float len;

public:
    ParticleRod(Particule* partA, Particule* partB, float len);

    // Ajoute constament une particule contact au vecteur
    void ajouterContact(std::vector<ParticleContact*> &particleContacts);
};

