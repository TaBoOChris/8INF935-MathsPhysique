#include "CollisionData.h"

CollisionData::CollisionData() {
	this->contacts;
	this->contactRestant = 0;
}

void CollisionData::generateContact(Primitive prim1, Primitive prim2, CollisionData* data) {

}

void CollisionData::printContact_console()
{
	for (Contact* contact : contacts)
	{
		std::cout << contact << std::endl;
		std::cout << "\n" << std::endl;
	}
}
