#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void)
{
    vector<string> v;
    string t;
    while(cin>>t)
        v.push_back(t);
    reverse(v.begin(),v.end());
    for(int i = 0 ; i < v.size();++i)
    {
        cout<<v[i];
        if(i != v.size()-1 )
            cout<<" ";
    }
    cout<<endl;
    stack<int> s;
    s.
    return 0;
}