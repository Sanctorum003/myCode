#include <iostream>
#include <cstdio>
using namespace std;

int main(){

    freopen("chapter1.ppm", "r", stdin);  
    freopen("chapter1.ppm", "w", stdout);//file i/o

    int nx = 200;
    int ny = 100;

    cout<<"P3"<<endl<<nx<<" "<<ny<<endl<<"255"<<endl;
    for(int j = ny-1;j>=0;--j)
    {
        for(int i = 0; i <nx;++i)
        {
           float r = float(i)/float(nx);
           float g = float(j)/float(ny);
           float b = 0.2;
           int ir = int(255.99*r);
           int ig = int(255.99*g);
           int ib = int(255.99*b);
           cout<<ir<<" "<<ig<<" "<<ib<<endl;
        }
    } 

    fclose(stdin);//关闭重定向输入 
	fclose(stdout);//关闭重定向输出 

    return 0;
}