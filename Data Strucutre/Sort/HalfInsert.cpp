//折半插入排序

void HalfInsert(int a[], int n)
{
    int i, j;
    for (i = 2; i <= n; ++i)
    {
        a[0] = a[i];
        int low = 1;
        int high = i - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (a[mid] >= a[0]) //注意条件
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        for (j = i - 1; j >= high + 1; --j) //因为最后一次比较一定是 low == high 所以high一定比待插入位置小一
                                            //或者使用 j>=low 也可以
        {
            a[j + 1] = a[j];
        }

        a[high + 1] = a[0];
    }
}