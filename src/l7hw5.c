#include <stdio.h>
#include <stdlib.h>
#include "print_1d_array.h"
#include "swap.h"

void sortInserts(int* arr, int len) {
    int temp, pos;
    for (int i = 1; i < len; ++i) {
        temp = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] > temp) {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}


//Описать в коде улучшенный алгоритм быстрой сортировки
void qsEnhanced(int* arr, int first, int last) {

    if (last+1 <= 10) {
        sortInserts(arr, last+1);
        return;
    }
    int middle=(first + last) / 2;
   
   // ставим наиболее близкий к медиане элемент в середину (считая из первого,среднего и последнего) 
    if (arr[last]<arr[middle] && arr[last]>arr[first])
        swap(&arr[last],&arr[middle]);
    else if (arr[last]>arr[middle] && arr[middle]<arr[first])
        swap(&arr[first],&arr[middle]);
    else if (arr[last]<arr[middle] && arr[last]<arr[first]) {
        if (arr[first]>arr[middle]){
            swap(&arr[last],&arr[middle]);
            swap(&arr[last],&arr[first]);
    }
    else {
            swap(&arr[last],&arr[first]);
    }
    }
    else if (arr[last]==arr[middle] && arr[middle]<arr[first])
            swap(&arr[last],&arr[first]);
/*    
    else if (arr[last]==arr[middle] && arr[last]>=arr[first])
        // ничего не делаем - нужный элемент уже в центре
    else if (arr[last]>arr[middle] && arr[middle]>arr[first])
            // ничего не делаем  - нужный элемент уже в центре
    else if (arr[last]>arr[middle] && arr[middle]==arr[first])
            // ничего не делаем - нужный элемент уже в центре
*/

    int i = first;
    int j = last;

    int x = arr[middle];

    do {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;

        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last) qsEnhanced(arr, i, last);
    if (first < j) qsEnhanced(arr, first, j);
}

// Сортировать в массиве целых положительных чисел только чётные числа, нечётные оставив на своих местах
// при помощи алгоритма блочной сортировки,
// то есть массив вида [0 2 8 3 4 6 5 9 8 2 7 3] превратить в [0 2 2 3 4 6 5 9 8 8 7 3]
void bucketSortEven(int* arr, int len) {
    int i;
    const int max = len;
    const int b = 10;

    int evenOnly[max];
    for(i=0;i<max;++i) {
         evenOnly[i]=-1;
    }

    int evenindex=0;
    for(i=0;i<max;++i) {
        if(arr[i]%2==0) { // even
            evenOnly[evenindex]=arr[i];
            evenindex++;
        }
    }

    int buckets[b][max+1];
    for (int i = 0; i < b; ++i) {
        buckets[i][max] = 0;
    }

    for (int digit = 1; digit < 1000000000; digit*=10) {
        for (int i = 0; i < max; ++i) {
            int d = abs( (evenOnly[i] / digit) % b);
            int counter = buckets[d][max];
            buckets[d][counter] = evenOnly[i];
            counter++;
            buckets[d][max] = counter;
            //buckets[d][buckets[d][max]++] = arr[i];
        }
        int idx = 0;
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < buckets[i][max]; ++j) {
                evenOnly[idx++] = buckets[i][j];
            }
            buckets[i][max] = 0;
        }
    }
    
    evenindex=0;
    for(i=0;i<max;++i) {
       if( arr[i]%2 > 0) // odd
         continue;
       else {
         if(evenOnly[evenindex] > 0) {
             arr[i]=evenOnly[evenindex];
             evenindex++;
         }
         else {
            while(evenindex<max && evenOnly[evenindex]<0)
                evenindex++;
            arr[i]=evenOnly[evenindex];
            evenindex++;
         }
         
       }  
    }

}

int tosort[12]={9,7,5,4,3,1,1,3,5,6,1,6};
int tosortevenonly[12]={0,2,8,3,4,6,5,9,8,2,7,3};

int main(int argc, char ** argv) {
    
    printf("До сортировки:\n");
    print_1d_array(12,tosort);
    qsEnhanced(tosort,0,11);
    printf("После сортировки:\n");
    print_1d_array(12,tosort);

    printf("Сортировка только чётных:\n");
    printf("До сортировки:\n");
    print_1d_array(12,tosortevenonly);
    bucketSortEven(tosortevenonly,12);
    printf("После сортировки:\n");
    print_1d_array(12,tosortevenonly);

    return 0;
}
