#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(void)
{
    string a,b;
    vector<int> v[50];
    vector<int> res;
    int cnt = 0;
    cin>>a>>b;

    if( a == "0" || b == "0")
    {
        cout<<0;
        return 0;
    }

    int p = 0;//进位调整位
    for(int i = b.size() - 1 ; i >= 0 ;--i)
    {//模拟一开始的相乘，注意保存在vector中的逆序
        for(int k = 0; k < cnt; ++k)
        {
            v[cnt].push_back(0);//加上合适多个0用于错位相加
        }

        for(int j = a.size() - 1; j>= 0; --j)
        {
            // cout<<(b.at(i)-'0') * (a.at(j)-'0')<<endl;
            int tmp = (b.at(i)-'0') * (a.at(j)-'0') + p;//乘积+前一位的进位
            int cur = tmp % 10;//当前位
            v[cnt].push_back(cur);
            p = tmp / 10;

            if(j == 0)
            {//一行里的最后一位
                if(p != 0)
                {
                    v[cnt].push_back(p);
                    p = 0;//清零
                }
                cnt++;//为下个i使用新的vector  
            }
        }
    }

    // for(int i = 0; i < cnt; ++i){
    //     for(int j = 0 ; j < v[i].size();++j)
    //         cout<<v[i][j];
    //     cout<<endl;
    // }


    //模拟错位相加，注意结果是逆序输出的，所以先扔入vector中
    int q = 0; // 进位调整位
    for(int j = 0; j <v[cnt-1].size(); ++j)
    {//取vector中每一位
        int tmp = 0;
        for(int i = 0; i < cnt ; ++i)
        {//对每一个vector进行操作
            if(j < v[i].size())//对于有意义的位置进行相加
                tmp += v[i][j];
        }
        tmp +=q;
        // cout<<tmp<<endl;
        res.push_back(tmp % 10);
        q = tmp/10;

        if(j == v[cnt-1].size()-1)//最后一位
        {
            if(q != 0)
                res.push_back(q);//如果还有进位则加入vector
        }
        // cout<<res[j];
    }

    // cout<<endl;

    for(int i = res.size() - 1; i>=0;--i)
        cout<<res[i];
    cout<<endl;

    return 0;
}
//774980393241726
//774980393241726