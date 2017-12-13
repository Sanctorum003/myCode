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
}GMatrix;//�ڽӾ������ݽṹ

void CreateMatrix(GMatrix &gm)//�����ڽӾ���
{
	queue<VertexType> que;
	cout << "�� ����" << endl;
	cin >> gm.numEdges;
	cin >> gm.numNodes;
	cout << "������Ϣ" << endl;
	for (int i = 0; i < gm.numNodes; ++i)
	{
		cin >> gm.vexs[i];
	}

	for (int i = 0; i < gm.numNodes; ++i)
	{//��ʼ�������Ȩͼ
		for (int j = 0; j < gm.numNodes; ++j)
		{
			if (i == j) gm.arc[i][j] = 0;
			else    gm.arc[i][j] = INF;
		}
	}

	cout << "����Ϣ" << endl;

	for (int i = 0; i < gm.numEdges; ++i)
	{
		int e1;
		int e2;
		int w;//Ȩ��
		cin >> e1 >> e2 >> w;
		gm.arc[e1][e2] = w;
		gm.arc[e2][e1] = w;
	}
}

void Prim(GMatrix gm, int s)
{
	int sum = 0;//Ȩֵ��
	int curP = s;//��ǰλ��
				 //��ǰ�ڵ㵽adj[i]��ȨֵΪlowcost[i]
                 //��lowcost[i] == 0 ʱ��ʾ��ѡ��
    EdgeType lowcost[MAXVEX];
	int adjvex[MAXVEX];
	for (int i = 0; i < gm.numEdges; ++i)
	{
        lowcost[i] = INF;
        //cout<<lowcost[i]<<endl;
	}//��ʼ��
	for (int i = 0; i < gm.numNodes; ++i)
	{
        adjvex[i] = s;
        //cout<<adjvex[i]<<endl;
    }//�ڵ��ʼ��
    
    
	lowcost[s] = 0; //��ʼ���ѱ�ѡ��
	// cout << gm.vexs[s] << "->";//����켣

							   //PRIM�㷨
							   //n���ڵ������n-1���ߣ����Խ���n-1��ѭ����ѡȡn-1����
							   //��һ���ڵ��Ѿ�ѡ��
	for (int i = 0; i < gm.numNodes - 1; ++i)
	{//����n-1��ѡ��
		for (int j = 0; j < gm.numNodes; ++j)
		{//�����ڽӾ���������lowcost��adjvex
			if (gm.arc[curP][j] < lowcost[j] && lowcost != 0)
			{//���curP��j��·������С��ԭ����·�����Ȳ���jû�б�ѡ�������
				lowcost[j] = gm.arc[curP][j];//����ֵ
				adjvex[j] = curP;//����Ŀ��ڵ�
			}
		}

		int min = INF;
		int minNodes;
		for (int i = 0; i < gm.numNodes; ++i)
		{//����lowcost,Ѱ����С���۱�
			if (lowcost[i] != 0 && lowcost[i] < min)
			{
				min = lowcost[i];
				minNodes = i;
			}
		}

		//������ز���
		sum += lowcost[minNodes];
		lowcost[minNodes] = 0;//���Ѿ�ѡ��Ĵ�����0
        cout << gm.vexs[adjvex[minNodes]]<<"->"<<gm.vexs[minNodes] << endl;
        curP = minNodes;//��ǰ�Ľڵ��ΪminNodes
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