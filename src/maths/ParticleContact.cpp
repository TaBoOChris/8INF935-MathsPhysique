#include "ParticleContact.h"

ParticleContact::ParticleContact(Particule* partA, Particule* partB, float restCoeff, Vector3D normal)
{
	this->particules[0] = partA;
	this->particules[1] = partB;
	this->restitution = restCoeff;
	this->contactNormal = normal;
}

void ParticleContact::resolve(float duree)
{
	resolveInterpenetration();
	resolveVelocity(duree);
}

float ParticleContact::caculVs() const
{
	return (particules[0]->getVitesse() - particules[1]->getVitesse())*contactNormal;
}

void ParticleContact::resolveVelocity(float duree)
{
	Particule* partA = this->particules[0];
	Particule* partB = this->particules[1];

	float Vs = caculVs();
	float Vsp = -this->restitution * Vs;
	Vector3D impulsionA = Vsp * this->contactNormal;
	Vector3D impulsionB = -Vsp * this->contactNormal;

	Vector3D vitA = partA->getVitesse() + partA->getInverseMasse() * impulsionA;
	this->particules[0]->setVitesse(vitA);

	Vector3D vitB = partB->getVitesse() + partB->getInverseMasse() * impulsionB;
	this->particules[1]->setVitesse(vitB);
}

void ParticleContact::resolveInterpenetration()
{
	float invMasseA = this->particules[0]->getInverseMasse();
	float invMasseB = this->particules[1]->getInverseMasse();

	// on isole les cas nuls, dans tout les autres on inverse invMasse pour obtenir la masse utilisée dans la formule

	if (invMasseA == 0) {
		this->particules[1]->setPosition(this->particules[1]->getPosition() - this->penetration * this->contactNormal);
	}
	else if (invMasseB == 0) {
		this->particules[0]->setPosition(this->particules[0]->getPosition() + this->penetration * this->contactNormal);
	}
	else {
		float masseA = (this->particules[0]->getMasse() == -1.0f) ? 1 / invMasseA : this->particules[0]->getMasse();
		float masseB = (this->particules[0]->getMasse() == -1.0f) ? 1 / invMasseB : this->particules[1]->getMasse();

		float deltapA = masseA / (masseA + masseB) * penetration;
		float deltapB = masseB / (masseA + masseB) * penetration;

		this->particules[0]->setPosition(this->particules[0]->getPosition() + deltapA * this->contactNormal);
		this->particules[1]->setPosition(this->particules[1]->getPosition() - deltapB * this->contactNormal);
	}
}
