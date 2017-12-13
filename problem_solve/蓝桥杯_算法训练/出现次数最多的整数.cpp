#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<long long int,long long int> > v;

int comp(pair<int,int> a,pair<int,int> b)
{
    if(a.second != b.second)
        return a.second > b.second;
    else
        return a.first < b.first;
}

int main(void)
{
    int n;
    cin>>n;
    if(n <= 0)  return 0;
    long long int temp;    
    for(int i = 0; i < n; ++i)
    {
        cin>>temp;
        int j =0;
        for(j = 0; j < v.size();++j)
        {
            if(v[j].first == temp)
            {
                v[j].second ++;
                break;
            }
        }

        if(j >= v.size())
        {
            v.push_back(pair<long long int,long long int>(temp,1));
        }
    }

    sort(v.begin(),v.end(),comp);

    // for(int i = 0; i < v.size();++i)
    // {
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }

    cout<<v[0].first;
    return 0;
}