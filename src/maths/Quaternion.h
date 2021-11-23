#ifndef QUATERNION_H
#define QUATERNION_H

#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */

#include"Vecteur3D.h"

class Quaternion
{

public:
	float x, y, z, w;

	Quaternion();

	Quaternion(float x, float y, float z, float w);
	
	friend Quaternion operator*(float f, Quaternion const& q);

	friend Quaternion operator+(Quaternion const& q1, Quaternion const& q2);

	friend Quaternion operator*(Quaternion const& q1, Quaternion const& q2);		// q1 * q2

	friend Quaternion operator/(Quaternion const& Q, float const& a);				// Q / a


	Quaternion negation();
	float norme();

	Quaternion conjugue();

	Quaternion inverse();

	void rotateByVector(class Vector3D v);
	void UpdateAngularVelocity(class Vector3D w, float duration);
};

#endif