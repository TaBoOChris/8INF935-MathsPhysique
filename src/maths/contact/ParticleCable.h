#pragma once
#include "ParticleLink.h"
#include <vector>

class ParticleCable :
    public ParticleLink
{
private:
    // Longueur max du cable
    float maxLen;
    // Coefficiant de restitution du cable
    float restitution;

public:
    // Constructeur du cable
    ParticleCable(Particule* partA, Particule* partB, float maxLen, float rest);
    // Ajoute une ParticuleContact au vecteur si la distance entre les deux particules est plus grande que la distance max du cable
    void ajouterContact(std::vector<ParticleContact*> &particleContacts);
};

