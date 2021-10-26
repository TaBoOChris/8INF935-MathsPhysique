#include "Particule.h"

class ParticuleForceGenerator
{
private:
    
public:

    virtual void updateForce(Particule *particule, float duration)=0;

};
