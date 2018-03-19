#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    string str = "0123456789";
    long int n = 0, m = 0;
    cin>>n;
    n--;
    do
    {
        if(n == m)
        {
            cout<<str<<endl;
            return 0;
        }

        m++;
    }while(next_permutation(str.begin(),str.end()));

    return 0;
}