#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int n;
	vector<int> v;
	cin>>n;
	
	int c = 2;
	
	while(c <= n)
	{
		if(n%c == 0)
		{
			v.push_back(c);
			n /= c;
		}
		else
			c++;
	}
	
	for(int i = 0; i < v.size()-1; ++i)
		cout<<v[i]<<"*";
	
	cout<<v[v.size()-1];
	return 0;
}