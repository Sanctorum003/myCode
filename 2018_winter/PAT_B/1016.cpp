#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
    string A;
    char a;
    string B;
    char b;
    cin>>A>>a>>B>>b;

    int ta = 0;
    int tb = 0;

    int sa = 0;
    int sb = 0;

    for(int i = 0; i < (int)A.size();++i)
    {
        if(A[i] == a)
            ta++;
    }

    for(int i = 0; i < (int)B.size();++i)
    {
        if(B[i] == b)
            tb++;
    }

    for(int i = 0 ; i < ta; ++i)
    {
        sa += (a-48)*pow(10,i);
    }

    for(int i = 0 ; i < tb; ++i)
    {
        sb += (b-48)*pow(10,i);
    }

    // cout<<ta<<" "<<tb<<" "<<sa<<" "<<sb<<endl;
    cout<<sa+sb<<endl;
    return 0;
}
