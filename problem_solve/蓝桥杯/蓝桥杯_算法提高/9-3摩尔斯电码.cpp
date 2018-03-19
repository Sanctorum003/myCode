#include <iostream>
#include <cstring>
using namespace std;

void pp(string  s)  
{  
    if ("*-" == s)  
      cout<<"a";  
    else if ("-***" == s)  
       cout<<"b";  
    else if ( "-*-*" ==s)  
      cout<<"c";  
    else if ( "-**" ==s)  
       cout<<"d";  
    else if ( "*" ==s)  
      cout<<"e";  
    else if ( "**-*" ==s)  
       cout<<"f";  
        else if ( "--*" ==s)  
      cout<<"g";  
    else if ( "****" ==s)  
       cout<<"h";  
        else if ( "**" ==s)  
      cout<<"i";  
    else if ( "*---" ==s)  
       cout<<"j";  
        else if ( "-*-" ==s)  
      cout<<"k";  
    else if ( "*-**" ==s)  
       cout<<"l";  
        else if ( "--" ==s)  
      cout<<"m";  
    else if ( "-*" ==s)  
       cout<<"n";  
        else if ( "---" ==s)  
      cout<<"o";  
    else if ( "*--*" ==s)  
       cout<<"p";  
        else if ( "--*-" ==s)  
      cout<<"q";  
    else if ( "*-*" ==s)  
       cout<<"r";  
        else if ( "**" ==s)  
      cout<<"s";  
    else if ( "-" ==s)  
       cout<<"t";  
        else if ( "**-" ==s)  
      cout<<"u";  
    else if ( "***-" ==s)  
       cout<<"v";  
       else if ( "*--" ==s)  
      cout<<"w";  
    else if ( "-**-" ==s)  
       cout<<"x";  
        else if ( "-*--" ==s)  
      cout<<"y";  
    else if ( "--**" ==s)  
       cout<<"z";  
}  


int main(void)
{
    string s;
    cin>>s;
    while(s.size() != 0)
    {
        int i = 0;
        for(i = 0; i < s.size();++i)
        {
            if(i == s.size()-1)
            {
                pp(s.substr(0,s.size()));
                return 0;
            }


            if(s[i] == '|')
            {
                // cout<<s.substr(0,i)<<endl;
                pp(s.substr(0,i));
                s = s.substr(i+1,s.size()-1);
                // cout<<endl;
                // cout<<s<<endl;
                break;
            }
        }
 
    }
    return 0;
}