#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
  int n;
  cin>>n;
  int a;

  while(n--)
  {  
    int k ;
    cin>>a;;
    int cnt;
    if(a / 1000 > 0 ) cnt = 4;
    else if(a / 100 > 0) cnt = 3;
    else if(a / 10 > 0) cnt = 2;
    else if(a / 1 > 0) cnt = 1;
    for(k = 0; k < 10; ++k)
    {
      if(a == (k*a*a) % (int)pow(10,cnt))
        break;
    }

    if( k < 10)
        cout<<k<<" "<<k*a*a<<endl;
    else
        cout<<"No"<<endl;
  }
  return 0;
}