#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "Vecteur3D.h"
#include "MoteurPhysique.h"
#include "ObjectToDraw.h"
#include "Camera.h"

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
    
    glEnable(GL_DEPTH_TEST);
    
    ObjectToDraw myObject;
    
    Shader shaderProgram ("default.vert", "default.frag");	// Gen Shader obj with shaders default.vert and default.frag

    myObject.initialization(shaderProgram);
    

    Camera camera(WINDOW_WIDTH, WINDOW_HEIGHT,glm::vec3(0.0f,0.0f,2.0f));

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderProgram.activate();	// Telle OpenGL wich shader we want to use
        
        myObject.display();

        camera.Inputs(window);
        camera.Matrix(45.0f, 0.1f, 100.0f, shaderProgram, "camMatrix");

        my_MoteurPhysique.display();
    }

    myObject.terminate();

    
    shaderProgram.terminate();
    my_MoteurPhysique.terminate();

    return 0;
}

