#include <stdio.h>

int main(void)
{
    int n, time = 0;
    while (scanf("%d", &n), n != 0)
    {
        int pre = 0, next = 0;
        time = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &next);
            if (next - pre > 0)
                {
                    time += (next-pre)*6 + 5;
                    pre = next;
                }
            else
                {
                    time += (pre - next)*4 + 5; 
                    pre = next;
                }
        }
        printf("%d\n", time);
    }
}