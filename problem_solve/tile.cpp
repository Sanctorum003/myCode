/**
 * 给出一列数对，求出其最长的递增序列的长度
 **/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

bool comp(pair<int,int> a,pair<int,int> b)
{
    if( a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

int main(void)
{
    pair<int,int> p[100];
    int n;
    cin>>n;
    for(int i = 0; i < n;++i)
    {
        cin>>p[i].first>>p[i].second;
    }

    sort(p,p+n,comp);

    cout<<endl;
    for(int i = 0 ; i < n; ++i)
        cout<<p[i].first<<" "<<p[i].second<<endl;
    cout<<endl;
 

    vector<int> v;
    v.push_back(p[0].second);
    for(int i = 1; i < n; ++i)
    {
        if(p[i].second >= v[v.size() -1 ])//最新值与v数组中的最大值比较，看是更改还是添加
            v.push_back(p[i].second);
        else
        {
            find
            int start = 0;
            int end = v.size()-1;
            while(end - start > 1)
            {
                int mid = (start + end)/2;
                if(v[mid] >= p[i].second)
                    end = mid;
                else
                    start = mid;
            }
            v[end] = p[i].second;
        }
    }

    cout<<v.size();

    return 0;

}