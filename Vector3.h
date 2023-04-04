#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>
# include <math.h>

using namespace std;

class Vector3
{
    public:
        Vector3(float X = 0.0f, float Y = 0.0f, float Z = 0.0f)
        {
            x = X;
            y = Y;
            z = Z;
        }

        // overloading operators
        Vector3 operator+=(const Vector3 &v)
        {
            return (*this = (*this + v));
        }

        Vector3 operator+(const Vector3 &v)
        {
            return Vector3(x + v.x, y + v.y, z + v.z);
        }

        Vector3 operator-=(const Vector3 &v)
        {
            return (*this = (*this - v));
        }

        Vector3 operator-(const Vector3 &v)
        {
            return Vector3(x - v.x, y - v.y, z - v.z);
        }

        Vector3 operator*=(float number)
        {
            return (*this = (*this * number));
        }

        Vector3 operator*(float number)
        {
            return Vector3(x * number, y * number, z * number);
        }

        Vector3 operator/=(float number)
        {
            return (*this = (*this / number));
        }

        Vector3 operator/(float number)
        {
            return Vector3( x / number, y / number, z / number);
        }

        Vector3 operator-(void)
        {
            return Vector3(-x, -y, -z);
        }

        // cross product function
        Vector3 operator*(const Vector3 &v){
            return Vector3(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
        };

        // dot product function
        float Dot(Vector3 v){
            return (x*v.x + y*v.y + z*v.z);
        };

        float Length(void){
            return sqrt(x*x + y*y + z*z);
        };

        Vector3 Normalize(void){
            float length = Length();

            x/=length;
            y/=length;
            z/=length;

            return *this;
        };

        void print(void){
            cout << "Vector: " << x << ", " << y << ", " << z << endl;
        };

    public:
        float x;
        float y;
        float z;
};

#endif