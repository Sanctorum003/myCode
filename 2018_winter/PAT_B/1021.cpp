#include <iostream>
using namespace std;

int main(void)
{
  string s;
  cin>>s;
  int a[10] = {0};
  for(int i = 0;i < (int)s.size();++i)
  {
     a[s[i]-48]++;
  }
  for(int i = 0; i < 10;++i)
  {
    cout<<i<<":"<<a[i]<<endl;
  }
  return 0;
}