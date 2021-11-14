#pragma once
class Matrix4
{
private: 

	float  	a00, a01, a02, a03;
	float  	a10, a11, a12, a13;
	float  	a20, a21, a22, a23;


public:
	Matrix4(
		float a00, float a01, float a02, float a03,
		float a10, float a11, float a12, float a13,
		float a20, float a21, float a22, float a23) ;



	friend Matrix4 operator+(Matrix4 const& A, Matrix4 const& B);		// A + B
	friend Matrix4 operator-(Matrix4 const& A, Matrix4 const& B);		// A - B

	friend Matrix4 operator*(Matrix4 const& M, float const& a);			// M * a
	friend Matrix4 operator*(float const& a, Matrix4 const& M);			// a * M

	friend Matrix4 operator/(Matrix4 const& M, float const& a);			// M / a

	friend Matrix4 operator*(Matrix4 const& A, Matrix4 const& B);		// A*B
};

