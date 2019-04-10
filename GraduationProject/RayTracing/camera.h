vec3 ram_in_disk()
{
    vec3 p;
    do
    {
        p = 2*vec3(drand48(),drand48(),0)-vec3(1,1,0);
    }while(dot(p,p) >= 1);
}

class camera
{
    public:
        camera(vec3 lookfrom, vec3 lookat,vec3 vup,float vfov,float aspect)
        {//lookfrom视点/ lookat观察中心/ vup上矢量(描述相机倾斜程度???)/ vfov视野最上到最下的角度/ aspect是长宽比
            float theta = vfov*M_PI/180;
            float half_height = tan(theta/2);
            float half_width = aspect*half_height;
            vec3 w = unit_vector(lookfrom - lookat);//z
            vec3 u = unit_vector(cross(vup,w));//x cross没有交换律！！！！！
            vec3 v = unit_vector(cross(w,u));//y

            origin = lookfrom;//世界坐标系下的位置
            lower_left_corner = lookfrom-w-half_height*v-half_width*u;//世界坐标系下的位置
            horizontal = 2*half_width*u;//延伸方向
            vertical = 2*half_height*v;//延伸方向
        }
        ray get_ray(float u,float v)
        {
            return ray(origin,lower_left_corner+u*horizontal+v*vertical-origin); //原点以及方向向量
        }


        //设置视点和画面大小
        vec3 origin;//设置原点（视点，摄像机中心点）
        vec3 lower_left_corner;//显示画面左下角（也等价于原点到左下角的向量）
        vec3 vertical;//垂直长度
        vec3 horizontal;//水平长度
};