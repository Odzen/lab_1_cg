#include <glm/glm.hpp> // vec2, vec3, mat4, radians
#include <glm/gtx/string_cast.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <iostream>

using namespace std;
using namespace glm;

float angleGlm(vec3 vector1, vec3 vector2) 
{
    float dot = glm::dot(vector1, vector2);
    float length = glm::length(vector1) * glm::length(vector2);

    if (length == 0) {
        return 0.0f;
    }

    float radians = glm::acos(dot / length);

    return glm::degrees(radians);
};

void runGlm(){
    cout << endl;
    cout << "Glm:" << endl;

    vec3 sum = vec3(1, 2, 3) +  vec3(7, 2, 5);
    vec3 substract = vec3(1, 2, 3) -  vec3(7, 2, 5);
    vec3 scaling = vec3(4, 5, 9) * 5.0f;
    vec3 div = vec3(20, 5, 15) / 5.0f;
    double dotProduct = glm::dot(vec3(1, 2, 3),  vec3(3, 2, 1));
    vec3 crossProduct = glm::cross(vec3(9, 4, 6),  vec3(6, 1, 7));
    vec3 normalized = glm::normalize(vec3(1, 2, 3));
    float angle = angleGlm(vec3(3, 2, -1), vec3(0, 5, 2));

    cout << "Sum glm:" << glm::to_string(sum) << endl;
    cout << "Rest glm:" << glm::to_string(substract) << endl;
    cout << "Scaling glm:" << glm::to_string(scaling) << endl;
    cout << "Div glm:" << glm::to_string(div) << endl;
    cout << "Dot glm:" << dotProduct << endl;
    cout << "Cross glm:" << glm::to_string(crossProduct) << endl;
    cout << "Normalized glm:" << glm::to_string(normalized) << endl;
    cout << "Angle glm:" << angle << endl;
}