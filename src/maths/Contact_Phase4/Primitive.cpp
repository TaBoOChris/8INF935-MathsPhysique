#include "Primitive.h"

Primitive::Primitive()
{
	this->Body = NULL;
	this->offset = Matrix4();
}

Primitive::Primitive(FormeIrreguliere body)
{
	this->Body = body.selfCorps;
	this->offset = Matrix4();
}

Primitive::Primitive(FormeIrreguliere body, Matrix4 offset)
{
	this->Body = body.selfCorps;
	this->offset = offset;
}
