#include <iostream>
#include "Vecteur3D.h"
#include "MoteurPhysique.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;




int main(void)
{
    Vector3D u(1, 4, 5);
    Vector3D v(2);

    cout << u.normalisation();

    //------------------------------

    MoteurPhysique my_MoteurPhysique;

    my_MoteurPhysique.initWindow();
    my_MoteurPhysique.display();

    return 0;
}

