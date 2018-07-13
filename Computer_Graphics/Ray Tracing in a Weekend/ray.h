#ifndef RAYH
#define RAYH
#include "vec3.h"

//p(t) = A + tB 射线的参数方程，A为射线起点[向量]，B为射线方向[向量],t是参数

class ray //光线[射线]类
{
    public:
        ray() {}
        ray(const vec3& a, const vec3& b) { A = a; B = b; }  
        vec3 origin() const       { return A; }
        vec3 direction() const    { return B; }
        vec3 point_at_parameter(float t) const { return A + t*B; }

        vec3 A;
        vec3 B;
};

#endif 


