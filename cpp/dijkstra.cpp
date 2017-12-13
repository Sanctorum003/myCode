/**
* @author sanctorum003
* @date 2017.10.16
**/
#include <iostream>
#include <string>
using namespace std;

#define MAXVEX 25
#define INF 0X3f3f3f3f

bool visited[MAXVEX];//�ڵ��Ƿ񱻷��ʹ�
int Path[MAXVEX];//path��¼���·���ϴ�v0��i��ǰһ������
int dist[MAXVEX];//DistΪv0��path�ĳ���

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
{//�����ڽӾ���
	cout << "�� ����" << endl;
	cin >> gm.numEdges >> gm.numVertexs;
	cout << "������Ϣ" << endl;
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
	cout << "����Ϣ" << endl;
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
//gm�ڽӾ���
//v0��ʼλ��
{
	for (int i = 0; i < gm.numVertexs; ++i)
	{
		dist[i] = gm.arc[v0][i];//��dist�����ֵ��Ϊvo��i��·������
								//cout<<gm.arc[v0][i]<<" "<<dist[i]<<endl;
		if (gm.arc[v0][i] > 0)//���ֱ������
			Path[i] = v0;//��path�����ΪV0�������ѡ������ڵ㣬ǰһ���ڵ�Ϊv0
		else
			Path[i] = -1;//��Ȼ��Ϊ-1��ʾ��ǰһ�ڵ�
	}

	dist[v0] = 0;//v0��v0�ĳ���Ϊ0
	Path[v0] = v0;
	visited[v0] = true;//v0�Ѿ���ѡ��

	for (int i = 0; i < gm.numVertexs - 1; ++i)
    {//���·���϶�ȡn-1���ߣ�nΪ�ڵ������
        int minEdge = INF;//���ڲ鿴Դ�ڵ㵽ĳһ�ڵ�����·��
        int minVertex = 0;//minEdge��Ŀ��ڵ�
		for (int j = 0; j < gm.numVertexs; ++j)
		{
			if (minEdge > dist[j] && visited[j] == false)
			{//�ҵ�vo���ĸ��ڵ������� ���� �˽ڵ�Ϊ������
				minEdge = dist[j];//��̳���
				minVertex = j;//��̳��ȵ�Ŀ��ڵ�
			}
		}

		// cout << "minVertex " << minVertex << endl;
		visited[minVertex] = true;

		for (int j = 0; j < gm.numVertexs; ++j)
		{//��path�����Լ�dist������и���
			if (dist[j] > gm.arc[minVertex][j] && visited[j] == false)
			{
				dist[j] = gm.arc[minVertex][j];//����dist��ֵ
				Path[j] = minVertex;//��Ϊ������dist������path����ָ��
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