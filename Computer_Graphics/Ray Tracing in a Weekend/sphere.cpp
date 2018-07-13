#include <iostream>
#include <cstdio>
#include "ray.h"
#include <vector>
using namespace std;

bool hit_sphere(const vec3 &center, float radius, const ray &r)
{ //t*t*dot( ​ B ​ , ​ B ​ ) + 2*t*dot( ​ B,A ​- C ​ ) + dot( ​ A-C,A ​- C ​ ) - R*R = 0
  //具体光线怎么相交的看
    vec3 oc = r.origin() - center;
    float b = 2 * dot(r.direction(), oc);
    float a = dot(r.direction(), r.direction());
    float c = dot(oc, oc) - radius * radius;
    return (b * b - 4 * a * c >= 0); //△要大于等于0时有实根
}

vec3 color(const ray &r)
{
    if (hit_sphere(vec3(0, 0, -1), 0.5, r))
    {
        return vec3(0.0, 0.0, 1.0);
    }
    vec3 unit_direction = unit_vector(r.direction());               //转换为单位向量
    float t = 0.5 * (unit_direction.y() + 1.0);                     //将单位化的射线的纵坐标转换到从[-1,1]变换到[0,1]
    return (1.0 - t) * vec3(0, 1.0, 0.0) + t * vec3(1.0, 0.0, 0.0); //通过参数t将两种颜色混合
}

int main(void)
{
    freopen("p_sphere.ppm", "r", stdin);
    freopen("p_sphere.ppm", "w", stdout);

    int nx = 400;
    int ny = 200;
    cout << "P3\n"
         << nx << " " << ny << "\n255\n";
    //通过以下三个向量确定向量(原点->图片上任意一点)   用以遍历整张图片
    vec3 lower_left_corner(-2, -1, -1); //向量(原点->图片左下角)
    //通过horizontal和vertical确定向量(图片左下角->图片上任意一点)
    vec3 horizontal(4, 0, 0); //向量(图片左下角->图片右下角)
    vec3 vertical(0, 2, 0);   //向量(图片左下角->图片左上角)

    for (int j = ny - 1; j >= 0; --j)
    {
        for (int i = 0; i < nx; ++i)
        {
            //u v 用于对图片进行采样。确定上面唯一一点
            float u = float(i) / float(nx);
            float v = float(j) / float(ny);

            //简直一条以原点以起点与图片上某一点相交的射线
            ray r(vec3(0, 0, 0), lower_left_corner + u * horizontal + v * vertical);
            vec3 col = color(r);

            int ir = int(255.99 * col.r());
            int ig = int(255.99 * col.g());
            int ib = int(255.99 * col.b());

            cout << ir << " " << ig << " " << ib << "\n";
        }
    }
}