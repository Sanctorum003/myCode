/**
* @author sanctorum003
* @date 2017.10.16
**/
#include <iostream>
#include <string>
using namespace std;

#define MAXVEX 25
#define INF 0X3f3f3f3f

bool visited[MAXVEX];//节点是否被访问过
int Path[MAXVEX];//path记录最短路径上从v0到i的前一个顶点
int dist[MAXVEX];//Dist为v0到path的长度

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
{//构造邻接矩阵
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
			if (i == j) gm.arc[i][j] = 0;
			else    gm.arc[i][j] = INF;
		}
	}
	cout << "边信息" << endl;
	for (int i = 0; i < gm.numEdges; ++i)
	{
		int e1;
		int e2;
		int w;
		cin >> e1 >> e2 >> w;
		gm.arc[e1][e2] = w;
		// gm.arc[e2][e1] = w;
	}
}

void Djikstra(GMatrix &gm, int v0)
//gm邻接矩阵
//v0开始位置
{
	for (int i = 0; i < gm.numVertexs; ++i)
	{
		dist[i] = gm.arc[v0][i];//将dist数组的值改为vo到i的路径长度
								//cout<<gm.arc[v0][i]<<" "<<dist[i]<<endl;
		if (gm.arc[v0][i] > 0)//如果直接相连
			Path[i] = v0;//将path数组记为V0，及如果选择这个节点，前一个节点为v0
		else
			Path[i] = -1;//不然记为-1表示无前一节点
	}

	dist[v0] = 0;//v0到v0的长度为0
	Path[v0] = v0;
	visited[v0] = true;//v0已经被选中

	for (int i = 0; i < gm.numVertexs - 1; ++i)
    {//最短路径肯定取n-1条边（n为节点个数）
        int minEdge = INF;//用于查看源节点到某一节点的最短路径
        int minVertex = 0;//minEdge的目标节点
		for (int j = 0; j < gm.numVertexs; ++j)
		{
			if (minEdge > dist[j] && visited[j] == false)
			{//找到vo到哪个节点距离最短 并且 此节点为被访问
				minEdge = dist[j];//最短长度
				minVertex = j;//最短长度的目标节点
			}
		}

		// cout << "minVertex " << minVertex << endl;
		visited[minVertex] = true;

		for (int j = 0; j < gm.numVertexs; ++j)
		{//对path数组以及dist数组进行更新
			if (dist[j] > gm.arc[minVertex][j] && visited[j] == false)
			{
				dist[j] = gm.arc[minVertex][j];//更新dist的值
				Path[j] = minVertex;//因为更新了dist，所以path更改指向
			}
		}
	}
}

int main(void)
{
	GMatrix gm;
	CreateMatrix(gm);
	for (int i = 0; i<gm.numVertexs; ++i)
	{
		for (int j = 0; j < gm.numVertexs; ++j)
		{
            if(gm.arc[i][j] != INF)
                cout << gm.arc[i][j] << " ";
            else
                cout << "INF" << " "; 
		}
		cout << endl;
    }
    
    Djikstra(gm, 0);

    for(int i = 0 ; i < gm.numVertexs; ++i)
    {
        if(dist[i] != INF)
            cout<<gm.vexs[Path[i]]<<"->"<<gm.vexs[i]<<":"<<dist[i]<<endl;
        else
        cout<<gm.vexs[Path[i]]<<"->"<<gm.vexs[i]<<":"<<"INF"<<endl;
    }
	return 0;
}