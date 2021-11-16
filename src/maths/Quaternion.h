#pragma once
#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */

#include "Vecteur3D.h"

class Quaternion
{

public:
	float x, y, z, w;

	Quaternion(float x, float y, float z, float w);
	
	friend Quaternion operator*(float f, Quaternion const& q);

	friend Quaternion operator+(Quaternion const& q1, Quaternion const& q2);

	friend Quaternion operator*(Quaternion const& q1, Quaternion const& q2);		// q1 * q2

	friend Quaternion operator/(Quaternion const& Q, float const& a);				// Q / a


	Quaternion negation();
	float norme();

	Quaternion conjugue();

	Quaternion inverse();

	void rotateByVector(Vector3D const& v);
	void UpdateAngularVelocity(Vector3D const& w, float duration);
};

