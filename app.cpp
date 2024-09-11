#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/trigonometric.hpp>
#include <math.h>
#define GLAD_GL_IMPLEMENTATION
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <stdio.h>
#include <stdlib.h>

#include <Shader.h>

struct circleData {
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
    unsigned int count;
};

void framebuffer_size_callback(GLFWwindow*, int, int);
void processInput(GLFWwindow*);
unsigned int shader(const char*, const char*);
const char* readFile(const char*);
struct circleData createCircle();

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    gladLoadGL();

    Shader shader1 = Shader("./res/vertex.glsl", "./res/fragment.glsl");
    struct circleData circle = createCircle();

    //glm::mat4 model = glm::scale(glm::mat4(1.0f), glm::vec3(10.0f, 10.0f, 0.0f));
    //glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH/(float)SCR_HEIGHT, 0.1f, 100.0f);

    glUseProgram(shader1);

    //unsigned int modelLoc = glGetUniformLocation(shader1, "model");
    //unsigned int viewLoc = glGetUniformLocation(shader1, "view");
    unsigned int projLoc = glGetUniformLocation(shader1, "projection");

    //glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    //glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader1);

        glBindVertexArray(circle.VAO);
        glDrawElements(GL_TRIANGLES, circle.count, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &circle.VAO);
    glDeleteBuffers(2, &circle.VBO);
    glDeleteProgram(shader1);

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, 1);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0, width, height);
}

struct circleData createCircle()
{

    const float radius = 1.0f;
    const float maxEdgeLength = 0.1f;
    const float smallestAngle = M_PI*0.95;

    float angle = asin(maxEdgeLength / (2*radius))*2;
    angle = fminf(angle, M_PI-smallestAngle);

    const float steps = (M_PI*2)/angle;

    int segmentCount = (int)ceilf(steps);
    segmentCount = (segmentCount < 3)
        ? 3
        : segmentCount;

    float vertex[(segmentCount+1)*3];
    unsigned int index[segmentCount*3];

    vertex[0] = 0.0f;
    vertex[1] = 0.0f;
    vertex[2] = 1.0f;

    const float angleStep = (M_PI * 2) / segmentCount;
    for(int i = 0; i < segmentCount; i++)
    {
        float theta = i*angleStep;
        float x = sinf(theta);
        float y = cosf(theta);

        x = 0.0f + x * radius;
        y = 0.0f + y * radius;

        vertex[(i*3)+3] = x;
        vertex[(i*3)+4] = y;
        vertex[(i*3)+5] = 1.0f;

        index[i*3] = 0;
        index[(i*3)+1] = i+1;
        index[(i*3)+2] = 1+((i+1)%segmentCount);

        //fprintf(stdout, "x:, %d, ", 0);
        //fprintf(stdout, "y:, %d, ", i+1);
        //fprintf(stdout, "z:, %d \n", 1+((i+1)%segmentCount));
    }

    unsigned int VBO, VAO, EBO;

    glGenVertexArrays(1, &VAO);

    glGenBuffers(1, &VBO);
    glGenBuffers(1,&EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(index), index, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    struct circleData vals = {
        VBO,
        VAO,
        EBO,
        segmentCount*3
    };

    return vals;
}