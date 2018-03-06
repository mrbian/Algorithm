//
// Created by BMAN on 2018/3/6.
//

#include "search_bin.h"

int BinarySearchWithRecursion(int* arr, int key, int low, int high){
    if(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] > key) return BinarySearchWithRecursion(arr,key,low,mid-1);
        else return BinarySearchWithRecursion(arr,key,mid+1,high);
    }
    return -1;
}


int BinarySearch(int* arr, int key, int n){
    int mid;
    int low = 1, high = n - 1;
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid] == key){
            return mid;
        }else if(arr[mid] > key){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}

void BinarySearchTest(){
    int arr[] = {6,1,2,3,4,5,6};
    int key = 3;
    int idx = BinarySearch(arr,key,arr[0]);
    printf("After search without recursion, the idx of number %d in the array is %d\n", key, idx);
    idx = BinarySearchWithRecursion(arr,3,1,arr[0]);
    printf("After search with recursion, the idx of number %d in the array is %d",key, idx);
}