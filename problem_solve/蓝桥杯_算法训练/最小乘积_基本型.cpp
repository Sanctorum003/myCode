#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int comp(int a,int b)
{
    return a>b;
}

int main(void)
{
    int n;
    cin>>n;

    while(n--)
    {
        int m;
        vector<int> v;
        vector<int> w;
        int temp;
        cin>>m;
        for(int i = 0 ; i < m;++i)
        {
            cin>>temp;
            v.push_back(temp);
        }
        for(int i = 0 ; i < m;++i)
        {
            cin>>temp;
            w.push_back(temp);
        }   

        sort(v.begin(),v.end());
        sort(w.begin(),w.end(),comp);

        int sum = 0;

        for(int i = 0; i < m; ++i)
            sum += v[i]*w[i];

        cout<<sum<<endl;
    }

    return 0;
}