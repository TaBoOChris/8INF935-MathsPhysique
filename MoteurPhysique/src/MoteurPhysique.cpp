#include "MoteurPhysique.h"
#include "Vecteur3D.h"

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>




GLFWwindow* MoteurPhysique::initWindow(int windowWidth, int windowHeight)
{
    /* Initialize the library */
    if (!glfwInit())
        return NULL;


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  // using OpenGL 3 for Major Version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);  // using OpenGL 3 for Minor Version
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // using Core profile ( with modern functions )


    /* Create a windowed mode window and its OpenGL context */
    this->m_window = glfwCreateWindow(800, 800, "Moteur Physique OpenGL", NULL, NULL);
    if (!this->m_window)
    {
        std::cout << "fail to create Window" << std::endl;
        glfwTerminate();
        return NULL;
    }

    glfwMakeContextCurrent(this->m_window);     // Make the window's context current 

    //gladLoadGL();

    /* Glew Init*/
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));

    }

    glViewport(0, 0, windowWidth, windowHeight); // specify the viewport of openGL in the window
    glClearColor(0.17f, 0.13f, 0.17f, 1.0f); // color of the background
    glClear(GL_COLOR_BUFFER_BIT); // clean the back buffer and assign new color
    glfwSwapBuffers(m_window); // swap the back buffer with the front buffer


    glfwSetMouseButtonCallback(this->m_window, &MoteurPhysique::mouse_button_callback); // input mouse

    return m_window;
}

void MoteurPhysique::display()
{
        glfwSwapBuffers(this->m_window); // Swap front and back buffers 
        glfwPollEvents(); // Poll for and process events 
}

void MoteurPhysique::terminate()
{
    glfwDestroyWindow(this->m_window); // destroy window
    glfwTerminate();  //stop glfw
}



void MoteurPhysique::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        std::cout << "click at x = " << xpos << " y = " << ypos << std::endl;

        double seconds = glfwGetTime();
        std::cout << seconds << std::endl;
    }
}
