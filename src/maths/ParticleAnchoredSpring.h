#include "ParticuleForceGenerator.h"
#include "Vecteur3D.h"

class ParticleAnchoredSpring
{
public:
	ParticleAnchoredSpring(Vector3D anchor, float constElast, float lenRepos);
	~ParticleAnchoredSpring();
	void updateForce(Particule* particule);

private:
	Vector3D anchor;
	float K;
	float l0;
};

