#include <iostream>
using namespace std;

int main(void)
{
    int  n;
    cin>>n;
    if(n <= 0)  return 0;
    int sum = 0;
    int temp;
    for(int i = 0; i < n; ++i)
    {
        cin>>temp;
        sum += temp;
    }

    cout<<sum<<" "<<sum/n<<endl;
    

    return 0;
}