//
// Created by BMAN on 2018/3/5.
//

#include <limits.h>
#include <stdlib.h>
#include "merge_sort.h"

void merge(int* arr, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int* L = malloc(sizeof(int) * (n1 + 1));        // 加入哨兵元素，所以长度+1
    int* R = malloc(sizeof(int) * (n2 + 1));
    L[n1] = INT_MAX; R[n2] = INT_MAX;               // 哨兵
    int i,j,k;
    for(i=0;i<n1;i++)                               // 左右子数组复制
        L[i] = arr[p + i];
    for(j=0;j<n2;j++)
        R[j] = arr[q + j + 1];                      // 注意右侧没有q位置的元素

    i = 0; j = 0;                                   // 归并到原来的数组
    for(k=p;k<=r;k++){
        if(L[i] > R[j]){
            arr[k] = R[j];
            j++;
        }else{
            arr[k] = L[i];
            i++;
        }
    }
}

// 不使用哨兵的归并函数
void mergeWithoutGuard(int* arr, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int* L = malloc(sizeof(int) * n1);
    int* R = malloc(sizeof(int) * n2);
    int i,j,k;
    for(i=0;i<n1;i++)
        L[i] = arr[p + i];
    for(j=0;j<n2;j++)
        R[j] = arr[q + j + 1];

    i = 0; j = 0;
    for(k=p;k<=r;k++){
        if(i >= n1 || j >= n2) break;               // 越界时退出

        if(L[i] > R[j]){
            arr[k] = R[j];
            j++;
        }else{
            arr[k] = L[i];
            i++;
        }
    }
    while(i < n1) arr[k++] = L[i++];              // k和i均已移动到正确位置
    while(j < n2) arr[k++] = R[j++];
}

void merge_sort(int * arr, int p, int r){
    if(p < r){                                      // 基本项不做操作
        int q = (p + r) / 2;                        // 向下取整更方便
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, p);
        mergeWithoutGuard(arr, p, q, r);
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