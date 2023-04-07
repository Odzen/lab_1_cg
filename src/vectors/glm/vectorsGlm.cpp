#include <glm/glm.hpp> // vec2, vec3, mat4, radians
#include <glm/gtx/string_cast.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <iostream>

using namespace std;
using namespace glm;

// angleGlm function can tale a glm::vec2 or glm::vec3 or glm::vec1


template<typename T>
float angleGlm(const T& vector1, const T& vector2) 
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
    cout << "--------------"<< endl;
    cout << "GLM" << endl;
    
    vec3 sum3 = vec3(1, 2, 3) +  vec3(7, 2, 5);
    vec2 sum2 = vec2(1, 2) +  vec2(7, 2);
    vec1 sum1 = vec1(1) +  vec1(7);

    vec3 substract3 = vec3(1, 2, 3) -  vec3(7, 2, 5);
    vec2 substract2 = vec2(1, 2) -  vec2(7, 2);
    vec1 substract1 = vec1(1) -  vec1(7);

    vec3 scaling3 = vec3(4, 5, 9) * 5.0f;
    vec2 scaling2 = vec2(4, 5) * 5.0f;
    vec1 scaling1 = vec1(4) * 5.0f;

    vec3 div3 = vec3(20, 5, 15) / 5.0f;
    vec2 div2 = vec2(20, 5) / 5.0f;
    vec1 div1 = vec1(20) / 5.0f;

    double dotProduct3 = glm::dot(vec3(1, 2, 3),  vec3(3, 2, 1));
    double dotProduct2 = glm::dot(vec2(1, 2),  vec2(3, 2));
    double dotProduct1 = glm::dot(vec1(1),  vec1(3));

    vec3 crossProduct3 = glm::cross(vec3(1, 2, 3),  vec3(4, 5, 6));

    vec3 normalized3 = glm::normalize(vec3(1, 2, 3));
    vec2 normalized2 = glm::normalize(vec2(1, 2));
    vec1 normalized1 = glm::normalize(vec1(1));

    float angle3 = angleGlm(vec3(3, 2, -1), vec3(0, 5, 2));
    float angle2 = angleGlm(vec2(3, 2), vec2(0, 5));
    float angle1 = angleGlm(vec1(3), vec1(0));

    cout << "Sum:" << endl;
    cout << glm::to_string(sum3) << endl;
    cout << glm::to_string(sum2) << endl;
    cout << glm::to_string(sum1) << endl;

    cout << "Rest:" << endl;
    cout << glm::to_string(substract3) << endl;
    cout << glm::to_string(substract2) << endl;
    cout << glm::to_string(substract1) << endl;

    cout << "Multiplication by scalar:" << endl;
    cout << glm::to_string(scaling3) << endl;
    cout << glm::to_string(scaling2) << endl;
    cout << glm::to_string(scaling1) << endl;

    cout << "Division by scalar:" << endl;
    cout << glm::to_string(div3) << endl;
    cout << glm::to_string(div2) << endl;
    cout << glm::to_string(div1) << endl;

    cout << "Dot product:" << endl;
    cout << dotProduct3 << endl;
    cout << dotProduct2 << endl;
    cout << dotProduct1 << endl;

    cout << "Cross product in R3:" << endl;
    cout << glm::to_string(crossProduct3) << endl;

    cout << "Normalization:" << endl;
    cout << glm::to_string(normalized3) << endl;
    cout << glm::to_string(normalized2) << endl;
    cout << glm::to_string(normalized1) << endl;

    cout << "Angle:" << endl;
    cout << angle3 << endl;
    cout << angle2 << endl;
    cout << angle1 << endl;
    
}