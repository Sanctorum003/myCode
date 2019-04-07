#include "ray.h"
#include  <iostream>

class material;

struct hit_record
{
    float t;//撞点在这条射线的位置t
    vec3 p;//撞点坐标
    vec3 normal;//该点的法向量
    material *mat_ptr;//材质数据
};

class hitable
{
    public:
        virtual bool hit(const ray &r,float tmin,float tmax,hit_record &rec) const = 0;    
};

class sphere:public hitable
{
    public:
        sphere(){}
        sphere(vec3 cen,float r,material *m):center(cen),radius(r),mat_ptr(m){};
        virtual bool hit(const ray& r,float tmin,float tmax,hit_record &rec)const;
        vec3 center;
        double radius;
        material* mat_ptr;

};

bool sphere::hit(const ray& r,float tmin,float tmax,hit_record &rec)const
{
    vec3 oc = r.origin()-center;
    float a = dot(r.direction(),r.direction());
    float b = 2.0 * dot(oc,r.direction());
    float c = dot(oc,oc)- radius*radius;
    float discriminant = b*b-4.0*a*c;
    if(discriminant > 0) //>=?
    {
        float temp = (-b-sqrt(discriminant))/(2.0 * a);
        if( temp > tmin && temp < tmax)
        {
            rec.t = temp;//撞点在这条射线的位置t
            rec.p = r.point_at_parameter(rec.t);//装点位置的坐标
            rec.normal = (rec.p - center)/radius;//法向量并map到[-1,1]
            rec.mat_ptr = mat_ptr;
            return true;
        }
        temp = (-b+sqrt(discriminant))/(2.0 * a);
        if( temp > tmin && temp < tmax)
        {
            rec.t = temp;//撞点在这条射线的位置t
            rec.p = r.point_at_parameter(rec.t);//装点位置的坐标
            rec.normal = (rec.p - center)/radius;//法向量并map到[-1,1]
            rec.mat_ptr = mat_ptr;
            return true;
        }
         
    }

    return false;
}


class hitable_list:public hitable
{
    public:
        hitable_list(){}
        hitable_list(hitable **l,int n):list(l),list_size(n){};
        virtual bool hit(const ray &r,float tmin,float tmax, hit_record &rec) const;

        hitable **list;
        int list_size;

};

bool hitable_list::hit(const ray &r,float tmin,float tmax,hit_record &rec) const
{
    hit_record tmp_rec;
    bool hit_anything = false;
    float closest_so_far = tmax;
    for(int i = 0; i < list_size;++i)
    {
        if(list[i]->hit(r,tmin,closest_so_far,tmp_rec))
        {
            hit_anything = true;
            closest_so_far = tmp_rec.t;
            rec = tmp_rec;
        }
    }
    return hit_anything;
}


class material
{
    public:
        virtual bool scatter(const ray& r_in,const hit_record& rec,vec3 &attenuation,ray& scattered)const = 0;
};

vec3 random_in_unit_sphere()
{//构造起点在原点，长度小于1，方向随机->用于寻找随机漫反射点
    vec3 p;
    do
    {
        p = 2*vec3(drand48(),drand48(),drand48())-vec3(1,1,1);
    }while(p.squared_length() >= 1);
    return p;
}

class lambertian:public material
{//Lambert （兰伯特）光照模型，理想漫反射模型
    public:
        lambertian(const vec3& a):albedo(a){};
        virtual bool scatter(const ray& r_in,const hit_record& rec,vec3 &attenuation,ray& scattered)const
        {//  入射光线/撞击信息/光线衰减系数（反射率）/反射光线
            vec3 target = rec.p + rec.normal+random_in_unit_sphere();
            scattered = ray(rec.p,target-rec.p);
            attenuation = albedo;
            return true;
        }

        vec3 albedo;//光线衰减系数

};

vec3 reflect(const vec3& v,const vec3& n)
{//镜面反射方向向量推导
    return v-2*dot(v,n)*n;
}

class metal:public material 
{//镜面反射
    public:
        metal(const vec3& a,float f):albedo(a){fuzz=f>1?1:f;}
        virtual bool scatter(const ray& r_in,const hit_record& rec,vec3 &attenuation,ray& scattered)const
        {//  入射光线/撞击信息/光线衰减系数（反射率）/反射光线
            vec3 reflected = reflect(r_in.direction(),rec.normal);//单位化？？？
            scattered = ray(rec.p,reflected+fuzz*random_in_unit_sphere());
            attenuation = albedo;
            return (dot(scattered.direction(),rec.normal)>0);//判断反射光线和法线是否是锐角，只有是锐角才能是反射
        }
        vec3 albedo;//光线衰减系数
        float fuzz;//模糊效果
};

float schlick(float cosine,float ref_idx)
{
    float R0 = (1-ref_idx)/(1+ref_idx);
    R0 = R0*R0;
    return R0+(1-R0)*pow(1-cosine,5);
}

bool refract(const vec3& v,const vec3& n,float ni_over_nt,vec3& refracted){
    vec3 uv = unit_vector(v);
    float dt = dot(uv,n);
    float discriminant = 1-(ni_over_nt*ni_over_nt)*(1-dt*dt);
    if(discriminant > 0)
    {
        refracted = (ni_over_nt)*(uv-n*dt)- n*sqrt(discriminant);
        return true;
    }
    else//小于0 没有折射光线，即发生全反射
        return false;

}

class dielectric:public material
{//折射
    public:
        dielectric(float ri):ref_idx(ri){}
        virtual bool scatter(const ray& r_in,const hit_record& rec,vec3 &attenuation,ray& scattered)const
        {
            vec3 outward_normal;
            vec3 reflected = reflect(r_in.direction(),rec.normal);
            float ni_over_nt;// n1/n2
            attenuation = vec3(1,1,1);//不衰减
            vec3 refracted;//折射方向向量
            float reflect_prob;//反射比例
            float cosine;//schlick中的一参数
            if(dot(r_in.direction(),rec.normal)>0)//说明光线从内部射向外部
            {
                outward_normal = -rec.normal;
                ni_over_nt = ref_idx;
                cosine = dot(r_in.direction(),rec.normal) / r_in.direction().length();

            }
            else
            {
                outward_normal = rec.normal;
                ni_over_nt = 1.0/ref_idx;
                cosine = - dot(r_in.direction(),rec.normal) / r_in.direction().length();
            }
            if(refract(r_in.direction(),outward_normal,ni_over_nt,refracted))
            {
                reflect_prob = schlick(cosine,ref_idx);
            }
            else
            {
                scattered = ray(rec.p, reflected);
                reflect_prob = 1.0;
            }
            if(drand48() < reflect_prob)
            {
                scattered = ray(rec.p,refracted);
            }
            else
            {
                scattered = ray(rec.p,reflected);
            }
            return true;
        }

        float ref_idx;
};