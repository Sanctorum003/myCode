#include <iostream>
#include <vector>
using namespace std;
void replace(vector<int> &v,int i,int j)
{
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void bubbleSort(vector<int> &v)
{
    for(int i = v.size()-1;i>=0;--i)
    {
        for(int j = 0;j < i;++j)
        {
            if(v[j] > v[j+1])
                replace(v,j,j+1);
        }

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
    
    bubbleSort(v);

    for(int i = 0; i < v.size();++i)
    {
        if(i != v.size()-1)
            cout<<v[i]<<" ";
        else
            cout<<v[i];
    }

    return 0;
}