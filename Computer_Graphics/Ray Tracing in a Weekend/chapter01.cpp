#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
    freopen("chapter01.ppm", "r", stdin);  
    freopen("chapter01.ppm", "w", stdout);//file i/o

    int nx = 200;                          
    int ny = 100;
     // "P3" means this is a RGB color image in ASCII
     // "nx ny" is the width and height of the image in pixels
     // "255" is the maximum value for each color                          
    cout<<"P3\n"<<nx<<" "<<ny<<"\n255\n"; 
     // The part below is image data: RGB triplets
    for(int j = ny-1;j>=0;--j){
        for(int i = 0; i < nx; ++i){
            float r = float(i) / float(nx);
            float g = float(j) / float(ny);
            float b = 0.2;
            int ir = int(255.99*r);
            int ig = int(255.99*g);
            int ib = int(255.99*b);
            cout<<ir<<" "<<ig<<" "<<ib<<"\n";
        }
    }

    return 0;
}