#include "Particule.h"
#include "Vecteur3D.h"

class ParticleContact
{
private:
	/* ParticuleContact est la collision entre deux particules*/
	Particule* particules[2];
	/* Coefficiant de restitution de la collision
	* v' = restitution * v
	* C = 1 : collision parfaitement �lastique
	* C = 0 : collision parfaitement in�lastique
	* 0 < C < 1 : collision �lastique
	*/
	float restitution;
	/* Vecteur normal � la collision, par convention, par rapport � la particule A */
	Vector3D contactNormal;
	/* Coefficiant d'interp�n�tration */
	float penetration;

public:
	/* Constructeur de ParticuleContact */
	ParticleContact(Particule* partA, Particule* partB, float restCoeff, Vector3D normal);

	/* Appelle les fonctions resolveVelocity et resolveInterpenetration */
	void resolve(float duree);
	/* Calcul la vitesse d'�loignement de la collision 
	* Vs = (p.[0] - p.[1]) * normal
	*/
	float caculVs() const;
	void resolveVelocity(float duree);
	void resolveInterpenetration();
};

