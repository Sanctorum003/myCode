#include <iostream>
#include <cctype>
using namespace std;

int main(void)
{
    bool flag = true;
    int n;
    string s;
    int z;
    int quan[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    int m[] = {1,0,40,9,8,7,6,5,4,3,2};// x = 88 - 48
    cin>>n;

    for(int i = 0 ; i < n; ++i)
    {
        int sum = 0;
        int z = -1;
        cin>>s;
        for(int j = 0 ; j < (int)s.size() - 1;++j)
        {
            if(!isdigit(string[j]))
                break;
            sum += (s[j]-48)*quan[j];
        }

        z = sum%11;
        // cout<<sum<<" "<<z<<endl;
        z = m[z];
        // cout<<z<<" "<<s[17]-48<<endl;
        if(z != s[17]-48)
        {
            cout<<s<<endl;
            flag = false;
        }
    }

    if(flag)
        cout<<"All passed"<<endl;
    return 0;
}
