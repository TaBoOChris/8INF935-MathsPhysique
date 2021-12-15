#include "Plane.h"

Plane::Plane()
{
}

Plane::Plane(Vector3D normal, float offset)
{
	this->normal = normal;
	this->offset = offset;
}

Vector3D Plane::getNormal()
{
	return this->normal;
}

float Plane::getOffset()
{
	return this->offset;
}
