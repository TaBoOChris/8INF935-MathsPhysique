#include "CollisionData.h"

CollisionData::CollisionData() {
	this->contacts;
	this->contactRestant = 0;
}

void CollisionData::generateContact(Box* prim1, Plane* prim2) {
	this->contacts = std::vector<Contact*>();						// On initialise les Contacts

	Quaternion orientation = prim1->getBody()->getOrientation();	// On recup l'orientation

	// On definit les 8 points de notre cube
	std::vector<Vector3D*> eightpoints;
	eightpoints.push_back(new Vector3D(0.0f, 0.0f, 0.0f));
	eightpoints.push_back(new Vector3D(prim1->getHalfsize().x, 0.0f, 0.0f));
	eightpoints.push_back(new Vector3D(prim1->getHalfsize().x, prim1->getHalfsize().y, 0.0f));
	eightpoints.push_back(new Vector3D(0.0f, prim1->getHalfsize().y, 0.0f));
	eightpoints.push_back(new Vector3D(0.0f, 0.0f, prim1->getHalfsize().z));
	eightpoints.push_back(new Vector3D(prim1->getHalfsize().x, 0.0f, prim1->getHalfsize().z));
	eightpoints.push_back(new Vector3D(prim1->getHalfsize().x, prim1->getHalfsize().y, prim1->getHalfsize().z));
	eightpoints.push_back(new Vector3D(0.0f, prim1->getHalfsize().y, prim1->getHalfsize().z));


	// Pour chaque points, on applique la rotation
	for (Vector3D* vec : eightpoints)
	{
		*vec = *vec + prim1->getBody()->getPosition();
		*vec = *vec * prim1->getOffset();
		*vec = vec->rotateByQuaternion(orientation);
		float dist = prim2->getNormal().normalisation() * *vec;
		if (dist <= -prim2->getOffset()) {
			float interpenetration = dist + prim2->getOffset();
			Contact* res = new Contact(*vec, prim2->getNormal(), interpenetration);
			this->contacts.push_back(res);
		}
	}
}

void CollisionData::generateContact(Primitive* prim1, Primitive* prim2)
{
}

void CollisionData::printContact_console()
{
	int index = 1;
	for (Contact* contact : contacts)
	{
		std::cout << "contact " << index << " : " << std::endl;
		std::cout << *contact << std::endl;
		std::cout << "\n" << std::endl;

		index++;
	}
}

std::vector<Contact*> CollisionData::getContacts()
{
	return this->contacts;
}
