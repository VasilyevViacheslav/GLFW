#include <GLFW/glfw3.h>
#include "Header.h"
#include <iterator>
#include <iostream>
#include <string>
int main(void)
{
    GLFWwindow* window;
    std::vector<Triangle> First;
    Triangle None{ 0,0,0,0,0,0,0 };
    Kit_Triangle Obs(None);
    float x1,y1,x2,y2,x3,y3,mass;
    int i = 0;
    while (true)
    {
        First.push_back(None);
        std::cout << "If want stop ->mass = 0, Trangles must be expressed anti-clockwise ";
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> mass;
        if (mass == 0) break;
        First[i] = { x1,y1,x2,y2,x3,y3,mass};
        Obs.add_Triangle(First[i]);
        ++i;
    }
    std::cout << Obs.CenterMassKit_x << "   " << Obs.CenterMassKit_y;
    std::vector<float> Coords = Obs.Get_Coords(Obs.Massive_Of_TRiangle);
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "TRIANGLEEEES", NULL, NULL);
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