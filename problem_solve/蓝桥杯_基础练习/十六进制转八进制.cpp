#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int main(void)
{
    int n;//个数
    cin>>n;
    for(int i = 0; i < n; ++i)
    {
        vector<int> v;
        string s;
        cin>>s;
        int m = s.length();

        //16 转 2
        for(int j = 0; j <m;++j)
        {
            char tmp = s.at(j);
            if( tmp >= '0' && tmp <= '9')
            {
                vector<int> t;
                int a = tmp - '0';
                for(int k = 0; k < 4; ++k)
                {
                    if( a != 0)
                    {
                        t.push_back(a%2);
                        a /= 2;
                    }
                    else
                    {
                        t.push_back(0);
                    }

                }
                for(int k = t.size()-1; k >= 0;--k)
                {
                    v.push_back(t[k]);
                }
            }
            else
            {
                vector<int> t;
                int a = tmp - 'A' + 10;
                while( a != 0)
                {
                    t.push_back(a%2);
                    a /= 2;
                }
                for(int k = t.size()-1; k >= 0;--k)
                {
                    v.push_back(t[k]);
                }
            }
        }

        // for(int j = 0; j < v.size();++j)
        //     cout<<v[j];
        // cout<<endl;

        int s_v = v.size();
        int m_v = s_v % 3;
        if(m_v == 1)    
        {
            v.insert(v.begin(),0);
            v.insert(v.begin(),0);            
        }

        if(m_v == 2)
        {
             v.insert(v.begin(),0);
        }

        

        //2 转 8
        vector<int> oct;

        for(int j = 0; j < v.size(); j+=3)
        {
            int o_tmp = v[j] * 4 + v[j+1]*2 + v[j+2]*1;
            if(oct.size() != 0 || o_tmp != 0)
                oct.push_back(o_tmp);
        }

        for(int j = 0; j < oct.size();++j)
            cout<<oct[j];
        cout<<endl;
    }
    return 0;
}