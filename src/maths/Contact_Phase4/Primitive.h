#pragma once

#include "../FormeIrreguliere.h"
#include "../Matrix4.h"
#include "Contact.h"

class Primitive
{
public:
	Primitive();
	Primitive(FormeIrreguliere body);
	virtual Contact contact(Primitive other);

private:
protected:
	CorpsRigide* Body;
	Matrix4 offset;

};

