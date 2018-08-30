#include <iostream>
#include <vector>
using namespace std;
void replace(vector<int> &v,int i,int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void SelectionSort(vector<int> &v)
{
    for(int i = 0 ; i < v.size(); ++i)
    {
        int minIndex = i;
        for(int j = i; j< v.size();++j)
        {
            if(v[j] < v[minIndex] )
                minIndex = j;
        }
        replace(v,i,minIndex);
    }
}

int main(void)
{
    vector<int> v;
    int n;
    int temp;
    cin>>n;
    while(n--)
    {
        cin>>temp;
        v.push_back(temp);
    }
    
    SelectionSort(v);

    for(int i = 0; i < v.size();++i)
    {
        if(i != v.size()-1)
            cout<<v[i]<<" ";
        else
            cout<<v[i];
    }

    return 0;
}