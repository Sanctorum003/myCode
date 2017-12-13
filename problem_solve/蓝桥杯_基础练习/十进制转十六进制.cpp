#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    char[] s = "0123456789ABCDEF";//ZI
    int n;
    cin>>n;
    vector<char> v;
    while(n != 0)
    {
        int temp = n %16;
        if(temp == 10)  v.push_back('A');
        else if(temp == 11) v.push_back('B');
        else if(temp == 12) v.push_back('C');
        else if(temp == 13) v.push_back('D');
        else if(temp == 14) v.push_back('E');
        else if(temp == 15) v.push_back('F');
        else v.push_back(n+48);
        n /= 16;
    }


    for(int i = v.size()-1; i >= 0;--i)
        cout<<v[i];
    return 0;
}