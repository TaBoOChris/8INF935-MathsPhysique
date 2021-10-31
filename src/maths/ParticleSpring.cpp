#pragma once
#include "ParticleSpring.h"
#include "contact/ParticleContact.h"
#include <vector>


ParticleSpring::ParticleSpring(Particule* anchorParticle, float constElast, float lenRepos)
{
	this->anchorParticle = anchorParticle;
	this->K = constElast;
	this->l0 = lenRepos;
	this->lmax = -1.0f;
}

ParticleSpring::ParticleSpring(Particule* anchorParticle, float constElast, float lenRepos, float lmax)
{
	this->anchorParticle = anchorParticle;
	this->K = constElast;
	this->l0 = lenRepos;
	this->lmax = lmax;
}

void ParticleSpring::setLMax(float newLMax) {
	this->lmax = newLMax;
}

void ParticleSpring::updateForce(Particule* particule, float duration)
{
	float longueur = (particule->getPosition() - anchorParticle->getPosition()).norme();	// distance entre deux particule
	//Si lmax est setté et que la distance est au dessus de lmax
	if (lmax != -1.0f && longueur > lmax) {
		//On fait comme dans ParticuleCable
		Particule* partA = this->anchorParticle;
		Particule* partB = particule;
		ParticleContact* tmp;
		tmp = new ParticleContact(partA, partB, 1.0f);
		tmp->resolve(duration);
	}
	else {
		Vector3D force = (particule->getPosition() - anchorParticle->getPosition()).normalisation() * K * (l0 - longueur);
		particule->addForce(force);
	}
}
