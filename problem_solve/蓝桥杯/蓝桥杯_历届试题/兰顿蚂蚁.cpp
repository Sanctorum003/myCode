#include <iostream>
#include <cstring>
using namespace std;

//UDLR 上下左右

int main(void)
{
    int row,column;//方格行列
    cin>>row>>column;
    int sq[row][column]={0};
    memset(sq,0,sizeof(sq));
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < column;++j)
            cin>>sq[i][j];//输入方格数据
    int posX,posY;//蚂蚁所在位置
    cin>>posX>>posY;
    char head;//朝向
    cin>>head;
    int step;//步数
    cin>>step;

    for(int i = 0; i<step;++i)
    {
        if(sq[posX][posY] == 0)//黑 左转 白 右转
        {//为白
            sq[posX][posY] = 1; //变黑
            if(head == 'U')
            {
                head = 'L';//转向
                posY--;//前进
            }
            else if(head == 'L') 
            {
                head = 'D';
                posX++;
            }
            else if(head == 'D')
            {
                head = 'R';
                posY++;
            }
            else
            {
                head = 'U';
                posX--;
            }
        }
        else
        {
            sq[posX][posY] = 0; //变 白
            if(head == 'U')
            {
                head = 'R';//转向
                posY++;//前进
            }
            else if(head == 'L') 
            {
                head = 'U';
                posX--;
            }
            else if(head == 'D')
            {
                head = 'L';
                posY--;
            }
            else
            {
                head = 'D';
                posX++;
            }
            
        } 
    }

    cout<<posX<<" "<<posY<<endl;

    return 0;
}