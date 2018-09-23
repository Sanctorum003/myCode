//ShellSort
void ShellSort(int a[],int n)
{
    int i,j,k;
    for(i = n/2;i>=1;i/=2)//i为步长
    {
        for(j = i+1;j<=n;++j)//i+1因为a[i]从1开始存数据
        {
            if(a[j] < a[j-i])//需排序
            {
                a[0] = a[j];
                for(k = j-i;a[k] > a[0] && k > 0;k-=i) // j>0的原因
                {
                    a[k+i] = a[k];
                }
                a[k+i] = a[0];
            }
        }
    }
}