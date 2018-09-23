//冒泡排序
void Exchange(int a[],int i,int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] =temp;
}

void BubbleSort(int a[], int n)
{
    for(int i = 1; i<=n;++i)
    {
        bool flag = false;
        for(int j = n; j > i ;--j)
        {
            if(a[j] < a[j-1])
            {
                Exchange(a,j-1,j);
                flag = true;
            }
        }

    if(flag == false)
        return; 
    }

}