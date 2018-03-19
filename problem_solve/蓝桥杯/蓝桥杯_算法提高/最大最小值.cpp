#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    vector<int> v;
    int  n;
    cin>>n;
    for(int i = 0; i < n; ++i)
    {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    sort(v.begin(),v.end());

    cout<<v[v.size()-1]<<" "<<v[0]<<endl;
}

