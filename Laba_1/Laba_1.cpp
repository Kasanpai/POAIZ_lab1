// Laba_1.cpp 
// part_4

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <malloc.h>


int main()
{
    int* a; 
    int i, j, n, m;
    int sum=0 ;
 
    printf("Input row: ");
    scanf("%d", &n);
    printf("Input column: ");
    scanf("%d", &m);


    a = (int*)malloc(n * m * sizeof(int));

    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < m; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", (a + i * m + j));
        }
    }
   

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
        {
            sum = sum + *(a + i * m + j);
        }
        printf("Sum in the row num %d = %d\n", i+1, sum);
        sum = 0;
    }


    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%4d ", *(a + i * m + j));

            
        }
        printf("\n");
    }
        free(a);
        getchar();
	return 0;
}
