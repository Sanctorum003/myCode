#include <iostream>
using namespace std;
int a[100][100]={0};

int main(void){
    int row,col;
    cin>>row>>col;
    int cnt = 1;
    for(int j = 0; j<col;++j)
    {
        for(int i = 0; i <row;++i)
        {
            a[i][j] = cnt++;
        }
    }
    
    for(int i = 0; i < row;++i)
    {
        for(int j = 0;j<col;++j)
        {
            cout<<a[i][j];
            if(j != col-1)
                cout<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}