#pragma once

#include "../FormeIrreguliere.h"
#include "../Matrix4.h"

class Primitive
{
public:
	Primitive();
	Primitive(FormeIrreguliere body);

private:
	CorpsRigide* Body;
	Matrix4 offset;

};

