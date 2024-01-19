/*
    动态申请数组,并按第一升序,第二列降序
*/

#include <stdio.h>
#include <stdlib.h>

int cmpfun1(const void* a,const void* b)
{
    int ret = **(int**)a - **(int**)b;
    if (ret == 0)
        return *(*(int**)b+1) - *(*(int**)a+1);
    return ret;
}

int main(void)
{
    int row, col;

    scanf("%d %d", &row, &col);
    int** arr = (int**)malloc(sizeof(int*)*row);

    for (int i = 0; i < row; i++)
    {
        int *p = (int*)malloc(sizeof(int)*col);
        arr[i] = p;
    }

    //input data
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    qsort(arr, row, sizeof(int*), cmpfun1);

    printf("\noutput:\n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }


    for (int i = 0; i < row; i++)
    {
        free(arr[i]);
    }
    free(arr);
}