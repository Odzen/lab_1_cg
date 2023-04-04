
#include <iostream>
#include "Vector3.h"

using namespace std;
int main(void)
{
    Vector3 vectorPlus = Vector3(1, 2, 3) + Vector3(7, 2, 5);
    Vector3 vectorSubstract = Vector3(1, 2, 3) - Vector3(7, 2, 5);
    Vector3 vectorMulti = Vector3(4, 5, 9) * 5;
    float dotValue = Vector3(1, 2, 3).Dot(Vector3(3, 2, 1));
    Vector3 vectorCross = Vector3(9, 4, 6) * Vector3(6, 1, 7);
    Vector3 vectorNorm = Vector3(1, 2, 3).Normalize();
    
    vectorPlus.print();
    vectorSubstract.print();
    vectorMulti.print();
    cout << dotValue << endl;
    vectorCross.print();
    vectorNorm.print();
}