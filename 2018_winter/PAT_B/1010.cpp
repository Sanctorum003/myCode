#include <iostream>
#include <vector>
using namespace std;

// int main(void)
// {
//     vector<vector<int>> v;
//     int t;
//     while(cin>>t)
//     {
//         vector<int> tp;
//         tp.push_back(t);
//         cin>>t;
//         tp.push_back(t);
//         v.push_back(tp);
//     }

//     for(int i = 0 ; i < v.size;++i)
//     {
        
//     }
//     return 0;
// }

int main(void)
{
    bool flag =true;
    int a;
    int b;
    if(b!=0)
    {
        cin>>a>>b;
        a*=b;
        b--;
        cout<<a<<" "<<b;
        flag = false;
    }
    while(cin>>a>>b)
    {
        if(b!=0)
        {
            a*=b;
            b--;
            cout<<" "<<a<<" "<<b;
            flag = false;
        }
    }

    if(flag)
        cout<<"0 0"<<endl;
    return 0;
}