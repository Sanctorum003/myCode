#include <iostream>
#include <utility>
using namespace std;

pair<string,int> p[100];

int main(void)
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    if(n > s.size())
        return 0;
    
    if(n == s.size())
    {
        cout<<s;
        return 0;
    }

    int cnt = 0;

    for(int j = n; j <= s.size();++j){
        for(int i = 0; i < s.size() - j; ++i)
        {
            string t = s.substr(i,j);
            for(int i = 0 ; i < cnt; ++i)
            {
                if(p[i].first == t)
                {
                    p[i].second++;
                    break;
                }
            }

            if(i >= cnt)
            {
                p[cnt].first = t;
                p[cnt].second = 1;
                cnt++;
            }
        }
    }

    pair<string,int> res;
    res.second = 0;
    for(int i = 0; i < cnt; ++i)
    {
        if(p[i].second > res.second)
        {
            res.first = p[i].first;
            res.second = p[i].second;
        }
        else if(p[i].second == res.second && p[i].first.length() > res.first.length())
        {
            res.first = p[i].first;
            res.second = p[i].second;
        }
    }

    cout<<res.first<<endl;
    return 0;
}