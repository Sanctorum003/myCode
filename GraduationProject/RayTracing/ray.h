#include "vec3.h"

class ray
{
    public:
        ray(){}
        ray(const vec3& A,const vec3& B)
        {
            this->A = A;
            this->B = B;
        }
        vec3 origin()const{return A;}
        vec3 direction()const{return B;}
        vec3 point_at_parameter(float t)const{return A+t*B;}

        vec3 A;//起始坐标
        vec3 B;//方向向量
};