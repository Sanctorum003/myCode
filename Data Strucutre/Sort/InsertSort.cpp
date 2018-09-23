//普通插入排序
void InsertSort(int a[],int n)
{
    int i,j;
    for(i = 2; i <= n;++i)
    {
        if(a[i]<a[i-1])//需排序
        {
            a[0] = a[i];
            for(j = i-1; a[j] > a[0]; --j) //不需要判断j大于0 因为到0时必然退出
            {
                a[j+1]=a[j];
            }
            a[j+1] = a[0];
        }   
    }
}