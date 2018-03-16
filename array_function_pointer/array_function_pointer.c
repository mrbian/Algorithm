//
// Created by BMAN on 2018/3/16.
//
#include "array_function_pointer.h"
/*
 * 1、声明一个指向整形的指针p
 * 2、声明一个返回整形指针的函数f
 * 3、声明一个指向返回整形值的函数的函数指针ff
 * 4、声明一个指向返回整形指针的函数的函数指针fff
 * 5、声明一个指针数组
 * 6、声明一个数组指针
 * 7、变态的：int (*f7[])() ，那么f7的含义？
 * 8、最后一个：int *(*f8[])()，那么f8的含义？
 */

int* f(){                   // 2
    int *p;
    return p;
}

int a1[2];       // a1是指向第一个整型数的指针
int a2[2][2];    // a2是指向第一个数组的指针

void pointer_test(){
    int* p;                 // 1
    int (*ff)();       // 3
    int* (*fff)() = f; // 4
    int* p1[2];          // 5 指针数组，用括号不不用括号这里就有区别
    int (*p2)[2];        // 6 指向数组的指针，也就是指向 指向数组第一个元素指针 的指针
    p1[0] = a1;
    p2 = &a1;
    p2 = a2;
}

// 32位一个指针占用4个字节，指针的指针占用8字节
void pointer_diff_test(){
    int** a1;
    printf("a1 %d \n", a1);
    printf("a1+1 %d \n", a1 + 1);
    printf("int(*)a1+1 %d \n", (int*)a1 + 1);
    printf("*a1 %d \n", *a1);
    printf("*a1+1 %d \n", *a1 + 1);

    int a2[][2] = {1,2,3,4};
    printf("a2 %d \n", a2);
    printf("a2+1 %d \n", a2 + 1);
    printf("(int*)a2+1 %d \n", (int*)a2 + 1);

    int a3[] = {1,2,3};
    printf("a3 %d \n", a3);
    printf("a3+1 %d \n", a3 + 1);
}