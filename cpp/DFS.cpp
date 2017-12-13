#include <iostream>
#include <vector>
using namespace std;

#define MAXVEX 20//最大顶点表节点数

bool visited[MAXVEX];

typedef string NodeType;
typedef int EdgeType;

typedef struct list //边表节点
{
	int adjvex;//邻接域,存储顶点的下标
	EdgeType weigh;//权重
	struct list *next;//next指针
}List, *EdgeNode;

typedef struct head //顶点表结点
{
	NodeType data;//顶点域，存储顶点信息
	EdgeNode firstAdjvex;//第一个边表节点
}VextexNode, AdjList[MAXVEX];

typedef struct graph
{
	AdjList adjList;//邻接表
	int edges;//边数
	int nodes;//节点数
}Graph;

void AdjacencyList(Graph &gl)
{
	cout << "输入边数和节点数" << endl;
	cin >> gl.edges;
	cin >> gl.nodes;

	// cout<<"边数:"<<gl.edges<<" "<<"节点数:"<<gl.nodes<<endl;

	cout << "输入顶点信息" << endl;
	for (int i = 0; i < gl.nodes; ++i)
	{
		cin >> gl.adjList[i].data;
		gl.adjList[i].firstAdjvex = NULL;
	}

	int e1;//首边
	int e2;//尾边
	//EdgeType w;//权重
	EdgeNode p;
	cout << "输入边的信息" << endl;

	for (int i = 0; i < gl.edges; ++i)
	{//有权有向图
	 // cout<<"此时i为"<<i<<endl;
		cin >> e1;
		cin >> e2;
		//cin>>w; //权重
		p = new List();
		p->adjvex = e2;
		//p->weigh = w;
		p->next = gl.adjList[e1].firstAdjvex;
		gl.adjList[e1].firstAdjvex = p;
	}
}



void visit(Graph gl, int v)
{
	cout << gl.adjList[v].data << " ";
}//遍历

bool DFS(Graph gl, int v)//从gl的v开始dpf搜索
{
	visited[v] = true;//v点已经访问过了
	visit(gl, v);
	EdgeNode enode;//节点
	for (enode = gl.adjList[v].firstAdjvex; enode; enode = enode->next)
	{
		if (!visited[enode->adjvex])
   		{
			DFS(gl, enode->adjvex);
		}
	}

	return true;
}


int main(void)
{
	Graph gl;
	AdjacencyList(gl);
	//bool *visited = new bool[gl.nodes];//记录dps遍历时节点的状态
	DFS(gl, 0);
	return 0;
}