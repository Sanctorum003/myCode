/*
    sstream 太慢直接取出各位数
*/

// #include <iostream>
// #include <sstream>
// #include <cstdio>
// using namespace std;


// string a;
// bool isHuiWen(int i,int n)
// {
//     stringstream ss;
//     int sum = 0;
//     ss<<i;
//     a = ss.str();//12321
//     // 0 1 2 3
//     for(int j = a.size()-1,k = 0; j >= a.size()/2,k<(a.size()+1)/2;--j,++k){
//         if(a[k] != a[j])
//             return false;
//     }

      
//     for(int k = 0; k < a.size();++k)
//         sum += a[k] - 48;
    
//     if(sum != n)
//         return false;
    
//     return true;
// }


// int main(void)
// {
//     int n;
//     cin>>n;

//     for(int i = 999999; i>=100000; --i)
//     {
//         if(isHuiWen(i,n))
//             printf("%d\n",i);
//     }
//     return 0;
// }

#include <iostream>  
using namespace std;  
  
int main()  
{  
    int n;  
    cin>>n;  
    for(int i=10000;i<=999999;++i)//全部范围  
    {  
        if(i<=99999)//五位数  
        {  
            int temp=i;  
            int a,b,c,d,e;  
            a=temp%10;  
            b=temp/10%10;  
            d=temp/1000%10;  
            c=temp/100%10;  
            e=temp/10000;  
            if(a==e&&b==d&&a+b+c+d+e==n)  
                cout<<i<<endl;  
        }  
        else//六位数  
        {  
            int temp=i;  
            int a,b,c,d,e,f;  
            a=temp%10;  
            b=temp/10%10;  
            c=temp/100%10;  
            d=temp/1000%10;  
            e=temp/10000%10;  
            f=temp/100000;  
            if(a==f&&b==e&&c==d&&a+b+c+d+e+f==n)  
                cout<<i<<endl;  
        }  
    }  
    return 0;  
}  