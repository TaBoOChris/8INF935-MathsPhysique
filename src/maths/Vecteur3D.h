#pragma once

#include <iostream>
#include <string>
#include <stdio.h>

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
        ~Vector3D();

        


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


        friend ostream& operator<<(ostream& os,  Vector3D const& u);


};