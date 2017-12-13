/**
* Kahn算法
* @author sanctorum003
* @date 2017.10.17（start）~2017.10.20
**/

/* 伪代码
    L ← Empty list that will contain the sorted elements
    S ← Set of all nodes with no incoming edges
    while S is non-empty do
    remove a node n from S
    insert n into L
    foreach node m with an edge e from n to m do
        remove edge e from thegraph
        if m has no other incoming edges then
            insert m into S
    if graph has edges then
        return error (graph has at least onecycle)
    else 
        return L (a topologically sortedorder)
*/
#include <iostream>
#include <string>
#include <list>
#include <queue>
using namespace std;

#define MAXVEX 25
#define INF 0X3f3f3f3f

typedef string VertexType;
typedef int EdgeType;

typedef struct matrix
{
	int numVertexs;
	int numEdges;
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
}GMatrix;

void CreateMatrix(GMatrix &gm)
{//构造邻接矩阵(无向图)
	cout << "边 顶点" << endl;
	cin >> gm.numEdges >> gm.numVertexs;
	cout << "顶点信息" << endl;
	for (int i = 0; i <gm.numVertexs; ++i)
	{
		cin >> gm.vexs[i];
	}

	for (int i = 0; i < gm.numVertexs; ++i)
	{
		for (int j = 0; j < gm.numVertexs; ++j)
		{
			// if (i == j) gm.arc[i][j] = 0;
            // else    gm.arc[i][j] = INF;
            gm.arc[i][j] = 0;
		}
	}
	cout << "边信息" << endl;
	for (int i = 0; i < gm.numEdges; ++i)
	{
		int e1;
		int e2;
		// int w;
        // cin >> e1 >> e2 >> w;
        cin>>e1>>e2;
		// gm.arc[e1][e2] = w;
        // gm.arc[e2][e1] = w;
        gm.arc[e1][e2] = 1; 
	}
}

void TopoSort(GMatrix gm)
{
    list<int> lis;//保存被选择的元素
	queue<int> que;//存储**入度为0**的元素，以备之后操作
	int degree[MAXVEX] = {0};//记录每个节点的入度

	for(int i = 0 ; i < gm.numVertexs; ++i)
	{
		int cnt = 0;
		for(int j = 0; j < gm.numVertexs; ++j)
		{
			if(gm.arc[j][i] == 1)
			{
				cnt++;//如果有到j可以通向i，则入度加1
			}
		}
		degree[i] = cnt;
	}//初始化各个节点的入度

	for(int i = 0 ; i < gm.numVertexs; ++i)
	{
		if(degree[i] == 0)
		{
			que.push(i);
		}
	}//将入度为0的节点进入队列

	while(!que.empty())
	{//当队列不为0时，持续循环
		int tmp = que.front();
		lis.push_back(tmp);
		que.pop();
		degree[tmp]--; //设定degree为-1时表示已被选择
		for(int i = 0; i<gm.numVertexs;++i)
		{//遍历tmp连通的节点
			if(gm.arc[tmp][i] == 1)
			{
				degree[i]--;
				if(degree[i] == 0)
				{
					que.push(i);
				}//如果入度变为0则进入队列
			}
		}
	}

	list<int>::iterator it;
	for(it = lis.begin(); it != lis.end();it++)
	{
		cout<<*it<<" ";
	} 
}

int main(void)
{
    GMatrix gm;
    CreateMatrix(gm);
	TopoSort(gm);
    return 0;
}
