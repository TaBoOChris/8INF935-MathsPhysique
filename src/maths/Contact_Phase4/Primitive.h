#pragma once

#include "../FormeIrreguliere.h"
#include "../Matrix4.h"
#include "Contact.h"

class Primitive
{
public:
	Primitive();
	Primitive(FormeIrreguliere body);

private:
protected:
	CorpsRigide* Body;
	Matrix4 offset;

};

