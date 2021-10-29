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
	ParticleContact(Particule* partA, Particule* partB, float restCoeff, Vector3D normal);

	void resolve(float duree);
	float caculVs() const;
	void resolveVelocity(float duree);
	void resolveInterpenetration();
};

