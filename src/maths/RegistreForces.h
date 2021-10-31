#include "ParticuleForceGenerator.h"
#include <vector>

class RegistreForces
{
public:
	RegistreForces();

	void add(Particule *particule, ParticuleForceGenerator *fg);	// add a force on particule
	void remove(Particule *particule, ParticuleForceGenerator *fg);
	void updateAllForces(float duration);

	int getSize();

private:
	// Definition de la structure particule <-> Générateur de Force
	typedef struct EnregistrementForceStruct {
		Particule *particule;
		ParticuleForceGenerator *fg;	// main class for gravity, drag , bungee
	} EnregistrementForce;

	// Définition du registre vecteur contenant les structures Particule <-> Générateur de Force
	std::vector<EnregistrementForce> registre;
};
