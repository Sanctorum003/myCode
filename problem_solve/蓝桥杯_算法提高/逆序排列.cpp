#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

    reverse(v.begin(),v.end());
    
    for(int i = 0 ; i<v.size();++i)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}