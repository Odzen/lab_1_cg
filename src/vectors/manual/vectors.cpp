
#include <iostream>
#include "Vector.hpp"
#include <string>
#include <vector>
#include <sstream>

void runVectors()
{
    cout << "Manual:" << endl;
    Vector3 vectorPlus3 = Vector3{1, 2, 3} + Vector3{7, 2, 5};
    Vector2 vectorPlus2 = Vector2{1.0f, 2.0f} + Vector2{7.0f, 2.0f};
    Vector1 vectorPlus1 = Vector1{1.0f} + Vector1{7.0f};

    Vector3 vectorSubstract3 = Vector3{1, 2, 3} - Vector3{7, 2, 5};
    Vector2 vectorSubstract2 = Vector2{1, 2} - Vector2{7, 2};
    Vector1 vectorSubstract1 = Vector1{1} - Vector1{7};

    Vector3 vectorMulti3 = Vector3{4, 5, 9} * 5;
    Vector2 vectorMulti2 = Vector2{4, 5} * 5;
    Vector1 vectorMulti1 = Vector1{4} * 5;

    Vector3 vectorDiv3 = Vector3{20, 5, 15} / 5;
    Vector2 vectorDiv2 = Vector2{20, 5} / 5;
    Vector1 vectorDiv1 = Vector1{20} / 5;

    float dotValue3 = Vector3{1, 2, 3}.dot(Vector3{3, 2, 1});
    float dotValue2 = Vector2{1, 2}.dot(Vector2{3, 2});
    float dotValue1 = Vector1{1}.dot(Vector1{3});

    Vector3 v1 = {1, 2, 3};
    Vector3 v2 = {4, 5, 6};

    Vector3 vectorCross3 = v1.cross(v2);

    float l1 = Vector3{9, 4, 6}.length();
    float l2 = Vector2{9, 4}.length();
    float l3 = Vector1{9}.length();

    Vector3 vectorNorm3 = Vector3{1, 2, 3}.normalize();
    Vector2 vectorNorm2 = Vector2{1, 2}.normalize();
    Vector1 vectorNorm1 = Vector1{2}.normalize();

    float vectorAngle3 = Vector3{3, 2, -1}.angle(Vector3{0, 5, 2});
    float vectorAngle2 = Vector2{3, 2}.angle(Vector2{0, 5});
    float vectorAngle1 = Vector1{3}.angle(Vector1{0});
    
    vectorPlus3.print();
    vectorPlus2.print();
    vectorPlus1.print();

    vectorSubstract3.print();
    vectorSubstract2.print();
    vectorSubstract1.print();

    vectorMulti3.print();
    vectorMulti2.print();
    vectorMulti1.print();

    vectorDiv3.print();
    vectorDiv2.print();
    vectorDiv1.print();

    cout << dotValue3 << endl;
    cout << dotValue2 << endl;
    cout << dotValue1 << endl;

    vectorCross3.print();

    cout << l1 << endl;
    cout << l2 << endl;
    cout << l3 << endl;

    vectorNorm3.print();
    vectorNorm2.print();
    vectorNorm1.print();

    cout << vectorAngle3 << endl;
    cout << vectorAngle2 << endl;
    cout << vectorAngle1 << endl;
}