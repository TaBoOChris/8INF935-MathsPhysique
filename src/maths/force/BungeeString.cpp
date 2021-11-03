#include "BungeeString.h"

BungeeString::BungeeString()
{
	this->anchorParticle = nullptr;
	this->K = 0.0f;
	this->l0 = 0.0f;
}

BungeeString::BungeeString(Particule* anchorParticle, float constElast, float lenRepos)
{
	this->anchorParticle = anchorParticle;
	this->K = constElast;
	this->l0 = lenRepos;
}

void BungeeString::updateForce(Particule* particule, float duration)
{
	float longueur = (particule->getPosition() - anchorParticle->getPosition()).norme();	// distance entre deux particule
	if (longueur <= l0) {											// si longueur repos < longeur, rien
		return;
	}
	Vector3D force = ( particule->getPosition() - anchorParticle->getPosition()).normalisation() *   K * (l0 - longueur);
	particule->addForce(force);
}
