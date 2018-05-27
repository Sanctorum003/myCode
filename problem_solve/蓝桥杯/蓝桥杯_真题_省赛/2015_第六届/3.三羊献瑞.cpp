//https://blog.csdn.net/qq_34594236/article/details/60145252
/*
#include <iostream>
using namespace std;

int main(void)
{
    for(int a = 0; a <= 9 ;++a)
        for(int b = 0; b <= 9;++b)
            for(int c = 0; c <= 9; ++c)
                for(int d = 0; d<=9;++d)
                    for(int e = 0; e<=9;++e)
                        for(int f = 0;f<=9;++f)
                            for(int g = 0;g<=9;++g)
                                for(int h = 0; h<=9;++h)
                                    if((d+10*c+100*b+1000*a) + (b+10*g+100*f+1000*e) == (h+10*b+100*c+1000*f+10000*e))
                                        {
                                            // cout<<(d+10*c+100*b+1000*a)<<" "<<(b+10*g+100*f+1000*e)<<" "<<(h+10*b+100*c+1000*f+10000*e)<<endl;
                                            if(a != b && a != c && a !=d && a !=e && a !=f && a!=g && a!= h &&
                                               b != c && b != d && b !=e && b !=f && b !=g && b!=h &&
                                               c != d && c != e && c !=f && c !=g && c !=h &&
                                               d != e && d != f && d !=g && d !=h && 
                                               e != f && e != g && e !=h &&
                                               f != g && f != h && 
                                               g != h )
                                                cout<<(d+10*c+100*b+1000*a)<<" "<<(b+10*g+100*f+1000*e)<<" "<<(h+10*b+100*c+1000*f+10000*e)<<endl;                                            
                                                // cout<<b+10*g+100*f+1000*e<<endl;
                                        }

}
//9567 1085 10652
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int a[10];
    for(int i = 0; i <= 9; i++)
    {
            a[i] = i;
    }
    do
    {
        if(!a[2] || !a[6])
                continue;
        int x = a[2] * 1000 + a[3] * 100 + a[4] * 10 + a[5];
        int y = a[6] * 1000 + a[7] * 100 + a[8] * 10 + a[3];
        int z = a[6] * 10000 + a[7] * 1000 + a[4] * 100 + a[3] * 10 + a[9];
        if(x + y == z)
            cout <<y<<endl;    
    }while(next_permutation(a, a + 10));
    return 0;

}