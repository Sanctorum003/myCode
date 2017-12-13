#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int comp(int a,int b)
{
    return a>b;
}

int main(void)
{
    int n;
    vector<int> v;
    cin>>n;
    while(n)
    {
        v.push_back(n);
        cin>>n;
    }
    sort(v.begin(),v.end(),comp);

    cout<<v[1]<<endl;

    return 0;
}