#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    cin>>n;
    if(n == 0)
    {
        cout<<0<<endl;
        return 0;
    }
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
        else if(temp == 9) v.push_back('9');
        else if(temp == 8) v.push_back('8');
        else if(temp == 7) v.push_back('7');
        else if(temp == 6) v.push_back('6');
        else if(temp == 5) v.push_back('5');
        else if(temp == 4) v.push_back('4');
        else if(temp == 3) v.push_back('3');
        else if(temp == 2) v.push_back('2');
        else if(temp == 1) v.push_back('1');
        else if(temp == 0) v.push_back('0');
        n /= 16;
        // cout<<v[v.size()-1]<<endl;
    }


    for(int i = v.size()-1; i >= 0;--i)
        cout<<v[i];
    return 0;
}