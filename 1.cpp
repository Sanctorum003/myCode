#include <iostream>
using namespace std;
#define Sub(x) x*x;

int main(void)
{
    int k = 1;
    cout<<++Sub(k+1);
    cout<<endl;
    return 0;
    // ++x+1*x+1
}