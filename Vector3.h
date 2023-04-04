#ifndef VECTOR3_H
#define VECTOR3_H

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

    public:
        float x;
        float y;
        float z;
};

#endif