#include <stdio.h>
#include <math.h>
#define MAX 1000000

int map[MAX+1];

int main()
{
    int numCases = 0; 
    int i=0,n=0;
    int sqrt_max = sqrt(MAX);
    for (int i=0; i <= MAX; i++)    map[i] = i;
    
    for (int i=1; i < MAX; i++) {
        int score = map[i] + 1;
        int limit;
        if (map[i+1] > score)
            map[i+1] = score;
        if (i > sqrt_max)
            limit = MAX;
        else
            limit = i*i;
        for (int j = i+i; j <= limit; j += i) {
            if (map[j] > score)
                map[j] = score;
        }
    }
    if (scanf("%d", &numCases) != 1)
        return 1;
    while (numCases-- > 0) {
        scanf("%d", &n);
        printf("for %d : %d\n", n,map[n]);
    }
    return 0;
}