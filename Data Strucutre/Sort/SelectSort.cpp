void swap(int a[],int i ,int j);

void SelectSort(int a[],int n)
{
    for(int i = 1;i<=n;++i)
    {
        int min = i;
        for(int j = i;j<=n;++j)
        {
            if(a[j] < a[min])
                min = j;
        }
        
        swap(a,i,min);
        
    }

}