#include "Plane.h"

Plane::Plane()
{
}

Plane::Plane(Vector3D normal, float offset)
{
	this->normal = normal;
	this->offset = offset;
}
