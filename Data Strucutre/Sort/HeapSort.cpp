void swap(int a[], int i, int j);
void Display(int a[]);

void HeapShiftDown(int a[], int k, int n)
{ //向下调整 构造大顶堆
    a[0] = a[k];
    for (int i = 2 * k; i <= n; i *= 2)
    {
        if (i < n && a[i] < a[i + 1]) // 保证要有右兄弟
            i++;                      //找到左右兄弟中的较大者
        if (a[i] > a[0])
        {
            swap(a, i, k); //孩子比父亲大，交换节点
            k = i;         //更改k值为所交换的孩子
        }
        else
            break; //调整完毕
    }              //从更换节点的位置继续向下调整，未交换的不会影响他的孩子节点
}

void HeapShiftUp(int a[], int k, int n)
{ //向上调整
    a[0] = a[k];

    for (int i = k / 2; i >= 1; i /= 2)
    {
        if (a[i] < a[0])
        {
            swap(a, i, k);
            k = i;
        }
    }
}

void HeapDelete(int a[], int n)
{
    swap(a, 1, n);
    HeapShiftDown(a, 1, n - 1);
}

void HeapInsert(int a[], int key, int n)
{
    a[n + 1] = key;
    HeapShiftUp(a, n + 1, n + 1);
}

void HeapAdjust(int a[], int n)
{
    //通过向下调整构建堆
    for (int i = n / 2; i >= 1; --i)
        HeapShiftDown(a, i, n);
}

void HeapSort(int a[], int n)
{
    HeapAdjust(a,n);
    //堆排序
    for (int i = n; i >= 1; --i)
    {
        swap(a, 1, i);
        HeapShiftDown(a, 1, i - 1); //队前**i-1**搞进行堆调整
    }
}