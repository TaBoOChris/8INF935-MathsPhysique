#include "../Particule.h"
#include "../Vecteur3D.h"

class ParticleContact
{
private:
	Particule* particules[2];
	float restitution;
	Vector3D contactNormal;
	float penetration;

public:
	ParticleContact(Particule* partA, Particule* partB, float restCoeff);

	void calculNormal();
	void resolve(float duree);
	float calculVs();
	void resolveVelocity(float duree);
	void resolveInterpenetration();
};

