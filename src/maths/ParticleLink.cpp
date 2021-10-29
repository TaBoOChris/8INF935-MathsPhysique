#include "ParticleLink.h"

float ParticleLink::currentLen() const
{
    return (this->particules[0]->getPosition() - this->particules[1]->getPosition()).norme();
}

ParticleLink::ParticleLink(Particule* partA, Particule* partB)
{
    this->particules[0] = partA;
    this->particules[1] = partB;
}
