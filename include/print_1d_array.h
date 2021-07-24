#ifndef PRINT_1D_ARRAY
#define PRINT_1D_ARRAY

#include <stdio.h>

void print_1d_array(int size, int *array)
{
    for(int i=0;i<size;i++)
        printf("%d%s",*(array+i),i==size-1?"\n":",");
}

#endif
