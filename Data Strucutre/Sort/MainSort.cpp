#include <iostream>
#define N 9
using namespace std;
int a[N + 10] = {0,3,1,4,1,5,9,2,6,5};

void InsertSort(int a[], int n);
void HalfInsert(int a[], int n);
void BubbleSort(int a[], int n);
void ShellSort(int a[],int n);
void QuickSort(int a[],int low ,int high);
void TriCutSort(int a[],int low,int high);
void SelectSort(int a[],int n);
void HeapSort(int a[],int n);
void HeapAdjust(int a[],int n);
void HeapInsert(int a[],int key,int n);

void Display(int a[],int n)
{
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

int main(void)
{
    // for(int i = 1 ; i <= N ; ++ i)
    //     cin>>a[i];

    string s;
    cin >> s;
    if (s == "i")
        InsertSort(a, N);
    else if (s == "hi")
        HalfInsert(a, N);
    else if(s == "b")
        BubbleSort(a,N);
    else if(s == "shell")
        ShellSort(a,N);
    else if(s == "q")
        QuickSort(a,1,N);
    else if(s == "qt")
        TriCutSort(a,1,N);
    else if(s == "sel")
        SelectSort(a,N);
    else if(s == "heap")
        HeapSort(a,N);

    // HeapAdjust(a,N);

    Display(a,N);

    // HeapInsert(a,100,N);

    // Display(a,N+1);

    return 0;
}