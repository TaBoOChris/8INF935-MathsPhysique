#pragma once

#include "../FormeIrreguliere.h"
#include "../Matrix4.h"
#include "Contact.h"

class Primitive
{

protected:
	CorpsRigide* Body;
	Matrix4 offset;


public:
	Primitive();
	Primitive(FormeIrreguliere body);

};

