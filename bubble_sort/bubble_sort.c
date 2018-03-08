//
// Created by BMAN on 2018/3/7.
//

#include "bubble_sort.h"
#include "../common/common.h"

void bubble_sort(int* arr, int n){
    int i,j,temp;
    for(i=1;i<n;i++){                   // i=1 to n-1，n-1个位置，最后一个不需要排
        for(j=n;j>i;j--){               // i到n全遍历，找出最小的进行冒泡，j=n downto i+1
            if(arr[j] < arr[j-1]){
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

void bubble_sort_test(){
    int arr[] = {6,5,2,6,1,4,3};
    print_func_test(arr,arr[0],bubble_sort);
}