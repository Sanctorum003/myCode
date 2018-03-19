#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    cin>>n;
    vector<int> v;
    vector<int> w;
    int temp;
    for(int i = 0 ; i < n; ++i)
    {
        cin>>temp;
        v.push_back(temp);
    }

    w  = v;

    sort(w.begin(),w.end());
    int max = w[n-1];
    int pos = find(v.begin(),v.end(),max) - v.begin() ;

    cout<<max<<" "<<pos;
    return 0;
}