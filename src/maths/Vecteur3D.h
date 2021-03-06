#ifndef VECTEUR3D_H
#define VECTEUR3D_H


#include <iostream>
#include <string>
#include <stdio.h>
#include <math.h>       /* sqrt */

#include "Quaternion.h"

using namespace std;

class Vector3D{
    private :


    public :

        float x;
        float y;
        float z;

        Vector3D();
        Vector3D(float val);
        Vector3D(float new_X, float new_Y, float new_Z);

        


        friend bool operator==(Vector3D const& u, Vector3D const& v);
        friend Vector3D operator+(Vector3D const& u, Vector3D const& v);
        friend Vector3D operator-(Vector3D const& u, Vector3D const& v);

        friend Vector3D operator*(Vector3D const& u, float const& a);
        friend Vector3D operator*(float const& a, Vector3D const& u);

        friend float operator*(Vector3D const& u, Vector3D const& v);
        
        Vector3D & operator=(Vector3D const& u);

        float norme() const;
        
        Vector3D produitvectoriel(Vector3D const& u)const;

        bool estUnitaire() const;

        Vector3D normalisation()const;

        Vector3D rotateByQuaternion(class Quaternion q);

        friend ostream& operator<<(ostream& os,  Vector3D const& u);


};

#endif