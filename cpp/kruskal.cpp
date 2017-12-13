#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define MAXVEX 25
#define INF 0x3f3f3f3f

typedef string VertexType;
typedef int EdgeType;

typedef struct matrix
{
    int numVertexs;//节点个数
    int numEdges;//边个数
    VertexType vexs[MAXVEX];//顶点信息
    EdgeType arc[MAXVEX][MAXVEX];//邻接矩阵
}GMatrix;

typedef struct edge
{
    int start;//开始节点
    int end;//结束节点
    int weigh;//权重
}Edge;//边集

bool inc_cmp(Edge a,Edge b)
{
     return a.weigh < b.weigh; 
}

void CreateMatrix(GMatrix &gm)
{//构造邻接矩阵
    cout<<"边 顶点"<<endl;
    cin>>gm.numEdges>>gm.numVertexs;
    cout<<"顶点信息"<<endl;
    for(int i = 0 ; i <gm.numVertexs;++i)
    {
        cin>>gm.vexs[i];
    }

    for(int i = 0; i < gm.numVertexs;++i)
    {
        for(int j = 0; j < gm.numVertexs; ++j)
        {
            if( i == j) gm.arc[i][j] = 0;
            else    gm.arc[i][j] = INF;
        }
    }
    cout<<"边信息"<<endl;
    for(int i = 0; i < gm.numEdges;++i)
    {
        int e1;
        int e2;
        int w;
        cin>>e1>>e2>>w;
        gm.arc[e1][e2] = w;
        gm.arc[e2][e1] = w;
    }
}

int Find_Fa(int fa[],int key)
{//寻找父节点
    while(fa[key] != key)
    {
        key = fa[key];
    }

    return key;
}

void Kruskal(GMatrix gm)
{
    int sum = 0;//最小权重
    Edge e[gm.numEdges];//边集数组
    int cnt = 0;//初始化边集数组时使用
    int k_edge = 0; //生成的边数，最终等于n-1
    int fa[gm.numVertexs];//辅助数组，查看两个节点是否连通（在同一个集合内）
    for(int i =0; i < gm.numVertexs;++i )
    {
        for(int j = i+1; j < gm.numVertexs; ++j)
        {
            if(gm.arc[i][j] != 0  && gm.arc[i][j] != INF)
            {
                e[cnt].start = i<j ? i : j;
                e[cnt].end = i>j ? i : j; 
                e[cnt].weigh = gm.arc[i][j];
                cnt++;
            }
        }
    }//初始化边集数组【从邻接矩阵中提取出边集数组】

    for(int i = 0; i < gm.numVertexs;++i)
    {
        fa[i] = i;
    }//初始化辅助数组，用于探测各个树的根节点


    make_heap(e,e+gm.numEdges,inc_cmp);//构造小顶堆在<algorithm>中
    sort_heap(e,e+gm.numEdges,inc_cmp);//堆排序，之后kruskal算法从最小权值开始测试是否可选


    for(int i = 0; i < gm.numEdges; ++i)
    {//遍历所有边
        if( k_edge == gm.numVertexs - 1) break;//边数达到n-1，最小生成树完成，退出循环
        int tmp1 = Find_Fa(fa,e[i].start);
        int tmp2 = Find_Fa(fa,e[i].end);
        if(tmp1 != tmp2)
        {
            sum += e[i].weigh;//加上权重
            /***
             * **容易出错的地方**
             * 这里采取路径压缩(?)
             * 构造的并查集的树结构只有两层
             * 当两树并起来的时候(i->j)，所有以i为根节点的节点都改为以以j为根节点
             ***/
            for(int i = 0 ; i < gm.numVertexs;++i)
            {
                if(fa[i] == tmp1)
                    fa[i] = tmp2;
            }

            k_edge++;
        }
    }

    cout<<sum<<endl;//输出最小权重

}

int main(void)
{
    GMatrix gm;
    CreateMatrix(gm);
    Kruskal(gm);
    return 0;
}