/**
* DFS方式
* @author sanctorum003
* @date 2017.10.20
**/

/* 伪代码
    L ← Empty list that will contain the sorted nodes
    S ← Set of all nodes with no outgoing edges
    for each node n in S do
        visit(n) 
    function visit(node n)
        if n has not been visited yet then
            mark n as visited
            for each node m with an edgefrom m to ndo
                visit(m)
            add n to L
*/

#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <stack>
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

bool visited[MAXVEX];//节点是否被访问
list<int> lis;//保存被选择的元素,TopoSort为结果逆序所以用栈数据结构

void visit(GMatrix gm,int k)
{
	visited[k] = true;//访问节点
	int i = 0;
	for(i = 0; i<gm.numVertexs;++i)
	{
		if(gm.arc[i][k] == 1 && !visited[i])
		{
			visit(gm ,i);
		}
	}
	lis.push_back(k);
}

void TopoSort(GMatrix gm)
{
	queue<int> que;//保存**无出度**的节点
	int degree[MAXVEX] = {0};//记录每个节点的**出度**

	for(int i = 0 ; i < gm.numVertexs;++i)
	{
		for(int j = 0; j < gm.numVertexs;++j)
		{
			if(gm.arc[i][j] == 1)
			{
				degree[i]++;
			}
		}
	}//初始化每个节点的出度

	// for(int i = 0 ; i < gm.numVertexs; ++i)
	// {
	// 	cout<< degree[i]<<" ";
	// }
	// cout<<endl;

	for(int i = 0; i < gm.numVertexs;++i)
	{
		if(degree[i] == 0)
		{
			visit(gm,i);
		}
	}
}


int main(void)
{
    GMatrix gm;
    CreateMatrix(gm);
	TopoSort(gm);

	list<int>::iterator it;
	for(it = lis.begin(); it != lis.end();it++)
	{
		cout<<*it<<" ";
	}
    return 0;
}