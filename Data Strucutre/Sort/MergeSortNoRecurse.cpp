void Merge(int a[],int low,int mid,int high);

int temp[10001] = {0};

void MergeNoRecurse(int a[],int low,int high ,int k )//k为步长
{
    int i = low;//用于从左到右两两归并
    while(i + 2*k -1< high)//  判断 [ k| k ] 串是否有2k长
    {
        Merge(a,i,i+k-1,i+2*k-1);
        i += 2*k;//跳到下两条待归并的串的串首要
    }
    if( i + k -1 < high)//最后两串的长度大于 k 但是小于 2k 
        Merge(a,i,i+k-1,high);
    //若小于k，则不动
}

void MergeSortNoRecurse(int a[],int n)
{
    int k = 1;//单个子串的长度
    while(k <= n)//步长不大于len
    {
        MergeNoRecurse(a,1,n,k);
        k *=2;//2路归并
       
    }
}