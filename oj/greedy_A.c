#include <stdio.h>

int main(void)
{
    int n[9] =  {1,4,7,2,5,8,3,6,9}, F[9] ={0};

    for (int i = 0; i < 9; i++)
    {
        int max = 0;
        for (int j = 0; j <= i; j++)
        {
            if (n[i] >= n[j] && max < F[i])
                {
                    F[i] = max+1;
                    max = F[i];
                    continue;
                }
            
            F[i]++;
        }
    }


    for (int i = 0; i < 9; i++)
    {
        printf("%d ", F[i]);
    }
int M = 0, k = 0;
    for (int i = 0; i < 9; i++)
    {
        if (F[i] > M)
           {
            M = F[i];
            k = i;
           }
    }

    printf("\n%d", F[k]);

}