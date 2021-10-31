#include "Particule.h"
#include "Vecteur3D.h"

class ParticleContact
{
private:
	/* ParticuleContact est la collision entre deux particules*/
	Particule* particules[2];
	/* Coefficiant de restitution de la collision
	* v' = restitution * v
	* C = 1 : collision parfaitement élastique
	* C = 0 : collision parfaitement inélastique
	* 0 < C < 1 : collision élastique
	*/
	float restitution;
	/* Vecteur normal à la collision, par convention, par rapport à la particule A */
	Vector3D contactNormal;
	/* Coefficiant d'interpénétration */
	float penetration;

public:
	/* Constructeur de ParticuleContact */
	ParticleContact(Particule* partA, Particule* partB, float restCoeff, Vector3D normal);

	/* Appelle les fonctions resolveVelocity et resolveInterpenetration */
	void resolve(float duree);
	/* Calcul la vitesse d'éloignement de la collision 
	* Vs = (p.[0] - p.[1]) * normal
	*/
	float caculVs() const;
	void resolveVelocity(float duree);
	void resolveInterpenetration();
};

