#include "ParticleBuoyancy.h"

ParticleBuoyancy::ParticleBuoyancy(float maxDepth, float objVolume, float hauteurLiquide, float density)
{
	this->maxDepth = maxDepth;
	this->objVolume = objVolume;
	this->hauteurLiquide = hauteurLiquide;
	this->density = density;
}

ParticleBuoyancy::~ParticleBuoyancy()
{
}

void ParticleBuoyancy::updateForce(Particule* particule)
{
	float particleDepth = particule->getPosition().y;

	if (particleDepth <= this->maxDepth - this->hauteurLiquide)
	{
		particule->addForce(Vector3D(0, this->objVolume * this->density, 0));
	}

	else if (particleDepth >= this->maxDepth - this->hauteurLiquide && particleDepth <= this->maxDepth + this->hauteurLiquide)
	{
		float submergedPartDepth = particleDepth - this->hauteurLiquide - this->maxDepth;

		particule->addForce(Vector3D(0, submergedPartDepth * this->objVolume * this->density, 0));
	}

}
