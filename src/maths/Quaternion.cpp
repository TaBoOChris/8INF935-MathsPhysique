#include "Quaternion.h"

Quaternion::Quaternion() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 0;
}

Quaternion::Quaternion(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;

}

Quaternion Quaternion::negation()
{
	return Quaternion(-this->x, -this->y,-this->z, -this->w);
}

float Quaternion::norme()
{
	return sqrt( pow(this->w, 2) + pow(this->x, 2)+ pow(this->y, 2)+ pow(this->z, 2));
}

void Quaternion::normalize()
{
	this->x = this->x / this->norme();
	this->y = this->y / this->norme();
	this->z= this->z/ this->norme();
	this->w= this->w / this->norme();
}

Quaternion Quaternion::conjugue()
{
	return Quaternion(-this->x, -this->y, -this->z, this->w);
}

Quaternion Quaternion::inverse()
{
	return Quaternion( this->conjugue() / this->norme());
}

void Quaternion::rotateByVector(Vector3D v)
{
	Quaternion q(0, v.x, v.y, v.z);
	(*this) = (*this) * q;
}

void Quaternion::UpdateAngularVelocity(Vector3D w, float duration)
{
	(*this) = (*this) + (1 / 2) * (duration * Quaternion(w.x, w.y, w.z, 0.0f) * (*this));
}

Quaternion operator*(float f, Quaternion const& q)
{
	return Quaternion(f*q.x, f*q.y, f*q.z, f*q.w);
}

Quaternion operator+(Quaternion const& q1, Quaternion const& q2)
{
	return Quaternion(q1.x+q2.x, q1.y+q2.y, q1.z+q2.z, q1.w+q2.w);
}

Quaternion operator*(Quaternion const& q1, Quaternion const& q2)
{
	//t1 = (r0   q1   + r1     q0    - r2   q3  +  r3   q2)
	//t2 = (r0   q2   + r1     q3    + r2   q0  -  r3   q1)
	//t3 = (r0   q3   - r1     q2    + r2   q1  +  r3   q0)
	return Quaternion(
		q1.w * q2.x + q1.x * q2.w - q1.y*q2.z + q1.z*q2.y,
		q1.w * q2.y + q1.x * q2.z + q1.y*q2.w - q1.z*q2.x,
		q1.w * q2.z - q1.x * q2.y + q1.y*q2.x + q1.z*q2.w,

		q1.w * q2.w - q1.x * q2.x - q1.y*q2.y - q1.z*q2.z
	);
}

Quaternion operator/(Quaternion const& Q, float const& a)
{
	// TODO
	return Q;
}

std::ostream& operator<<(std::ostream& os, Quaternion const& Q)
{
	os << " x=" << Q.x << " y=" << Q.y << " z=" << Q.z << " w=" << Q.w << std::endl;

	return os;
}
