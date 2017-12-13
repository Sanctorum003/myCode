#include <iostream>
#define max(a,b) a>b?a:b
using namespace std;

int M[5050];
int W[220];
int V[220];

int main(void)
{
    int n;//数量
    int m;//总重量
    cin>>n>>m;
    for(int i = 1; i <= n;++i)
        cin>>W[i]>>V[i];

    for(int i = 1; i<=n;++i)
    {
        for(int j = m; j >= W[i]; --j)
            M[j] = max(M[j],M[j-W[i]]+V[i]);
    }

    cout<<M[m]<<endl;
}