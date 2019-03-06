#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

int main(void)
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int a[26];
    fill(a,a+26,0);
    string s;
    getline(cin,s);
    int cnt =0 ;
    for(int i =0; i < s.size();++i)
    {
        if(s[i] != ' ')
        {
            a[s[i]-'a']++;
            cnt++;
        }
    }
    
    int res=0;
    for(int i =1; i <26;++i)
    {
        if(a[res] < a[i])
            res =i;
    }
    
    cout<<char(res+'a')<<" ";//<<a[res]<<cnt<<endl;;
    printf("%.2f\n",((double)a[res])/cnt);
    
    return 0;
}