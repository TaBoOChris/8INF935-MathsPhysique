#pragma once 

#include "../Particule.h"
#include "../Vecteur3D.h"

class ParticleContact
{
private:
	/* ParticuleContact est la collision entre deux particules*/
	Particule* particules[2];
	/* Coefficiant de restitution de la collision
	* v' = restitution * v
	* C = 1 : collision parfaitement elastique
	* C = 0 : collision parfaitement inelastique
	* 0 < C < 1 : collision elastique
	*/
	float restitution;
	/* Vecteur normal a la collision, par convention, par rapport � la particule A */
	Vector3D contactNormal;
	/* Coefficiant d'interpenetration */
	float penetration;

public:
	/* Constructeur de ParticuleContact */
	ParticleContact(Particule* partA, Particule* partB, float restCoeff);

	/* Calcul le vecteur normal a la collision */
	void calculNormal();

	/* Appelle les fonctions resolveVelocity et resolveInterpenetration */
	void resolve(float duree);
	/* Calcul la vitesse d'eloignement de la collision 
	* Vs = (p.[0] - p.[1]) * normal
	*/
	float calculVs();
	/* Calcul la vitesse d'eloignement de chaque particule en fonction de leur masse */
	void resolveVelocity(float duree);
	/* Modifie la position des particules en fonction de leur interpenetration */
	void resolveInterpenetration();
};

