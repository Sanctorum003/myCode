#include <iostream>
#include <cfloat>
#include <cstdlib>
#include <math.h>
#include "hitable.h"
#include "camera.h"
using namespace std;


vec3 color(const ray &r,hitable *world,int depth)
{//入射光线，物体集合，最大递归深度
    hit_record rec;
    if(world->hit(r,0.001,MAXFLOAT,rec))//光线投射是否撞到物体
    {//是，根据物体材质，计算不同的散射光线
        ray scattered;//散射光线
        vec3 attenuation;//光线衰减系数
        if(depth < 50 && rec.mat_ptr->scatter(r,rec,attenuation,scattered))//计算是否有反射光线 && 未达到最大递归次数
        {//存在
            return attenuation*color(scattered,world,depth+1);//scattered保存有装点和散射方向向量，这样不停的递归
        }
        else
        {//不存在
            return vec3(0,0,0);
        }
        // vec3 target = rec.p+rec.normal+random_in_unit_sphere();//生成随机漫反射
        // return 0.5*color(ray(rec.p,target-rec.p),world,0);
    }
    else
    {//否，取环境光
        vec3 unit_direction = unit_vector(r.direction());//向量单位化，这里方向向量==原点到遍历点的向量
        float t = 0.5*(unit_direction.y()+1);//映射到0~1
        return (1-t)*vec3(1.0,1.0,1.0)+t*vec3(0.5,0.7,1.0);//进行线性插值
    }
}

int main(void)
{
    freopen ("image3.ppm","w",stdout);

    int nx = 200;
    int ny = 100;
    int ns = 100;//采样次数
    cout<<"P3"<<endl;
    cout<<nx<<" "<<ny<<endl;
    cout<<255<<endl;

    //设置相机
    camera cam(vec3(-2,2,1),vec3(0,0,-1),vec3(0,1,0),30,2);

    //设置多个物体
    hitable *list[5];
    list[0] = new sphere(vec3(0,0,-1),0.5,new lambertian(vec3(0.8, 0.3, 0.3)));
    list[1] = new sphere(vec3(0,-100.5,-1),100,new lambertian(vec3(0.8, 0.8, 0)));
    list[2] = new sphere(vec3(1,0,-1),0.5,new metal(vec3(0.8, 0.6, 0.2),0.3));
    list[3] = new sphere(vec3(-1,0,-1),0.5,new dielectric(1.5));
    list[4] = new sphere(vec3(-1,0,-1),-0.45,new dielectric(1.5));
    hitable *world = new hitable_list(list,5);

    //遍历画面以及设置颜色
    for(int j = ny-1; j >= 0 ;--j)
    {
        for(int i = 0; i < nx;++i)
        {
            vec3 col(0.0,0.0,0.0);
            for(int s = 0; s < ns; ++s)
            {
                //用于遍历的offset
                float u = float(i+drand48())/float(nx);
                float v = float(j+drand48())/float(ny);
                ray r = cam.get_ray(u,v);
                col += color(r,world,0);//ns次累计
            }
            
            col /= float(ns);//ns取平均
            col = vec3(sqrt(col[0]),sqrt(col[1]),sqrt(col[2]));
            int ir = int(col[0]*255.99);
            int ig = int(col[1]*255.99);
            int ib = int(col[2]*255.99);
            cout<<ir<<" "<<ig<<" "<<ib<<endl;
        }
    }

    fclose(stdout);
    return 0;
}