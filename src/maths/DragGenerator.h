#include "ParticuleForceGenerator.h"
#include "Vecteur3D.h"

class DragGenerator : public ParticuleForceGenerator
{
public:
	DragGenerator();
	DragGenerator(float k1, float k2);
	~DragGenerator();
	void updateForce(Particule* particule, float duration);

private:
	float k1;
	float k2;
};
