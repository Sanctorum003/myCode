//并查集
#include <iostream>
#include <cmath>
using namespace std;

#define MAXNODE 25

typedef struct tree
{
    int data;//节点值
    int parent;//父亲节点下标
} UTree[MAXNODE];


void InitUnion(UTree ut,int n)
{//初始化函数
    cout<<"输入数据和父亲节点"<<endl;
    for(int i = 0 ; i < n ; ++i)
    {
        cin>>ut[i].data;
        cin>>ut[i].parent;
    }
}

int FindNode(UTree ut,int n,int key)
{//查找节点，找到返回此节点的下标
    int i = 0;
    for(i =0 ; i < n; ++i)
    {
        if(ut[i].data == key) break;
    }

    if(i >= n ) return -1;//未找到待查值

    return i;
}

int FindRoot(UTree ut,int n ,int key)
{
    int node = FindNode(ut,n,key);
    while(ut[node].parent >= 0)
    {//当父亲节点存在
        node = ut[node].parent;
    }

    return node;
}

void Union(UTree ut,int n,int x,int y)
{
    int root1 = FindRoot(ut,n,x);
    int root2 = FindRoot(ut,n,y);
    if(abs(ut[root1].parent) > abs(ut[root2].parent))
    {//root1的集合比root2的集合大就把root2并到root1上
        ut[root1].parent = -(abs(ut[root1].parent)+abs(ut[root2].parent));//重新设定集合个数
        ut[root2].parent = root1;//将root2并到root1
    }
    else
    {
        ut[root2].parent = -(abs(ut[root1].parent)+abs(ut[root2].parent));//重新设定集合个数
        ut[root1].parent = root2;//将root1并到root2
    }
}

int main(void)
{
    cout<<"节点个数"<<endl;
    int n;
    cin>>n;
    UTree ut;
    InitUnion(ut,n);

    int x;
    int y;
    cout<<"X Y"<<endl;
    cin>>x>>y;
    Union(ut,n,x,y);

    for(int i = 0; i < n;++i)
    {
        cout<<ut[i].data<<" "<<ut[i].parent<<endl;
    }
    return 0;
}