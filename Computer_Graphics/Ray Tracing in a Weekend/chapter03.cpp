#include <iostream>
#include <cstdio>
#include "ray.h"
#include <vector>
using namespace std;

vec3 color(const ray& r){
    vec3 unit_direction = unit_vector(r.direction());//转换为单位向量
    float t = 0.5*(unit_direction.y()+1.0);//将单位化的射线的纵坐标转换到从[-1,1]变换到[0,1]
    return (1.0-t)*vec3(0,1.0,0.0)+t*vec3(1.0,0.0,0.0);//通过参数t将两种颜色混合
}

int main(void)
{
    freopen("chapter03.ppm","r",stdin);
    freopen("chapter03.ppm","w",stdout);

    int nx = 200;
    int ny = 100;
    cout<<"P3\n"<<nx<<" "<<ny<<"\n255\n"; 
    //通过以下三个向量确定向量(原点->图片上任意一点)   用以遍历整张图片
    vec3 lower_left_corner(-2,-1,-1);//向量(原点->图片左下角)
    //通过horizontal和vertical确定向量(图片左下角->图片上任意一点)
    vec3 horizontal(4,0,0);//向量(图片左下角->图片右下角)
    vec3 vertical(0,2,0);//向量(图片左下角->图片左上角)

     for(int j = ny-1;j>=0;--j){
        for(int i = 0; i < nx; ++i){
            //u v 用于对图片进行采样。确定上面唯一一点
            float u = float(i)/float(nx);
            float v = float(j)/float(ny);
            
            //简直一条以原点以起点与图片上某一点相交的射线
            ray r(vec3(0,0,0),lower_left_corner+u*horizontal+v*vertical);
            vec3 col = color(r);
            
            int ir = int (255.99*col.r());  
            int ig = int (255.99*col.g());  
            int ib = int (255.99*col.b());  

            cout << ir << " " << ig << " " << ib << "\n";  
        }
     }
    

}