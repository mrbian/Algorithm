//
// Created by BMAN on 2018/3/5.
//

#include <limits.h>
#include <stdlib.h>
#include "merge_sort.h"

void merge(int *arr, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int* L1 = malloc(sizeof(int) * (n1 + 1));       // 加入哨兵元素，所以长度+1
    int* L2 = malloc(sizeof(int) * (n2 + 1));
    L1[n1] = INT_MAX; L2[n2] = INT_MAX;             // 哨兵
    int i,j,k;
    for(i=0;i<n1;i++)                               // 左右子数组复制
        L1[i] = arr[p + i];
    for(j=0;j<n2;j++)
        L2[j] = arr[q + j + 1];

    i = 0; j = 0;                                   // 归并到原来的数组
    for(k=p;k<=r;k++){
        if(L1[i] > L2[j]){
            arr[k] = L2[j];
            j++;
        }else{
            arr[k] = L1[i];
            i++;
        }
    }
}

void merge_sort(int * arr, int p, int r){
    if(p < r){                                      // 基本项不做操作
        int q = (p + r) / 2;                        // 向下取整更方便
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, p);
        merge(arr, p, q, r);
    }
}

void merge_sort_test(){
    int arr[] = {7,5,2,4,7,1,3,6};
    printf("Merge_sort, the origin array is:");
    print_arr(arr,arr[0]);
    printf("\n");

    merge_sort(arr,1,arr[0]);

    printf("After merge_sort, the array is:");
    print_arr(arr,arr[0]);
}