//
// Created by BMAN on 2018/3/8.
//

#include <stdlib.h>
#include <limits.h>
#include "find-max-subarray.h"

int* getDiffArray(int* arr, int n){
    int i;
    int* A = malloc(sizeof(int) * n);
    A[0] = n - 1;
    for(i=1;i<n;i++){
        A[i] = arr[i+1] - arr[i];
    }
    return A;
}

// 暴力破解，返回最大子数组的边界和最大子数组的和，此方法的时间复杂度为O(n方)
int* problem3_solution1(int* A, int n){
    int i,j;
    int low = 1; int high = 1;
    int sum = 0; int max = INT_MIN;
    for(i=1;i<n;i++){
        sum = A[i];
        for(j=i+1;j<=n;j++){
            sum += A[j];
            if(sum > max){
                low = i;
                high = j;
                max = sum;
            }
        }
    }

    int* result = malloc(sizeof(int) * 4);
    result[0] = 3;
    result[1] = low; result[2] = high; result[3] = max;
    return result;
}

// 只需找出形如A[i...mid]和A[mid+1..j]的最大子数组，然后将其合并即可
int* find_max_cross_subarray(int* A, int n, int low, int mid, int high){
    int left_sum = INT_MIN;
    int sum = 0; int i;
    int left_low = mid;
    for(i=mid;i>=low;i--){
        sum += A[i];
        if(sum > left_sum){
            left_low = i;
            left_sum = sum;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    int right_high = mid + 1;
    for(i=mid+1;i<=high;i++){
        sum += A[i];
        if(sum > right_sum){
            right_high = i;
            right_sum = sum;
        }
    }

    int* result = malloc(sizeof(int) * 4);
    result[0] = 3;
    result[1] = left_low;
    result[2] = right_high;
    result[3] = left_sum + right_sum;
    return result;
}

// 利用分治法思想的解法，时间复杂度为O(nlgn)
int* find_max_subarray(int* A, int n, int low, int high){
    int* result = malloc(sizeof(int) * 4); result[0] = 3;
    if(low == high){                                        // 基本项
        result[1] = low;
        result[2] = high;
        result[3] = A[low];
        return result;
    }

    int mid = (low + high) / 2;

    int left_sum; int right_sum; int cross_sum;

    int* left_result = find_max_subarray(A,A[0],low,mid);
    left_sum = left_result[3];

    int* right_result = find_max_subarray(A,A[0],mid+1,high);
    right_sum = right_result[3];

    int* cross_result = find_max_cross_subarray(A,A[0],low,mid,high);
    cross_sum = cross_result[3];

    if(left_sum >= right_sum && left_sum >= cross_sum)
        return left_result;
    else if(right_sum >= left_sum && right_sum >= cross_sum)
        return right_result;
    else
        return cross_result;

}


void problem3_solution_test(){
    int arr[] = {17,100,113,110,85,105,102,86,63,81,101,94,106,101,79,94,90,97};
    int* A = getDiffArray(arr,arr[0]);
//    print_arr(A,A[0]);
//    int * result = problem3_solution1(A,A[0]);
    int* result = find_max_subarray(A,A[0],1,A[0]);
    print_arr(result,result[0]);
}