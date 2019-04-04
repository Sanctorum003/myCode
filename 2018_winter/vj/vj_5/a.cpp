#include <bits/stdc++.h>
using namespace std;

string per[3] = {"ABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCABCA",
                 "BABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABCBABC",
                 "CCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAABBCCAA"};
string name[3] = {"Adrian","Bruno","Goran"};

int main(void)
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt[3];
    fill(cnt,cnt+3,0);
    for(int i =0; i <3;++i)
    {
        for(int j = 0; j < n;++j)
        {
            // cout<<per[i][j]<<" "<<s[j]<<endl;
            if(per[i][j] == s[j])
                cnt[i]++;
        }
    }

    int maxe = *max_element(cnt,cnt+3);
    cout<<maxe<<endl;
    for(int i = 0; i <3;++i)
    {
        if(cnt[i] == maxe)
            cout<<name[i]<<endl;
    }

    return 0;
}