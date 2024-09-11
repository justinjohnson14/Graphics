#include <cmath>

#include <glad/glad.h>

#include <glm/glm.hpp>

class Geometry {
public:
    void generateCircle(float, float, float);

    struct LineParameters {
        float x0, y0;
        float x1, x2;
        float lineWidth;
    };

    struct RingParameters {
        float center_x = 0.0f, center_y = 0.0f;
        float startAngle = 0.0f, endAngle = M_PI*2;
        float innerRadius = 0.5f, outerRadius = 1.0f;
        float maxEdgeLength = 2.0f;

        bool drawArrow = false;
        bool arrowOnEnd = true;
        float arrowLength = 0.0f;
    };

    struct CircleParams{
        float center_x = 0.0f, center_y = 0.0f;
        float radius = 1.0f;
        float maxEdgeLength = 0.1f;
        float smallestAngle = M_PI * 0.95f;
    };

    struct RhombusParameters {
        float center_x = 0.0f, center_y = 0.0f;
        float height = 0;
        float shear = 0;
        float width = 0;
    };

    struct TrapezoidParameters {
        float center_x = 0, center_y = 0;
        float height = 0;
        float base = 0;
        float top = 0;
    };

    struct FrameParameters {
        float x, y;
        float frameWidth, frameHeight;
        float lineWidth;
    };

    struct GridParameters {
        float x, y;
        float width, height;
        float div_x, div_y;
        float lineWidth;
    };

    struct PathParameters {
        glm::vec3 p0;
        glm::vec3 p1;
        int n0;
        int n1;

        int i = 0;
        float width;

        int v0 = -1;
        int v1 = -1;
        float pdir_x, pdir_y;
    };
private:

};

void Geometry::generateCircle(float center_x, float center_y, float radius)
{
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
    vertex[2] = 0.0f;

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
        vertex[(i*3)+5] = 0.0f;

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

    Renderer::NewDrawCall();

    return vals;
}