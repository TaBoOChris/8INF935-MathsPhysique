#include "CollisionData.h"

CollisionData::CollisionData() {
	this->contacts;
	this->contactRestant = 0;
}

void CollisionData::generateContact(Primitive prim1, Primitive prim2, CollisionData* data) {

}

void CollisionData::printContact_console()
{
	int index = 1;
	for (Contact* contact : contacts)
	{
		std::cout << "contact " << index << " : " << std::endl;
		std::cout << contact << std::endl;
		std::cout << "\n" << std::endl;

		index++;
	}
}
