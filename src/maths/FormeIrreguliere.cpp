#include "FormeIrreguliere.h"

FormeIrreguliere::FormeIrreguliere()
{
	pt0 = Vector3D(-1, -1, -1);
	allPoints.push_back(&pt0);
	pt1 = Vector3D(-1, -1, 1);
	allPoints.push_back(&pt1);
	pt2 = Vector3D(-1, 1, 1);
	allPoints.push_back(&pt2);
	pt3 = Vector3D(-1, 1, -1);
	allPoints.push_back(&pt3);
	pt4 = Vector3D(1, -1, -1);
	allPoints.push_back(&pt4);
	pt5 = Vector3D(1, -1, 1);
	allPoints.push_back(&pt5);
	pt6 = Vector3D(1, 1, 1);
	allPoints.push_back(&pt6);
	pt7 = Vector3D(1, 1, -1);
	allPoints.push_back(&pt7);

	selfCorps = new CorpsRigide();

	Matrix3* inertiaTensor = new Matrix3(
		8.0f / 12.0f, 0.0f, 0.0f,
		0.0f, 8.0f / 12.0f, 0.0f,
		0.0f, 0.0f, 8.0f / 12.0f
	);

	selfCorps->setInverseInertiaTensor(inertiaTensor->getInverse());
}

void FormeIrreguliere::updateAllPoint(float temps) {
	Quaternion* ptr_orientation = &this->selfCorps->getOrientation();

	for (Vector3D* pt : allPoints) {
		pt->rotateByQuaternion(ptr_orientation);
	}
}