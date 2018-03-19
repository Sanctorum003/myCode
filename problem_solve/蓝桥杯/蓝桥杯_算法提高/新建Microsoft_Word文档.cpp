#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;//行数
    cin>>n;
    vector<int> cur;//当前文件
    int curAdd = 1;//应该放置的位置
    string s;//输入指令
    int del;//删除序号
    vector<int>::iterator it;
    while(n--)
    {
        cin>>s;
        if(s == "New")
        {
            int i =0 ;
            for(i = 1; i <= cur.size();++i)
            {
                if(i != cur[i-1])
                {
                    curAdd = i;
                    break;
                }
                
            }

            if(i > cur.size())
                curAdd = cur.size()+1;

            cur.push_back(curAdd);
            sort(cur.begin(),cur.end());
            cout<<curAdd<<endl;
        }
        else if(s == "Delete")
        {
            cin>>del;
            if((it = find(cur.begin(),cur.end(),del)) == cur.end())
            {
                cout<<"Failed"<<endl;
            }
            else
            {
                cur.erase(it);
                cout<<"Successful"<<endl;
            }
        }
    }
    return 0;
}