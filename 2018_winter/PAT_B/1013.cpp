#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n )
{
  int i = 0;
  for(i = 2; i<=sqrt(n);++i)
  {
    if( n %i == 0) break;
  }
  
  if(i > sqrt(n)) return true;
  else return false;
}

int main(void)
{
  int a,b;
  cin>>a>>b;
  int cnt = 0;
  for(int i = 2; cnt <= b;++i)
  {
    if(isPrime(i))
    {
      cnt++;
      if(cnt >= a && cnt <= b)
      {
        cout<<i;
        if( (cnt-a+1)%10 == 0 )
            cout<<endl;
        else
            if(cnt != b)
                cout<<" ";
      }
    }
  }
  return 0;
}














