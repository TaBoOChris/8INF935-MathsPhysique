#include "Contact.h"

Contact::Contact(Vector3D contactPoint, Vector3D contactNormal, float penetration) {
	this->contactPoint = contactPoint;
	this->contactNormal = contactNormal;
	this->penetration = penetration;
}

ostream& operator<<(ostream& os, Contact const& contact)
{
    os << "contactPoint : \n " << contact.contactPoint << endl;
    os << "contactNormal : \n " << contact.contactNormal << endl;
    os << "penetration =  " << contact.penetration << endl;

    return os;
}
