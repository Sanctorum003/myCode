#include <iostream>
using namespace std;
typedef long long ll;

ll fact(ll n)
{
    if(n == 1) return 1;
    else return n*fact(n-1);
}

int main(void)
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    ll n;
    cin>>n;
    for(int i =0; i < n; ++i)
    {
        ll t;
        cin>>t;
        t = fact(t);
        // cout<<t<<endl;
        string s;
        s = to_string(t);
        // cout<<s<<endl;
        ll cnt=0;
        for(int j = s.size()-1; j > 0;--j)
        {
            // cout<<s[j]<<endl;
            if(s[j] == '0')
            {
                // cout<<s[i]-48<<endl;
                cnt++;
            }
            else
                break;
        }
        cout<<"case #"<<i<<":"<<endl<<cnt<<endl;
    }
    return 0;
}