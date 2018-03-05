//
// Created by BMAN on 2018/3/5.
//

#include "select_sort.h"

void select_sort(int *arr, int n){
    int i,j,idx,temp;
    for(i=1;i<=n;i++){
        idx = i; j = i;
        while(j <= n){                          // SelectMinKey，找到最小数的下标
            idx = arr[j] > arr[idx] ? idx : j;
            j ++;
        }
        if(idx != i){                           // 交换当前数和最小数
            temp = arr[idx];
            arr[idx] = arr[i];
            arr[i] = temp;
        }
    }
}

void select_sort_test(){
    int arr[] = {6,5,2,4,6,1,3};            // 首项为数组长度
    print_func_test(arr,arr[0],select_sort);
}