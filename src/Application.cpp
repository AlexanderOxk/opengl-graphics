#include <GLFW/glfw3.h>

int main(void)
{
    GLFWwindow *window;
    GLFWmonitor *primary_monitor;
    const GLFWvidmode *mode;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a full screen mode window and its OpenGL context */
    primary_monitor = glfwGetPrimaryMonitor();
    mode = glfwGetVideoMode(primary_monitor);
    window = glfwCreateWindow(mode->width, mode->height, "Hello OpenGL", primary_monitor, NULL);
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
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}