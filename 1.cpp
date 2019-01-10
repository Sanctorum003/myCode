#include<stdio.h>
int main(){
    int a[3][4];  //a[4][5]
    int b[1][4]; 
    while(scanf("%d",&a)!=EOF){   //这里每次把值读入到a[0][0]了
        int max1=0,max2=0;
        for (int i=0;i<4;i++)
        for(int j=0;j<5;j++)
            a[i][j]=scanf("%d",&a[i][j]);//输入数据
          
          for(int j=0;j<5;j++){
              max1=max2=a[0][j];//把每列第一个数先赋值给max1，和,max2
              for(int i=0;i<4;i++){
                  if(max1<a[i][j]){
                  max1=a[i][j];
                  max2=max1;
                  }
                  b[0][j]=max1;
                  b[1][j]=max2;
          }
        }  
        for(int i=0;i<2;i++){
           for(int j=0;j<5;j++){
               printf("%d ",&b[i][j]);
           }
           printf("\n");
    }
    }
}
