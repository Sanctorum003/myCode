//快速排序：三项切分
void swap(int a[],int i,int j )
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void TriCutSort(int a[],int low,int high)
{
    if(low < high)
    {
        int fro = low;
        int rear = high;
        int i = low+1;
        int v = a[low];

        while(i <= rear)  
        {
            if(a[i] < v )
            {
                swap(a,i,fro);
                i++;
                fro++;
            }
            else if(a[i] > v)
            {
                swap(a,i,rear);
                rear--;
            }
            else
            {
                i++;
            }
        }

        TriCutSort(a,low,fro-1);
        TriCutSort(a,i,high);
    }
}
