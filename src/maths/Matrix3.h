#pragma once

#include <iostream>
#include <string>
#include <stdio.h>

class Matrix3
{
private:
	float  	a00, a01, a02 ;
	float  	a10, a11, a12 ;
	float  	a20, a21, a22 ;

public : 

	Matrix3(
		float a00, float a01, float a02,
		float a10, float a11, float a12,
		float a20, float a21, float a22);

	friend Matrix3 operator+(Matrix3 const& A, Matrix3 const& B);		// A + B
	friend Matrix3 operator-(Matrix3 const& A, Matrix3 const& B);		// A - B

	friend Matrix3 operator*(Matrix3 const& M, float const& a);			// M * a
	friend Matrix3 operator*(float const& a, Matrix3 const& M);			// a * M
	
	friend Matrix3 operator/(Matrix3 const& M, float const& a);			// M / a

	friend Matrix3 operator*(Matrix3 const& A, Matrix3 const& B);		// A*B


	float getDeterminant();
	bool isInvertible();
	Matrix3 getTranspose();
	Matrix3 getAdjoint();
	Matrix3 getInverse();

	friend std::ostream& operator<<(std::ostream& os, Matrix3 const& M);

};

