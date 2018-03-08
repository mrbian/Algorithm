//
// Created by BMAN on 2018/3/6.
//

#include <stdlib.h>
#include <limits.h>
#include "../../common/common.h"
#include "solution.h"

// 归并排序（哨兵版）
void _merge(int* arr, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int* L1 = malloc(sizeof(int) * (n1 + 1));
    int* L2 = malloc(sizeof(int) * (n2 + 1));
    L1[n1] = INT_MAX; L2[n2] = INT_MAX;
    int i,j,k;
    for(i=0;i<n1;i++)
        L1[i] = arr[p + i];
    for(i=0;i<n2;i++)
        L2[i] = arr[q + i + 1];

    i = 0; j = 0; k = p;
    while(k<=r){
        if(L1[i] > L2[j])
            arr[k++] = L2[j++];
        else
            arr[k++] = L1[i++];
    }
}

void _mergeSort(int* arr, int p, int r){
    if(p < r){
        int q = (p + r) / 2;
        _mergeSort(arr,p,q);
        _mergeSort(arr,q+1,r);
        _merge(arr,p,q,r);
    }
}

void problem1_solution(){
    int arr[] = {6,5,2,3,10,1,6};
    _mergeSort(arr,1,arr[0]);
    print_arr(arr,arr[0]);
    printf("\n");

    int index1 = 1;
    int index2 = arr[0];
    int x = 17;
    while(index1 < index2){
        if(arr[index1] + arr[index2] == x){
            printf("This set has the sum number %d, and the index are %d and %d\n", x, index1, index2);
            return;
        }else if(arr[index1] + arr[index2] < x){
            index1 ++;
        }else{
            index2 --;
        }
    }
    printf("This set has no the sum number %d\n", x);
}