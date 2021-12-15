#pragma once

#include "../FormeIrreguliere.h"
#include "../Matrix4.h"

class Primitive
{
public:
	Primitive();
	Primitive(FormeIrreguliere body);

	Primitive(FormeIrreguliere body, Matrix4 offset);

private:
	CorpsRigide* Body;
	Matrix4 offset;

};

