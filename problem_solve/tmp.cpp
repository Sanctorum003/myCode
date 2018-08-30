#include <stdio.h>

int main(void)
{
    int i = 0;
    switch(i)
    {
        case 1:
            break;
        case 2:
        case 3:
            break;
        case 5:
            i = 0xff;
        default:
            break;
    }
    return 0;
}