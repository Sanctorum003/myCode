//关键点:一个位置如果重复访问必然冗余，所以bfs时要排除掉已访问过的位置
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define Num 100003

typedef struct Node
{
    int pos;
    int times;
}Node;

int main(void)
{
    bool a[Num];
    fill(a,a+Num,0);
    int x,y;
    cin>>x>>y;
    queue<Node> q;//记录当前位置
    vector<int> v;//记录到达方式
    Node n;//初始位置节点
    n.pos = x;//初始位置
    n.times = 0;//移动
    q.push(n);
    while(!q.empty())
    {
        Node t = q.front();
        q.pop();

        if(t.pos == y)
        {
            v.push_back(t.times);
        }
        else
        {
            if(t.pos+1 >= 0 && t.pos+1 <= Num && a[t.pos+1] == false)
            {
                Node q1;
                q1.pos= t.pos+1;
                q1.times = t.times+1;
                a[t.pos+1] = true;
                q.push(q1);
            }

            if(t.pos-1 >= 0 && t.pos-1 <= Num && a[t.pos-1] == false)
            {
                Node q2;
                q2.pos= t.pos-1;
                q2.times = t.times+1;
                a[t.pos-1] = true;
                q.push(q2);
            }

            if(2*t.pos >= 0 && 2*t.pos <= Num && a[2*t.pos] == false)
            {
                Node q3;
                q3.pos= t.pos*2;
                q3.times = t.times+1;
                a[t.pos*2] = true;
                q.push(q3);
            }

        }
        
    }

    sort(v.begin(),v.end());
    cout<<v[0]<<endl;
    return 0;
}