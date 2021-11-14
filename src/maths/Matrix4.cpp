#include "Matrix4.h"

Matrix4::Matrix4(
	float a00, float a01, float a02, float a03, 
	float a10, float a11, float a12, float a13, 
	float a20, float a21, float a22, float a23)
{

	this->a00 = a00;
	this->a01 = a01;
	this->a02 = a02;
	this->a03 = a03;

	this->a10 = a10;
	this->a11 = a11;
	this->a12 = a12;
	this->a13 = a13;

	this->a20 = a20;
	this->a21 = a21;
	this->a22 = a22;
	this->a23 = a23;
}

Matrix4 operator+(Matrix4 const& A, Matrix4 const& B)
{
	return Matrix4(
		A.a00 + B.a00, A.a01 + B.a01, A.a02 + B.a02, A.a03 + B.a03,
		A.a10 + B.a10, A.a11 + B.a11, A.a12 + B.a12, A.a13 + B.a13,
		A.a20 + B.a20, A.a21 + B.a21, A.a22 + B.a22, A.a23 + B.a23);
}

Matrix4 operator-(Matrix4 const& A, Matrix4 const& B)
{
	return Matrix4(
		A.a00 - B.a00, A.a01 - B.a01, A.a02 - B.a02, A.a03 - B.a03,
		A.a10 - B.a10, A.a11 - B.a11, A.a12 - B.a12, A.a13 - B.a13,
		A.a20 - B.a20, A.a21 - B.a21, A.a22 - B.a22, A.a23 - B.a23);
}

Matrix4 operator*(Matrix4 const& M, float const& a)
{
	return Matrix4(
		M.a00 * a, M.a01 * a, M.a02 * a, M.a03 * a,
		M.a10 * a, M.a11 * a, M.a12 * a, M.a13 * a,
		M.a20 * a, M.a21 * a, M.a22 * a, M.a23 * a );
}

Matrix4 operator*(float const& a, Matrix4 const& M)
{
	return Matrix4(M * a);
}
