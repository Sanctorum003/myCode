#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <math.h>
#include <vector>
using namespace std;

#define GET_ARRAY_LEN(array, len)                 \
    {                                             \
        len = (sizeof(array) / sizeof(array[0])); \
    } //return the size of the array
#define SIZE 100000000

int a[SIZE]; //the array need to be sorted

//class statement
class StdOp;
class SelectSort;
class MergeSort;
class QuickSort;
class HeapSort;
//class statement end

class StdOp
{
  public:
    static bool lessTo(int a, int b)
    {
        if (a < b)
            return true;
        else
            return false;
    }

    static void exchange(int *a, int m, int n) //use array
    {
        int temp = 0;
        temp = a[m];
        a[m] = a[n];
        a[n] = temp;
    }

    static void show(int *a, int lo,int hi, string s) //output the array
    {
        cout << s + ":"<<endl;
        for (int i = lo; i <= hi; i++)
            cout << a[i] << " ";
        cout << endl;
    }
};

class SelectSort
{ //static
  public:
    static void selectSort(int *a, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            int min = i;
            for (int j = i + 1; j < n; ++j)
            {
                if (StdOp::lessTo(a[j], a[i]))
                    min = j;
            }
            StdOp::exchange(a, i, min);
        }
    }
};

class MergeSort
{ //need instantiation
  private:
    int *aux;

  private:
    void merge(int *a, int lo, int mid, int hi)
    {
        if (a[mid] <= a[mid + 1])
            return; //优化1

        int n = hi - lo + 1;
        for (int i = lo; i <= hi; ++i)
        {
            aux[i] = a[i];
        }

        int i = lo;
        int j = mid + 1;

        for (int k = lo; k <= hi; ++k)
        {
            if (i > mid)
                a[k] = aux[j++];
            else if (j > hi)
                a[k] = aux[i++];
            else if (StdOp::lessTo(aux[j], aux[i]))
                a[k] = aux[j++];
            else
                a[k] = aux[i++];
        }
    }

    void mergeSort(int *a, int lo, int hi)
    {
        //StdOp::show(aux,hi-lo+1,"a2");
        if (hi <= lo)
            return;
        int mid = (lo + hi) / 2;
        mergeSort(a, lo, mid);
        mergeSort(a, mid + 1, hi);
        merge(a, lo, mid, hi);
    }

  public:
    void mergeSort(int *a, int n)
    {
        aux = new int[n];
        mergeSort(a, 0, n - 1);
    }

    void mergeUnrecursionSort(int *a, int n)
    {
        aux = new int[n];

        for (int sz = 1; sz < n; sz = sz + sz)
        {
            for (int lo = 0; lo < n - sz; lo += sz + sz)
            {
                merge(a, lo, lo + sz - 1, min(n - 1, lo + sz + sz - 1));
            }
        }
    }
};

class QuickSort
{//三取样+快速三向切分+插排
  private:
    static void selectSort(int *a,int lo,int hi)
    {
        for(int i = lo + 1; i <= hi;++i)
        {
            for(int j = i; j > lo && StdOp::lessTo(a[j],a[j-1]);--j)
            {
                StdOp::exchange(a,j,j-1);
            }

        }
    }

    static void triSelected(int *a,int lo,int hi)
    {
        int mid = (lo+hi)/2;
        if(a[lo] > a[mid])  StdOp::exchange(a,lo,mid);
        if(a[lo] > a[hi])   StdOp::exchange(a,lo,hi);
    }

    static int partition(int *a, int lo, int hi)
    {
        triSelected(a,lo,hi);//selected mid from three digits
        int i = lo;
        int j = hi + 1;
        int v = a[lo];

        while (1)
        {
            while (a[++i] < v)
                if (i == hi)
                    break;
            while (v < a[--j])
                if (j == lo)
                    break;
            if (i >= j)
                break;
            StdOp::exchange(a, i, j);
        }

        StdOp::exchange(a, lo, j);
        return j;
    }

  public:
    static void quickSort(int *a, int lo, int hi)
    {
        if (lo + 10 >= hi)
        {
            selectSort(a,lo,hi);
            return;
        }
        int j = partition(a, lo, hi); //shao bin
        quickSort(a, lo, j - 1);
        quickSort(a, j + 1, hi);
    }

    static void triCutQSort(int *a ,int lo ,int hi)
    {
        if (lo + 10 >= hi)
        {
            selectSort(a,lo,hi);
            return;
        }


        triSelected(a,lo,hi);

        //Tri-Cut
        int lt = lo;//head
        int gt = hi;//tail
        int i = lo + 1; //point
        int v = a[lo];//shaobin

        while(i <= gt)
        {
            if(a[i] < v ) 
            {
                StdOp::exchange(a,i,lt);
                lt++;
                i++;
            }
            else if(a[i] > v)
            {
                StdOp::exchange(a,i,gt);
                gt--;
            }
            else
            {
                i++;
            }
        }

        triCutQSort(a,lo,lt-1);
        triCutQSort(a,gt+1,hi);

    }
};

class HeapSort
{//根节点为1
public:
    int *a;//array need to be sorted;
        //a[0]保存当前数组大小

    HeapSort(int n)
    {
        a = new int[n+1];
        memset(a,0,sizeof(a));
    }

    ~HeapSort();

    void swim(int k)//上浮
    {
        while(k>1 && a[k]>a[k/2])
        {
            StdOp::exchange(a,k,k/2);
            k /= 2;
        }
    }

    void sink(int  k)//下沉
    {
        while(2*k <= a[0])
        {
            int tmp = 2 * k ;
            if(tmp < a[0] && a[tmp] < a[tmp+1])    tmp++;//search the max children
            if(a[k] >= a[tmp])  break;// 是否需要下沉
            StdOp::exchange(a,k,tmp);//下沉
            k = tmp;
        }
    }

    void sink(int  k,int n)//下沉
    {
        while(2*k <= n)
        {
            int tmp = 2 * k ;
            if(tmp < n && a[tmp] < a[tmp+1])    tmp++;//search the max children
            if(a[k] >= a[tmp])  break;// 是否需要下沉
            StdOp::exchange(a,k,tmp);//下沉
            k = tmp;
        }
    }

    void insert(int val)
    {
        // cout<<a[0]<<endl;
        a[++a[0]] = val;
        swim(a[0]);
    }

    int delMax(int k)
    {
        int key = a[1];
        StdOp::exchange(a,1,a[0]--);
        sink(1);
        return key;
    }

    void heapSort()
    {
        int tmp = a[0];
        while(tmp > 1)
        {
            // cout<<tmp<<"<before>:"<<a[1]<<" "<<a[tmp]<<endl;
            StdOp::exchange(this->a,1,tmp--);
            // cout<<tmp<<"<before>:"<<a[1]<<" "<<a[tmp]<<endl;
            sink(1,tmp);
        }
    }
};

int main()
{
    srand(1);
    for (int i = 0; i < SIZE; ++i)
    {
        a[i] = rand() % 100000000 + 1;
    }
    int n = 0;
    GET_ARRAY_LEN(a, n);

    // MergeSort ms;
    // ms.mergeSort(a, n);

    // MergeSort ms;
    // double timeStart = clock();
    // ms.mergeUnrecursionSort(a, n);
    // double timeEnd = clock();
    // cout<<"MergeSort("<<SIZE<<"):"<<(double)(timeEnd - timeStart)<<"ms"<<endl;

    

    double timeStart = clock();
    QuickSort::triCutQSort(a, 0, SIZE - 1);
    double timeEnd = clock();
    cout<<"QuickSort("<<SIZE<<"):"<<(double)(timeEnd - timeStart)<<"ms"<<endl;


    // HeapSort *hp = new HeapSort(SIZE);
    // for(int i = 0; i < SIZE;++i)
    // {
    //     hp->insert(rand() % 10 + 1);
    // }

    // hp->heapSort();

    // StdOp::show(hp->a,1,hp->a[0],"Heap Sort");

    return 0;
}