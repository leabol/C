#include <stdio.h>
#include <stdlib.h>

int CompareIntArray2(const void *a, const void *b)
{
    return *(*(int **)a) - *(*(int **)b);
}

// Test 2D Array
int main(void)
{
    int a[5][3] = {{5,4,-1},{3,2,3},{7,3,-2},{-1,1,1},{4,0,1}};

    int row = 5;
    int col = 3;

    // 申请指向行首指针的二级指针空间
    int **arr2 = (int **)malloc(row * sizeof(int**));
    int i, j;
    for (i = 0; i < row; i++) { 
        // 得到行首指针，注意相邻行的内存空间不一定连续
        // 但同一行内部元素的内存空间是连续的
        arr2[i] = (int*)malloc(col * sizeof(int));
    }

    // 录入数据
    for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
            arr2[i][j] = a[i][j];  // 快速录入预设数据
            // int ret = scanf("%d", &arr2[i][j]);
            // if (ret != 1) { return -1; }
        }
    }
   // int b[3] = {0,0,0};
   // arr2[2] = (int *)&b[0];  // 替换第3行数据

    // 打印输入的数组
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }
 printf("\n\n");
 
 // 常见错误调用，操作后打印时会报错
    // qsort(arr2, 5, 3 * sizeof(int), CompareIntArray); 
    // 正确调用，注意元素大小和compare函数
    qsort(arr2, row, sizeof(int*), CompareIntArray2); 

    // 打印排序后的数组
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }

    // 释放对应内存
    for (i = 0; i < row; i++) {
     // 当有 arr2[2] = (int *)&b[0]
     // 注意不能释放arr2[2], 因为是从栈中申请的，不是在堆里动态申请来的内存
        free(arr2[i]);  
    }
    free(arr2);
   
    return 0;
}