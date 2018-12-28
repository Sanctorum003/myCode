#include <iostream>
using namespace std;

int main(void)
{
  string s;
  cin>>s;
  int sum =0;
  for(int i = 0 ; i <(int)s.size();++i)
  {
      int temp = int(s[i] - 48);
      sum+=temp;
  }
  
  s = to_string(sum);
  
  for(int i = 0; i < (int)s.size();++i)
  {
    switch(s[i]-48){
      case 1:
        cout<<"yi";
        break;
      case 2:
        cout<<"er";
        break;
      case 3:
        cout<<"san";
        break;
      case 4:
        cout<<"si";
        break;
      case 5:
        cout<<"wu";
        break;
      case 6:
        cout<<"liu";
        break;
      case 7:
        cout<<"qi";
        break;
      case 8:
        cout<<"ba";
        break;
      case 9:
        cout<<"jiu";
        break;
      case 0:
        cout<<"ling";
        break;
    }
    
    if(i != (int)s.size()-1)
    {
      cout<<" ";
    }
  }
  return 0;
}