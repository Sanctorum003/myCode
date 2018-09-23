//QickSort
int Partition(int a[],int i,int j)
{
    int pivot = a[i];
    while(i < j)
    {
        for(;i<j && a[j] >= pivot ;--j);
        a[i] = a[j];
        for(;i<j && a[i] <= pivot ;++i);
        a[j] = a[i];
    }

    a[i] = pivot;
}

void QuickSort(int a[],int low,int high)
{
    if(low < high)
    {
        int pivotpos = Partition(a,low,high);
        QuickSort(a,low,pivotpos-1);
        QuickSort(a,pivotpos+1,high);
    }
}