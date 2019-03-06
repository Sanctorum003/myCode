#include <iostream>
#include <vector> 
#include <string>
using namespace std;
//the，a，an，of，for, and
int main(void)
{
    int n;
    cin>>n;
    while(n--)
    {
        vector<string> v;
        string s;
        getline(cin,s);
        string t;
        int pre = 0;
        int rear =0;
        cout<<s.find(" ",pre+1)<<endl;
        while((rear = s.find(" ",pre+1)) != -1)
        {
            cout<<pre<<" "<<rear<<endl;
            t = s.substr(pre,rear);
            cout<<t<<endl;
            pre = rear;
        }
        
        
    }
    return 0;
}