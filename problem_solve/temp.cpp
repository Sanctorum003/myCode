#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    vector<int> v;
    for(int i = 100; i>=0; --i)
        v.push_back(1);

    sort(v.begin(),v.end());

    for(int i = 0; i < v.size()-1;++i)
        cout<<v[i]<<endl;

    cout<<endl;

    return 0;
}