#include "RegistreForces.h"

RegistreForces::RegistreForces(){
}

void RegistreForces::add(Particule *particule, ParticuleForceGenerator *fg) {
	EnregistrementForce tmp = { particule , fg };
	this->registre.push_back(tmp);
	return;
}

void RegistreForces::remove(Particule *particule, ParticuleForceGenerator *fg) {
	std::vector<EnregistrementForce>::iterator iter = this->registre.begin();
	for (size_t i = 0; i < this->registre.size(); i++)
	{
		if (((EnregistrementForce) *(iter+i)).fg == fg && ((EnregistrementForce) * (iter + i)).particule == particule)
		{
			this->registre.erase(iter + i);
			return;
		}
	}
	return;
}

void RegistreForces::updateAllForces(float duration) {

	// we get all force register and we update them
	for (EnregistrementForce force : registre)
	{
		force.fg->updateForce(force.particule, duration);
	}
}

int RegistreForces::getSize()
{
	return this->registre.size();
}
