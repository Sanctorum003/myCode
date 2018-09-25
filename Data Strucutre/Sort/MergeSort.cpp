void Merge(int a[],int low,int mid,int high)
{
    int temp[high-low+1] = {0};
    int i = low;
    int j = mid+1;
    int cnt = 0;
    while(i<=mid && j <= high)
    {
        if(a[i]<=a[j])
            temp[cnt++] = a[i++];
        else
            temp[cnt++] = a[j++];
    }

    while(i<=mid)
        temp[cnt++] = a[i++];
    while(j<=high)
        temp[cnt++] = a[j++];

    for(int k = 0; k < cnt;++k)
        a[low+k] = temp[k];

}

void MergeSort(int a[],int low,int high)
{
    if(low < high)
    {
        int mid = (low+high)/2;
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        Merge(a,low,mid,high);
    }
}