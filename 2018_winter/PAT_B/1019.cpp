#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int cmp(int a,int b)
{
    return a>b;
}//降序

int main(void)
{
    vector<int> v;
    int t;
    int temp;
    cin>>temp;
    int fr;
    int to;
    int minus;

    t = temp / 1000;
    v.push_back(t);  
    t = temp % 1000 / 100;
    v.push_back(t);  
    t = temp % 100 / 10;
    v.push_back(t);  
    t = temp % 10;
    v.push_back(t);  


    do
    {    
        sort(v.begin(),v.end(),cmp);
        fr = v[0]*1000+v[1]*100+v[2]*10+v[3]*1;
        sort(v.begin(),v.end());
        to = v[0]*1000+v[1]*100+v[2]*10+v[3]*1;
        minus = fr -to;
        printf("%04d - %04d = %04d\n",fr,to,minus);
        // cout<<fr<<" - "<<to<<" = "<<minus<<endl;
        v[0] = minus / 1000;
        v[1] = minus % 1000 / 100;
        v[2] = minus % 100 / 10;
        v[3] = minus % 10;
    }while(!(minus == 0 || minus == 6174));

    return 0;
}