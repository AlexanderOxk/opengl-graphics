#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

GLFWwindow *init_app(int width, int height, bool fullscreen = false)
{
    GLFWwindow *window;
    if (!glfwInit())
        return NULL;

    if (fullscreen)
    {
        GLFWmonitor *primary_monitor;
        const GLFWvidmode *mode;
        primary_monitor = glfwGetPrimaryMonitor();
        mode = glfwGetVideoMode(primary_monitor);
        window = glfwCreateWindow(mode->width, mode->height, "Hello OpenGL", primary_monitor, NULL);
    }
    else
    {
        window = glfwCreateWindow(width, height, "Hello OpenGL", NULL, NULL);
    }

    if (!window)
    {
        glfwTerminate();
        return NULL;
    }

    glfwMakeContextCurrent(window);
    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        return NULL;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;
    return window;
}

int main(void)
{
    GLFWwindow *window;
    window = init_app(1920, 1080);

    float positions[6] = {
        -0.5f,
        -0.5f,
        0.0f,
        0.5f,
        0.5f,
        -0.5f,
    };

    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}