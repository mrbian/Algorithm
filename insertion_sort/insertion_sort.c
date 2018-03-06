//
// Created by BMAN on 2018/1/19.
//
#include "insertion_sort.h"

/*
 * 下标j指出正被插入的元素，A[1...j-1]为已排序好的序列
 * 插入排序可以用数学归纳法进行非形式化的证明（P10）
 * 循环不变式：初始化、保持、终止
 */
void insertion_sort(int * arr, int n){
    if(n <= 0) return;

    int i,j,key;
    for(j=2;j<=n;j++){                      // 排序从第二个元素开始
        key = arr[j];
        i = j - 1;
        while(i > 0 && arr[i] > key){       // 将比key元素大的元素移动到靠后位置，找到元素应当被插入的位置
                                            // 最差情况下每次循环这句话执行j次，最好情况下执行1次
            arr[i + 1] = arr[i];
            -- i;
        }
        arr[i + 1] = key;                   // 注意前面多减了一次，应该是i + 1
    }
}

// 利用二分法的插入排序，时间复杂度为O(nlgn)
void insertion_sort_binary_search(int* arr, int n){
    int i,j,k,key;
    int low,high,mid;
    for(j=2;j<=n;j++){
        key = arr[j];
        low = 1; high = j - 1;
        while(low <= high){                             // 结束后low的位置就是应当插入的位置
            mid = (low + high) / 2;
            if(arr[mid] >= key) high = mid - 1;
            else low = mid + 1;
        }
        i = low; k = j - 1;
        while(i < j){                                   // low位置到j位置的元素依次后移一位
            arr[k + 1] = arr[k];
            k--; i++;
        }
        arr[low] = key;
    }
}

void insertion_sort_test(){
    int arr[] = {6,5,2,4,6,1,3};            // 首项为数组长度
//    print_func_test(arr,arr[0],insertion_sort);
    print_func_test(arr,arr[0],insertion_sort_binary_search);
}
