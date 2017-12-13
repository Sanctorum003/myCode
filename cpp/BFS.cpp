#include <iostream>
#include <queue>
using namespace std;

#define MAXVEX 100//最大顶点数
#define INF 0x3f3f3f3f//无穷大
bool visited[MAXVEX];

typedef string VertexType;//顶点类型
typedef int EdgeType;//边权重类型

typedef struct matrix
{
    int numNodes;//顶点个数
    int numEdges;//边的个数
    VertexType vexs[MAXVEX];//顶点数组
    EdgeType arc[MAXVEX][MAXVEX];//邻接矩阵
}GMatrix;

void CreateMatrix(GMatrix &gm)//构造邻接矩阵
{
    cout<<"输入边数和顶点数"<<endl;
    cin>>gm.numEdges>>gm.numNodes;
    cout<<"输入顶点的信息"<<endl;
    for(int i = 0; i < gm.numNodes;++i)
    {
        cin>>gm.vexs[i];
    }
    cout<<"输入边的信息（无向图）"<<endl;
    for(int i = 0; i < gm.numEdges;++i)
    {
        int e1;
        int e2;
        cin>>e1>>e2;
        gm.arc[e1][e2] = 1;
        gm.arc[e2][e1] = 1;
    }
}

void visit(int i)
{
    visited[i] = true;
    cout<<i<<" ";
}

bool BFS(GMatrix gm,int data)
{
    queue<int> que;
    que.push(data);
    visit(data);
    while(!que.empty())
    {
        int tmp = que.front();
        que.pop();
        for(int i = 0; i < gm.numNodes; ++i)
        {
            if( gm.arc[tmp][i] && !visited[i] )//如果两点有路径且没有访问过
            {
                que.push(i);
                visit(i);//访问节点，入队
            }
        }
    }


    return true;
}

int main(void)
{
    GMatrix gm;
    CreateMatrix(gm);
    for(int i = 0; i <gm.numNodes; ++i)
    {
        for(int j = 0 ; j < gm.numNodes; ++j)
        {
            cout<<gm.arc[i][j]<<" ";
        }
        cout<<endl;
    }

    BFS(gm,0);

    return 0;
}