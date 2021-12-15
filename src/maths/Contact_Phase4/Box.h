#pragma once
#include "Primitive.h"
#include "Plane.h"

class Box :
    public Primitive
{
public:
    Box();
    Box(CorpsRigide* self, Vector3D halfsizes, Matrix4 matrix);
    

    Vector3D getHalfsize();
    Matrix4 getOffset();
    CorpsRigide* getBody();
    std::vector<Vector3D*> getPoints() { return points; }

    void setPoints(std::vector<Vector3D*> vect);

    Mesh mesh;		//Objet 3D
    void setMesh();									// construire le Mesh
    void Draw(Shader& shader, Camera& camera);		// Afficher le mesh
    void updateMesh();
private:
    Vector3D halfsizes;
    std::vector<Vector3D*> points;
};

