#include <iostream>
#define N 11
using namespace std;
int a[N + 1] = {0, 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

void InsertSort(int a[], int n);
void HalfInsert(int a[], int n);
void BubbleSort(int a[], int n);

void Display(int a[])
{
    for (int i = 1; i <= N; ++i)
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

    Display(a);

    return 0;
}