#include <iostream>
#include "Vecteur3D.h"
#include "MoteurPhysique.h"
#include "ObjectToDraw.h"

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

    GLFWwindow* window = my_MoteurPhysique.initWindow();
    
    ObjectToDraw myObject;

    myObject.initialization();


    while (!glfwWindowShouldClose(window))
    {
        
        glClear(GL_COLOR_BUFFER_BIT);
        myObject.display();
        my_MoteurPhysique.display();
    }

    myObject.terminate();
    my_MoteurPhysique.terminate();

    return 0;
}

