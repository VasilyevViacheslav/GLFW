#include <GLFW/glfw3.h>
#include "Header.h"
#include <iterator>
int main(void)
{
    GLFWwindow* window;
    Triangle First(0, 0, 0.5, 0, 0.5, 0.5, 1);
    Triangle Second(-0.5,-0.6,0.f,-0.1f,0.f,1.f,14);
    Kit_Triangle Obs(First);
    Obs.add_Triangle(Second);
    std::vector<float> Coords = Obs.Get_Coords(Obs.Massive_Of_TRiangle);
    
    
    int i = 0;
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }


    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
        GLfloat j = 0;;

        for (int i = 0; i < Coords.size(); i += 6) 
        {
            glColor3f(Obs.Massive_Of_Dest[j]/Obs.MaxDesteny, 0, 0);
                glVertex2d(Coords[i], Coords[i + 1]);
                glVertex2d(Coords[i + 2], Coords[i + 3]);
                glVertex2d(Coords[i + 4], Coords[i + 5]);
                ++j;
        }
        glEnd();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}