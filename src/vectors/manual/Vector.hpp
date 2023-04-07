#ifndef VECTOR_H
#define VECTOR_H


#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>



using namespace std;

template<int DIM>
class Vector
{
    public:

        Vector() {}

        Vector(std::initializer_list<float> args) {
            if (args.size() != DIM) {
                throw std::invalid_argument("Vector must have DIM components");
            }
            auto it = args.begin();
            for (int i = 0; i < DIM; ++i) {
                data[i] = *it++;
            }
        }

        // overloading operators
        Vector operator+=(const Vector &v)
        {
            return (*this = (*this + v));
        }

        Vector operator+(const Vector &v)
        {
            Vector<DIM> result;
            for (int i = 0; i < DIM; ++i) {
                result.data[i] = data[i] + v.data[i];
            }
            return result;
        }

        Vector operator-=(const Vector &v)
        {
            return (*this = (*this - v));
        }

        Vector operator-(const Vector &v)
        {
            Vector<DIM> result;
            for (int i = 0; i < DIM; ++i) {
                result.data[i] = data[i] - v.data[i];
            }
            return result;
        }

        Vector operator*=(float number)
        {
            for (int i = 0; i < DIM; ++i) {
                data[i] *= number;
            }
            return *this;
        }

        Vector operator*(float number)
        {
            Vector<DIM> result;
            for (int i = 0; i < DIM; ++i) {
                result.data[i] = data[i] * number;
            }
            return result;

        }

        Vector operator/=(float number)
        {
            for (int i = 0; i < DIM; ++i) {
                data[i] /= number;
            }
            return *this;
        }

        Vector operator/(float number)
        {
            Vector<DIM> result;
            for (int i = 0; i < DIM; ++i) {
                result.data[i] = data[i] / number;
            }
            return result;
        }

        Vector operator-(void)
        {
            return (*this) * -1;
        }

        Vector cross(const Vector &v) const {
            static_assert(DIM == 3, "Cross product only defined for 3D vectors");
            Vector<DIM> result;
            result = Vector<DIM>{data[1]*v.data[2] - data[2]*v.data[1],
                                data[2]*v.data[0] - data[0]*v.data[2],
                                data[0]*v.data[1] - data[1]*v.data[0]};
            return result;
        }

        float dot(Vector v){
    
            float result = 0;
            for (int i = 0; i < DIM; ++i) {
                result += data[i] * v.data[i];
            }
            return result;
        };

        float length(void){
            return sqrt(dot(*this));
        };

        Vector normalize(void){
            float len = length();
            if (len == 0) {
                return *this;
            }
            for (int i = 0; i < 3; ++i) {
                data[i] /= len;
            }
            return *this;
        };

        float angle(Vector v){
            float dot_product = dot(v);
            float length_product = length() * v.length();
            if (length_product == 0) {
                return 0;
            }
            float arg = dot_product / length_product;
            if (arg <= -1.0) {
                return 180.0;
            } else if (arg >= 1.0) {
                return 0.0;
            }
            float radians = acos(arg);
            float degrees = radians * (180.0 / M_PI);
            return degrees;
        };

        void print(void){
            std::cout << "Vector: [";
            for (int i = 0; i < DIM; ++i) {
                std::cout << data[i];
                if (i < DIM-1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;
        };


    public:
        float data[DIM];
};

using Vector1 = Vector<1>;
using Vector2 = Vector<2>;
using Vector3 = Vector<3>;

#endif