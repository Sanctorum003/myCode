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

int dist[MAXVEX][MAXVEX];//�洢i��j�����·��
int path[MAXVEX][MAXVEX];//�洢i��j��Ҫ�����ĸ��ڵ�

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

void Floyed(GMatrix gm)
{//���ö�̬�滮��˼��
    for(int i = 0 ; i < gm.numVertexs;++i)
    {
        for(int j = 0 ; j < gm.numVertexs; ++j)
        {
            dist[i][j] = gm.arc[i][j];//���ڽӾ����ʼ�� ·������ ����
            path[i][j] = j;//��j����Ŀ��ڵ㣩��ʼ�� ·�� ����
        }
    }

    for(int i = 0 ; i < gm.numVertexs; ++i)
    {
        for(int j = 0; j < gm.numVertexs; ++j)
        {
            for(int k = 0; k < gm.numVertexs; ++k)
            {//������ ����ѭ�� => ����j��k��·�����ȣ��Ƚ��м�;��0��1��2... 
             //��j��k��·���м�������Ų�����0�Ľڵ� => j��k��·���м�������Ų�����1�Ľڵ� => ...
             //����û��һ�θ��¿����õ�ǰһ�θ���ʱ·�����ȵ�����ֵ����̬�滮��
             //ͨ�����path���飬���Կ��������ת����������Լ������յ�path����

             //���ʹ��i��j��·�����ȣ�����ѭ���бȽ��м�;��0,1,2...
             //���µ�ʱ���õ���dist[i][j]��������ֵ�������ղ���ȷ
                if(dist[j][i]+dist[i][k] < dist[j][k])
                {
                    dist[j][k] = dist[j][i]+dist[i][k];//·�����ȱ�Ϊ��С��ֵ
                    path[j][k] = i; //��i��k�ľ��������Ҫͨ��j
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