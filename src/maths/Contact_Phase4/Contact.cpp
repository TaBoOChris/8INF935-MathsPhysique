#include "Contact.h"

Contact::Contact(Vector3D contactPoint, Vector3D contactNormal, float penetration) {
	this->contactPoint = contactPoint;
	this->contactNormal = contactNormal;
	this->penetration = penetration;
}