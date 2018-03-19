#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    string s;
    vector<char> v;
    cin>>s;
    for(int i = 0; i <s.length();++i)
    {
        if(islower(s.at(i)))
            v.push_back(toupper(s.at(i)));
        else if(isupper(s.at(i)))
            v.push_back(tolower(s.at(i)));
    }

    for(int i = 0; i < v.size();++i)
        cout<<v[i];
    return 0;
}