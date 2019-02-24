#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
两个字符串自左向右逐个字符相比（按ASCII值大小相比较），直到出现不同的字符或遇’\0’为止。

当两个数的位数一样，则直接可以应用字符串的比较。如
*/

int cmp(string a,string b)
{   
    if(a.size() > b.size())
    {
        int k = a.size()-b.size();
        for(int i =0; i < k; ++i)
            b+=a[i];
    }
    else if(a.size() < b.size())
    {
        int k = b.size()-a.size();
        for(int i =0; i < k; ++i)
            a+=b[i];
    }

    return a>b;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    string a[n];
    for(int i =0; i< n; ++i)
    {
        cin>>a[i];
    }

    sort(a,a+n,cmp);

    for(int i =0; i<n;++i)
        cout<<a[i];

    return 0;
}