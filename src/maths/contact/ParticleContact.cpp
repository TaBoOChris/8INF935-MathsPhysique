#include "ParticleContact.h"

ParticleContact::ParticleContact(Particule* partA, Particule* partB, float restCoeff)
{
	this->particules[0] = partA;
	this->particules[1] = partB;
	this->restitution = restCoeff;
	this->calculNormal();
	this->penetration = 0.0f;
}

void ParticleContact::setPenetration(float newpenetration) {
	this->penetration = newpenetration;

}

void ParticleContact::calculNormal()
{
	this->contactNormal = (particules[0]->getPosition() - particules[1]->getPosition()).normalisation();

}

void ParticleContact::resolve(float duree)
{
	/*std::cout << "start Resolve \n";
	std::cout << "vs = " << calculVs() << "\n";*/

	calculNormal();

	/*if (this->penetration > 0.0f) {
	}*/
	resolveInterpenetration();
	resolveVelocity(duree);
}

float ParticleContact::calculVs()
{
	return (particules[0]->getVitesse() - particules[1]->getVitesse())*contactNormal;
}

void ParticleContact::resolveVelocity(float duree)
{
	Particule* partA = this->particules[0];
	Particule* partB = this->particules[1];

	float Vs = calculVs();
	float Vsp = -this->restitution * Vs;
	Vector3D impulsionA = Vsp * this->contactNormal;
	Vector3D impulsionB = -Vsp * this->contactNormal;

	Vector3D vitA = partA->getVitesse() + partA->getInverseMasse() * impulsionA;
	//std::cout << "vitesseA : " << vitA << " Impulsion : " << impulsionA << "\n";
	this->particules[0]->setVitesse(vitA);

	Vector3D vitB = partB->getVitesse() + partB->getInverseMasse() * impulsionB;
	//std::cout << "vitesseB : " << vitB <<" Impulsion : " << impulsionB<< "\n";

	this->particules[1]->setVitesse(vitB);
}

void ParticleContact::resolveInterpenetration()
{
	float invMasseA = this->particules[0]->getInverseMasse();
	float invMasseB = this->particules[1]->getInverseMasse();

	// on isole les cas nuls, dans tout les autres on inverse invMasse pour obtenir la masse utilis�e dans la formule

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
