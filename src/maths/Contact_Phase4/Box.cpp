#include "Box.h"

Box::Box()
{
}

Box::Box(CorpsRigide* self, Vector3D halfsizes, Matrix4 matrix)
{
	this->Body = self;
	this->halfsizes = halfsizes;
	this->offset = matrix;
}

Vector3D Box::getHalfsize()
{
	return this->halfsizes;
}

Matrix4 Box::getOffset()
{
	return this->offset;
}

CorpsRigide* Box::getBody()
{
	return this->Body;
}
