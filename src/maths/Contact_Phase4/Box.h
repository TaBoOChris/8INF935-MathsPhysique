#pragma once
#include "Primitive.h"
#include "Plane.h"

class Box :
    public Primitive
{
private:
    Vector3D halfsizes;
    std::vector<Vector3D*> points;

public:
    Mesh mesh;		//Objet 3D

    // ------ Constructor ----------
    Box();
    Box(CorpsRigide* self, Vector3D halfsizes, Matrix4 matrix);
    
    // ------ Getters ----------
    Vector3D getHalfsize();
    Matrix4 getOffset();
    CorpsRigide* getBody();
    std::vector<Vector3D*> getPoints() { return points; }

    // ------ Setters ----------
    void setPoints(std::vector<Vector3D*> vect);
    void setMesh();									// construire le Mesh


    // ------ Methode  ----------
    void Draw(Shader& shader, Camera& camera);		// Afficher le mesh
    void updateMesh();
};

