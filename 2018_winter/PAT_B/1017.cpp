#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> v;
    string s;
    int flag = false;
    cin>>s;
    int b;
    cin>>b;
    int R=0;
    for(int i = 0 ; i < (int)s.size(); ++i)
    {
        R = 10*R + (s[i]-48);
        v.push_back(R/b);
        R = R % b;
    }
    for(int i = 0 ; i < (int)v.size();++i)
        if(v[i] != 0 || flag)
        {
            cout<<v[i];
            flag = true;
        }
    if(!flag) cout<<0;
    cout<<" "<<R;
    return 0;
}