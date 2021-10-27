#include "ParticuleForceGenerator.h"
#include "Vecteur3D.h"

class BungeeString
{
public:
	BungeeString(Particule anchorParticle, float constElast, float lenRepos);
	~BungeeString();
	void updateForce(Particule* particule);

private:
	Particule anchorParticle;
	float K;
	float l0;
};

