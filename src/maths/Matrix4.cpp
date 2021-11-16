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

Matrix4::Matrix4(Matrix3 mat3, Vector3D vec)
{
	this->a00 = mat3.a00;
	this->a01 = mat3.a01;
	this->a02 = mat3.a02;
	this->a03 = vec.x;
				
	this->a10 = mat3.a10;
	this->a11 = mat3.a11;
	this->a12 = mat3.a12;
	this->a13 = vec.y;
				
	this->a20 = mat3.a20;
	this->a21 = mat3.a21;
	this->a22 = mat3.a22;
	this->a23 = vec.z;
}

Matrix3 Matrix4::getAij(int i, int j)
{
	switch(i){
	case 0: switch (j) {
	case 0:	return Matrix3(a11, a12, a13, a21, a22, a23, 0, 0, 1);
	case 1:	return Matrix3(a10, a12, a13, a20, a22, a23, 0, 0, 1);
	case 2:	return Matrix3(a10, a11, a13, a20, a21, a23, 0, 0, 1);
	case 3:	return Matrix3(a10, a11, a12, a20, a21, a22, 0, 0, 0);
	}
	case 1: switch (j) {
	case 0:	return Matrix3(a01, a02, a03, a21, a22, a23, 0, 0, 1);
	case 1:	return Matrix3(a00, a02, a03, a20, a22, a23, 0, 0, 1);
	case 2:	return Matrix3(a00, a01, a03, a20, a21, a23, 0, 0, 1);
	case 3:	return Matrix3(a00, a01, a02, a20, a21, a22, 0, 0, 0);
	}
	case 2: switch (j) {
	case 0:	return Matrix3(a01, a02, a03, a11, a12, a13, 0, 0, 1);
	case 1:	return Matrix3(a00, a02, a03, a10, a12, a13, 0, 0, 1);
	case 2:	return Matrix3(a00, a01, a03, a10, a11, a13, 0, 0, 1);
	case 3:	return Matrix3(a00, a01, a02, a10, a11, a12, 0, 0, 0);
	}
	case 3: switch (j) {
	case 0:	return Matrix3(a01, a02, a03, a11, a12, a13, a21, a22, a23);
	case 1:	return Matrix3(a00, a02, a03, a10, a12, a13, a20, a22, a23);
	case 2:	return Matrix3(a00, a01, a03, a10, a11, a13, a20, a21, a23);
	case 3:	return Matrix3(a00, a01, a02, a10, a11, a12, a20, a21, a22);
	}
	}
}

Matrix3 Matrix4::getMatrix3()
{
	return Matrix3(
		 a00,  a01,  a02,
		 a10,  a11,  a12,
		 a20,  a21,  a22);
}

Vector3D Matrix4::getVector3D()
{
	return Vector3D(a03,a13,a23);
}

Matrix4 Matrix4::getInverse()
{
	Matrix3 matrixInv = this->getMatrix3().getInverse();
	Vector3D vector = -1 * matrixInv * this->getVector3D();

	return Matrix4(matrixInv, vector);
}

Matrix4 Matrix4::setOrientation(Quaternion const& q)
{
	float a00 = 1 - (2 * pow(q.y, 2) + pow(q.z, 2));
	float a01 = 2 * (q.x * q.y + q.z * q.w);
	float a02 = 2 * (q.x * q.z - q.y * q.w);
	float a10 = 2 * (q.x * q.y - q.z * q.w);
	float a11 = 1 - 2 * (pow(q.x, 2) + pow(q.z, 2));
	float a12 = 2 * (q.y * q.z + q.x * q.w);
	float a20 = 2 * (q.x * q.z + q.y * q.w);
	float a21 = 2 * (q.y * q.z - q.x * q.w);
	float a22 = 1 - 2 * (pow(q.x, 2) + pow(q.y, 2));
	return Matrix4(a00, a01, a02, q.x,
				a10, a11, a12, q.y,
				a20, a21, a22, q.z);
}

float Matrix4::det()
{
	float res = 0;
	float mat[16] = { a00, a01, a02, a03, a10, a11, a12, a13, a20, a21, a22, a23, 0.0f, 0.0f, 0.0f, 1.0f };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Matrix3 tmp = getAij(i, j);
			res += pow((-1), (i + j)) * mat[i*4 + j] * tmp.getDeterminant();
		}
	}
	return res;
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

Vector3D operator*(Vector3D const& v, Matrix4 const& M)
{
	return Vector3D(
		M.a00 * v.x + M.a01* v.y + M.a02 *v.z + M.a03,
		M.a10 * v.x + M.a11* v.y + M.a12 *v.z + M.a13,
		M.a20 * v.x + M.a21* v.y + M.a22 *v.z + M.a23
	);
}

Vector3D operator*(Matrix4 const& M, Vector3D const& v)
{
	return (v * M);
}

std::ostream& operator<<(std::ostream& os, Matrix4 const& M)
{
	os << " " << M.a00 << " " << M.a01 << " " << M.a02 << " " << M.a03 << std::endl;
	os << " " << M.a10 << " " << M.a11 << " " << M.a12 << " " << M.a13 << std::endl;
	os << " " << M.a20 << " " << M.a21 << " " << M.a22 << " " << M.a23 << std::endl;

	return os;
}


