#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    queue<int> q;
    int n;
    cin>>n;
    int t;
    while(n--)
    {
        cin>>t;
        if(t == 1)
        {
            int data;
            cin>>data;
            q.push(data);
        }
        else if(t == 2)
        {
            if(q.size() != 0)
            {
                cout<<q.front()<<endl;
                q.pop();
            }
            else
            {
                cout<<"no"<<endl;
            }
        }
        else if(t == 3)
            cout<<q.size()<<endl;
    }
}