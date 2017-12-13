#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define MAXVEX 20
#define INF 0x3f3f3f3f

typedef string VertexType;
typedef int EdgeType;

typedef struct matrix
{
	int numNodes;
	int numEdges;
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
}GMatrix;//邻接矩阵数据结构

void CreateMatrix(GMatrix &gm)//构造邻接矩阵
{
	queue<VertexType> que;
	cout << "边 顶点" << endl;
	cin >> gm.numEdges;
	cin >> gm.numNodes;
	cout << "顶点信息" << endl;
	for (int i = 0; i < gm.numNodes; ++i)
	{
		cin >> gm.vexs[i];
	}

	for (int i = 0; i < gm.numNodes; ++i)
	{//初始化有向带权图
		for (int j = 0; j < gm.numNodes; ++j)
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
		int w;//权重
		cin >> e1 >> e2 >> w;
		gm.arc[e1][e2] = w;
		gm.arc[e2][e1] = w;
	}
}

void Prim(GMatrix gm, int s)
{
	int sum = 0;//权值和
	int curP = s;//当前位置
				 //当前节点到adj[i]的权值为lowcost[i]
                 //当lowcost[i] == 0 时表示以选择
    EdgeType lowcost[MAXVEX];
	int adjvex[MAXVEX];
	for (int i = 0; i < gm.numEdges; ++i)
	{
        lowcost[i] = INF;
        //cout<<lowcost[i]<<endl;
	}//初始化
	for (int i = 0; i < gm.numNodes; ++i)
	{
        adjvex[i] = s;
        //cout<<adjvex[i]<<endl;
    }//节点初始化
    
    
	lowcost[s] = 0; //初始点已被选择
	// cout << gm.vexs[s] << "->";//输出轨迹

							   //PRIM算法
							   //n个节点的树有n-1条边，所以进行n-1次循环找选取n-1条边
							   //第一个节点已经选定
	for (int i = 0; i < gm.numNodes - 1; ++i)
	{//进行n-1次选边
		for (int j = 0; j < gm.numNodes; ++j)
		{//遍历邻接矩阵来更新lowcost和adjvex
			if (gm.arc[curP][j] < lowcost[j] && lowcost != 0)
			{//如果curP到j的路径长度小于原来的路径长度并且j没有被选过则更新
				lowcost[j] = gm.arc[curP][j];//更新值
				adjvex[j] = curP;//更新目标节点
			}
		}

		int min = INF;
		int minNodes;
		for (int i = 0; i < gm.numNodes; ++i)
		{//遍历lowcost,寻找最小代价边
			if (lowcost[i] != 0 && lowcost[i] < min)
			{
				min = lowcost[i];
				minNodes = i;
			}
		}

		//进行相关操作
		sum += lowcost[minNodes];
		lowcost[minNodes] = 0;//将已经选择的代价置0
        cout << gm.vexs[adjvex[minNodes]]<<"->"<<gm.vexs[minNodes] << endl;
        curP = minNodes;//当前的节点变为minNodes
	}

	cout << sum << endl;
}

int main(void)
{
	GMatrix gm;
	CreateMatrix(gm);
	// for(int i = 0; i <gm.numNodes; ++i)
	// {
	//     for(int j = 0 ; j < gm.numNodes; ++j)
	//     {
	//         cout<<gm.arc[i][j]<<" ";
	//     }
	//     cout<<endl;
	// }
	Prim(gm, 3)
	return 0;
}