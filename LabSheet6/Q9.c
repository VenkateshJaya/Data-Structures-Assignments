#include<stdio.h>

long long int maxAs(int n)
{
    if(n <= 6)
    {
        return n;
    }
    
    long long int max = 0;
    for(int i = n-3;i>=1;i--)
    {
        long long int curr = (n-1-i)*maxAs(i);
        max = (max>curr)?max:curr;
    }
    return max;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lld\n", maxAs(n));
    return 0;
}