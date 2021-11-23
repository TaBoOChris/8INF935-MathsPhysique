#pragma once

#include "Vecteur3D.h"

Vector3D::Vector3D() 
{
    this->x = 0.0f;
    this->y = 0.0f;
    this->z = 0.0f;

}

Vector3D::Vector3D(float val) 
{
    this->x = val;
    this->y = val;
    this->z = val;
}

Vector3D::Vector3D(float new_X, float new_Y, float new_Z) 
{
    this->x = new_X;
    this->y = new_Y;
    this->z = new_Z;
}


bool operator==(Vector3D const& u, Vector3D const& v) 
{
    return(u.x == v.x && u.y == v.y && u.z == v.z);
    
}

Vector3D operator+(Vector3D const& u, Vector3D const& v) 
{
    return Vector3D(u.x + v.x, u.y + v.y , u.z + v.z);
}

Vector3D operator-(Vector3D const& u, Vector3D const& v) 
{
    return Vector3D(u.x - v.x, u.y - v.y , u.z - v.z);

}

Vector3D operator*(Vector3D const& u, float const& a) 
{
    return Vector3D(u.x*a, u.y*a,u.z*a);
}

Vector3D operator*(float const& a, Vector3D const& u)
{
    return Vector3D(u.x * a, u.y * a, u.z * a);
}

float operator*(Vector3D const& u, Vector3D const& v) 
{
    return ( u.x * v.x + u.y * v.y + u.z * v.z );
}

Vector3D & Vector3D::operator=(Vector3D const& u) 
{

    this->x = u.x;
    this->y = u.y;
    this->z = u.z;

    return *this;
    
}

float Vector3D::norme()const
{
    return sqrt(*this * *this);
}

Vector3D Vector3D::produitvectoriel(Vector3D const& u) const
{
    Vector3D res;

    res.x = this->y * u.z - u.y * this->z;
    res.y = this->z * u.x - u.z * this->x;
    res.z = this->x * u.y - u.x * this->y;
    
    return res;
}

bool Vector3D::estUnitaire() const
{
    return (this->norme() == 1 );
}

Vector3D Vector3D::normalisation() const
{
    return *this * (1/this->norme()) ;
}

Vector3D Vector3D::rotateByQuaternion(Quaternion q)         // rotate a vector by a Quaternion
{
    Quaternion vecQ = Quaternion(this->x, this->y, this->z, 0.0f);
    Quaternion q2 = q.conjugue();
    Quaternion rotQ = (q * vecQ) * q2;

    return Vector3D(rotQ.x, rotQ.y, rotQ.z);
}

ostream& operator<<(ostream& os,  Vector3D const& u) 
{
    os << "x = " << u.x <<endl;
    os << "y = " << u.y <<endl;
    os << "z = " << u.z <<endl;
    os << "norme = " << u.norme() <<endl;
    os << "Est unitaire = " << u.estUnitaire() <<endl;

    return os;
}
