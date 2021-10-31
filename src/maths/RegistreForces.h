#include "ParticuleForceGenerator.h"
#include <vector>

class RegistreForces
{
public:
	// Constructeur du registre
	RegistreForces();

	// Crée une struct qui contient un generateur de force et la particule auquel il applique une force et l'ajoute au vecteur registre
	void add(Particule *particule, ParticuleForceGenerator *fg);
	// Retire du registre un generateur de force et la particule auquelle il s'applique.
	void remove(Particule *particule, ParticuleForceGenerator *fg);

	// Parcours le registre et appelle updateForce sur tous les generateurs de forces
	void updateAllForces(float duration);

	//renvoie la taille du registre
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
