#pragma once


#include <iostream>
#include <string>
#include <stdio.h>
#include "Matrix3.h"
#include "Vecteur3D.h"
#include "Quaternion.h"


class Matrix4
{
public:
	
	float  	a00, a01, a02, a03;
	float  	a10, a11, a12, a13;
	float  	a20, a21, a22, a23;
	
	Matrix4();

	Matrix4(
		float a00, float a01, float a02, float a03,
		float a10, float a11, float a12, float a13,
		float a20, float a21, float a22, float a23) ;

	Matrix4(Matrix3 mat3, Vector3D vec);

	// Operateur --------------------------------------------------------------------------

	friend Matrix4 operator+(Matrix4 const& A, Matrix4 const& B);		// A + B
	friend Matrix4 operator-(Matrix4 const& A, Matrix4 const& B);		// A - B

	friend Matrix4 operator*(Matrix4 const& M, float const& a);			// M * a
	friend Matrix4 operator*(float const& a, Matrix4 const& M);			// a * M

	friend Vector3D operator*(Vector3D const& v, Matrix4 const& M);		// v * M
	friend Vector3D operator*(Matrix4 const& M, Vector3D const& v);		// M * v

	// Methodes principales -----------------------------------------------------------
	Matrix3 getAij(int i, int j);		// Retourne la matrice 3x3 demande
	Matrix3 getMatrix3();				// retourne la matrice 3x3
	Vector3D getVector3D();				// retourne le Vecteur 3D
	Matrix4 getInverse();				// retorune l'inverse de la matrice
	float det();						// retorune le determinant		

	Matrix4 setOrientation(Quaternion const& q);			// set l'orientation de la matrice
	Vector3D transformPosition(Vector3D vec);				// multiplie la matrice par un vecteur
	Vector3D transformInversePosition(Vector3D vec);


	// Affichage
	friend std::ostream& operator<<(std::ostream& os, Matrix4 const& M);
};

