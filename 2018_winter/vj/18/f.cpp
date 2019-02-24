#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    int m,n,k;
    cin>>m>>n>>k;
    queue<int> man;
    queue<int> woman;
    for(int i=1; i<=m;++i)
        man.push(i);
    for(int i=1; i<=n;++i)
        woman.push(i);

    while(k--)
    {
        int a,b;
        a = man.front();
        b = woman.front();
        man.push(a);
        woman.push(b);
        man.pop();
        woman.pop();
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}