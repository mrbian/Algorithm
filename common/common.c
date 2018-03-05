//
// Created by BMAN on 2018/3/4.
//

#include "common.h"

void print_arr(int *arr, int n){
    int i;
    for(i=1;i<=n;i++) printf("%d ",arr[i]);
}


void print_func_test(int *arr, int n, void(*pfun)(int *, int)){
    printf("The origin array is ");
    print_arr(arr,6);
    printf("\n");

    pfun(arr,6);

    printf("Now the array is ");
    print_arr(arr,6);
    printf("\n");
}
