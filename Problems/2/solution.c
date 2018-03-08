//
// Created by BMAN on 2018/3/7.
//

#include <stdlib.h>
#include <limits.h>
#include "solution.h"

int _mergeAndCount(int* arr, int p, int q, int r){
    int count = 0;
    int n1 = q - p + 1;
    int n2 = r - q;
    int* L1 = malloc(sizeof(int) * n1);
    int* L2 = malloc(sizeof(int) * n2);
    int i,j,k;
    for(i=0;i<n1;i++)
        L1[i] = arr[p + i];
    for(j=0;j<n2;j++)
        L2[j] = arr[q + 1 + j];

    k = p; i = 0; j = 0;
    while(k<=r && i<n1 && j<n2){                    // 不能够使用哨兵，哨兵会让结果出现错误
        if(L1[i] > L2[j]){
            count ++;
            arr[k++] = L2[j++];
        }else{
            arr[k++] = L1[i++];
        }
    }
    while(i<n1){
        arr[k++] = L1[i++];
        count ++;
    }
    while(j<n2){
        arr[k++] = L2[j++];
    }
    return count;
}

int _mergeSortAndCount(int* arr, int p, int r){
    // need copy arr
    if(p < r){
        int q = (p + r) / 2;
        int count = 0;
        count += _mergeSortAndCount(arr,p,q);
        count += _mergeSortAndCount(arr,q+1,r);
        count += _mergeAndCount(arr,p,q,r);
        return count;
    }else
        return 0;                                   // 这句话非常重要，如果没有返回值，默认返回32766
}

void problem2_solution(){
    int arr[] = {5,2,3,8,6,1};
    printf("the count of this array is %d",_mergeSortAndCount(arr,1,arr[0]));
}