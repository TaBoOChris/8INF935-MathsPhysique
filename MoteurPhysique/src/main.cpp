#include <iostream>
#include "Vecteur3D.h"
#include "MoteurPhysique.h"
#include "ObjectToDraw.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>



using namespace std;

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800


int main(void)
{
    Vector3D u(1, 4, 5);
    Vector3D v(2);

    cout << u.normalisation();

    //------------------------------

    MoteurPhysique my_MoteurPhysique; 

    GLFWwindow* window = my_MoteurPhysique.initWindow(WINDOW_WIDTH, WINDOW_HEIGHT);
    
    ObjectToDraw myObject;

    myObject.initialization();


    while (!glfwWindowShouldClose(window))
    {
        
        
        myObject.display();



        my_MoteurPhysique.display();
    }

    myObject.terminate();
    my_MoteurPhysique.terminate();

    return 0;
}

