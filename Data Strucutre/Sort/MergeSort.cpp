#include <iostream>
#include <vector>
using namespace std;
void replace(vector<int> &v, int i, int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void Merge(vector<int> &v, int lo, int mid, int hi, int n)
{
    int a[n] = {0}; //辅助数组
    int i = lo;
    int j = mid+1;
    int cnt = 0;
    while (i <= mid && j <= hi)
    {
        if (v[i] < v[j])
        {
            a[cnt++] = v[i];
            i++;
        }
        else
        {
            a[cnt++] = v[j];
            j++;
        }
    }

    while (i <= mid)
    {
        a[cnt++] = v[i++]; //?????
    }

    while (j <= hi)
    {
        a[cnt++] = v[j++];//?????
    }

    for (int k = 0; k < cnt; ++k)
    {
        v[lo + k] = a[k];
    }
}

void MergeSort(vector<int> &v)
{   // 0 2 4
    //  lo = 0 hi = 1 mid = 1 lo = 2 hi = 3 mid = 3
    //  lo = 0 hi = 3 mid = 2 lo = 4 hi = 7 mid = 6
    int i,n = v.size() - 1;
    int len = 1; //*1
    while (len <= n)
    {
        for ( i = 0; i+2*len <= n; i += 2*len)
        {// 0 1 | 2 3 | 4
            int lo = i;
            int hi = i + 2*len - 1;
            //if (hi > n)
            //    hi = n;
            //int mid = (lo+hi) / 2; // [lo, mid] [mid+1, hi]
            Merge(v, lo, lo+len-1, hi, len);
            //cout<<"相关数据"<<lo<<" "<<mid<<" "<<hi<<endl;
        }
        if ( i+len <= n  ) Merge(v,i,i+len-1,n,0);
        len *= 2;
        /*for (int i = 0; i < v.size(); ++i)
        {
            if (i != v.size() - 1)
                cout << v[i] << " ";
            else
                cout << v[i];
        }
        cout<<endl;*/
    }
}

int main(void)
{
    vector<int> v;
    int n,tt;
    int i,temp;
    cin >> n;
    tt = n;
    while (tt--)
    {
        cin >> temp;
        v.push_back(temp);
    }

    MergeSort(v);

    for ( i = 0; i < n-1 ; ++i)
    {

            cout << v[i] << " ";
    //     else
    //         cout << v[i];
     }
     cout<<v[i];

    return 0;
}