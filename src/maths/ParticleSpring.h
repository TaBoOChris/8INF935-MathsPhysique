#include "ParticuleForceGenerator.h"
#include "Vecteur3D.h"

class ParticleSpring :
    public ParticuleForceGenerator
{
public:
	ParticleSpring(Particule anchorParticle, float constElast, float lenRepos);
	~ParticleSpring();
	void updateForce(Particule* particule);

private:
	Particule anchorParticle;
	float K;
	float l0;
};

