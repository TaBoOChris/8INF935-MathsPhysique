#include "Matrix3.h"

Matrix3::Matrix3(
	float a00, float a01, float a02, 
	float a10, float a11, float a12, 
	float a20, float a21, float a22)
{
	this->a00 = a00;
	this->a01 = a01;
	this->a02 = a02;

	this->a10 = a10;
	this->a11 = a11;
	this->a12 = a12;

	this->a20 = a20;
	this->a21 = a21;
	this->a22 = a22;
}

float Matrix3::getDeterminant()
{
	return a00 * ( a11 * a22 - a21 * a12) - a01 * (a10 * a22 - a20 * a12) + a02 * (a10 * a21 - a20 * a11);
}

bool Matrix3::isInvertible()
{
	return getDeterminant() != 0;
}

Matrix3 Matrix3::getTranspose()
{
	return Matrix3(
		a00, a10, a20,
		a01, a11, a21,
		a02, a12, a22);
}

Matrix3 Matrix3::getAdjoint()
{
	return Matrix3(
		a11 * a22 - a21 * a12,				-1*( a10 * a22 - a20 * a12),            a10 * a21 - a20 * a11,
		-1 * (a01 * a22 - a21 * a02),		a00 * a22 - a20 * a02,					-1 * (a00 * a21 - a20 * a01),
		a01 * a12 - a11 * a02,				-1 * (a00 * a12 - a10 * a02),			a00 * a11 - a10 * a01 );
}

Matrix3 Matrix3::getInverse()
{
	return getAdjoint() / getDeterminant();
}



Matrix3 operator+(Matrix3 const& A, Matrix3 const& B)
{
	return Matrix3(
		A.a00 + B.a00, A.a01 + B.a01, A.a02 + B.a02,
		A.a10 + B.a10, A.a11 + B.a11, A.a12 + B.a12,
		A.a20 + B.a20, A.a21 + B.a21, A.a22 + B.a22);
}

Matrix3 operator-(Matrix3 const& A, Matrix3 const& B)
{
	return Matrix3(
		A.a00 - B.a00, A.a01 - B.a01, A.a02 - B.a02,
		A.a10 - B.a10, A.a11 - B.a11, A.a12 - B.a12,
		A.a20 - B.a20, A.a21 - B.a21, A.a22 - B.a22);
}

Matrix3 operator*(Matrix3 const& M, float const& a)
{
	return Matrix3(
		M.a00 * a, M.a01 * a, M.a02 * a,
		M.a10 * a, M.a11 * a, M.a12 * a, 
		M.a20 * a, M.a21 * a, M.a22 * a );
}

Matrix3 operator*(float const& a, Matrix3 const& M)
{
	return Matrix3( M * a);
}

Matrix3 operator/(Matrix3 const& M, float const& a)
{
	return Matrix3(M * (1/a));
}


Matrix3 operator*(Matrix3 const& A, Matrix3 const& B)
{
	return Matrix3(
		A.a00 * B.a00 + A.a01 * B.a10 + A.a02 * B.a20,		A.a00 * B.a01 + A.a01 * B.a11 + A.a02 * B.a21,		A.a00 * B.a02 + A.a01 * B.a12 + A.a02 * B.a22,
		A.a10 * B.a00 + A.a11 * B.a10 + A.a12 * B.a20,		A.a10 * B.a01 + A.a11 * B.a11 + A.a12 * B.a21,		A.a10 * B.a02 + A.a11 * B.a12 + A.a12 * B.a22,
		A.a20 * B.a00 + A.a21 * B.a10 + A.a22 * B.a20,		A.a20 * B.a01 + A.a21 * B.a11 + A.a22 * B.a21,		A.a20 * B.a02 + A.a21 * B.a12 + A.a22 * B.a22  );
}

Vector3D operator*(Vector3D const& v, Matrix3 const& M)
{
	return Vector3D(
		M.a00 * v.x + M.a01 * v.y + M.a02 * v.z ,
		M.a10 * v.x + M.a11 * v.y + M.a12 * v.z ,
		M.a20 * v.x + M.a21 * v.y + M.a22 * v.z 
	);
}

Vector3D operator*(Matrix3 const& M, Vector3D const& v)
{
	return (v * M);
}

std::ostream& operator<<(std::ostream& os, Matrix3 const& M)
{
	os << " " << M.a00 << " " << M.a01 << " " << M.a02  << std::endl;
	os << " " << M.a10 << " " << M.a11 << " " << M.a12  << std::endl;
	os << " " << M.a20 << " " << M.a21 << " " << M.a22  << std::endl;

	return os;
}
