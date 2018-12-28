#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
  int a;
  int b;
  vector<int> v;
  cin>>a>>b;
  int sum = a*b;
  string s = to_string(sum);
  for(int i = 0; i < (int)s.size();++i)
  {
    v.push_back(s[i]-48);
  }
  reverse(v.begin(),v.end());
  bool flag = false;
  for(int i = 0; i <= v.size()-1 ;++i)
  {
      if(v[i] || falg )
      {
        cout<<v[i];
        flag = true;
      }
  }

  return 0;
}