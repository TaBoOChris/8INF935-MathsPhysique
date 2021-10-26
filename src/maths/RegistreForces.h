#include "ParticuleForceGenerator.h"
#include <vector>

class RegistreForces
{
public:
	RegistreForces();
	~RegistreForces();
	void add(Particule *particule, ParticuleForceGenerator *fg);
	void remove(Particule* particule, ParticuleForceGenerator* fg);
	void updateAllForces(float duration);


private:
	// Definition de la structure particule <-> G�n�rateur de Force
	typedef struct EnregistrementForceStruct {
		Particule *particule;
		ParticuleForceGenerator *fg;
	} EnregistrementForce;

	// D�finition du registre vecteur contenant les structures Particule <-> G�n�rateur de Force
	std::vector<EnregistrementForce> registre;
};
