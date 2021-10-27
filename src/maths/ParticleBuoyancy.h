#include "ParticuleForceGenerator.h"
#include "Vecteur3D.h"

class ParticleBuoyancy
{
public:
	ParticleBuoyancy(float maxDepth, float objVolume, float hauteurLiquide, float density);
	~ParticleBuoyancy();
	void updateForce(Particule* particule);

private:
	float maxDepth;
	float objVolume;
	float hauteurLiquide;
	float density;
};

