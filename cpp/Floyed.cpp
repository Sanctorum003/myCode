/**
* @author sanctorum003
* @date 2017.10.17
**/
#include <iostream>
#include <string>
using namespace std;

#define MAXVEX 25
#define INF 0X3f3f3f3f

typedef string VertexType;
typedef int EdgeType;

int dist[MAXVEX][MAXVEX];//存储i到j的最短路径
int path[MAXVEX][MAXVEX];//存储i到j需要经过哪个节点

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

void Floyed(GMatrix gm)
{//利用动态规划的思想
    for(int i = 0 ; i < gm.numVertexs;++i)
    {
        for(int j = 0 ; j < gm.numVertexs; ++j)
        {
            dist[i][j] = gm.arc[i][j];//用邻接矩阵初始化 路径长度 数组
            path[i][j] = j;//用j（即目标节点）初始化 路径 数组
        }
    }

    for(int i = 0 ; i < gm.numVertexs; ++i)
    {
        for(int j = 0; j < gm.numVertexs; ++j)
        {
            for(int k = 0; k < gm.numVertexs; ++k)
            {//必须是 按次循环 => 遍历j到k的路径长度，比较中间途径0，1，2... 
             //即j到k的路径中间增加序号不大于0的节点 => j到k的路径中间增加序号不大于1的节点 => ...
             //这样没后一次更新可以用到前一次更新时路径长度的最优值（动态规划）
             //通过结果path数组，可以看出多次跳转。具体可以自己看最终的path数组

             //如果使用i到j的路径长度，本次循环中比较中间途径0,1,2...
             //更新的时候用到的dist[i][j]并非最优值，答案最终不正确
                if(dist[j][i]+dist[i][k] < dist[j][k])
                {
                    dist[j][k] = dist[j][i]+dist[i][k];//路径长度变为更小的值
                    path[j][k] = i; //从i到k的距离最短需要通过j
                }

            }
        }
    }

}

int main(void)
{
    GMatrix gm;
    CreateMatrix(gm);
    Floyed(gm);

    for(int i = 0 ; i < gm.numVertexs;++i)
    {
        for(int j = 0 ; j < gm.numVertexs; ++j)
        {
            if(dist[i][j] != INF)
                cout<<dist[i][j]<<" ";
            else
                cout<<"INF ";
        }
        cout<<endl;
    }

    for(int i = 0 ; i < gm.numVertexs;++i)
    {
        for(int j = 0 ; j < gm.numVertexs; ++j)
        {
            if(dist[i][j] != INF)
                cout<<path[i][j]<<" ";
            else
                cout<<"-1 ";
        }
        cout<<endl;
    }
    return  0;
}