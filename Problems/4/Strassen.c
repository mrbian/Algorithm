//
// Created by BMAN on 2018/3/14.
//

#include <stdlib.h>
#include "Strassen.h"

// O(n3)的非递归算法，普通的矩阵乘法
// 将矩阵用一维数组存储还是二维数组存储？
int** problem4_solution1(int** A, int m, int n, int** B, int s, int t){
    if(n == s){
        int i,j,k;
        int** C = malloc(sizeof(int*) * m);
        for(i=0;i<m;i++){
            C[i] = malloc(sizeof(int) * t);
        }

        for(i=0;i<m;i++){
            for(j=0;j<t;j++){
                C[i][j] = 0;
                for(k=0;k<n;k++){
                    C[i][j] = C[i][j] + *((int*)A + i * n + k) * *((int *)B + k * t + j);      // 一定要这样寻址，否则编译器不知道怎么分行，但是数组C就不能用这种方法！
                }
            }
        }

        return C;

    }else{
        printf("the matrix A and B can not multiply!");
    }
}


// Strassen算法，递归的矩阵乘法，适合n*n型且n为2的幂的矩阵乘法
int** Strassen(int** A, int ** B, int a_rs, int a_cs, int b_rs, int b_cs, int n, int origin_n){
    int** C = malloc((sizeof(int*) * n));
    int i,j;
    for(i=0;i<n;i++){
        C[i] = malloc(sizeof(int) * n);
    }

    int** m1_temp; int** m2_temp;
    if(n == 1){
        C[0][0] = (*((int*)A + a_rs * origin_n + a_cs)) * (*((int*)B + b_rs * origin_n + b_cs));
    }else{
        n /= 2;

        // C11 = Strassen(A11,B11) + Strassen(A12,B21)
        m1_temp = Strassen(A, B, a_rs, a_cs, b_rs, b_cs, n,origin_n);
        m2_temp = Strassen(A, B, a_rs, a_cs+n, b_rs+n, b_cs,n,origin_n);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                C[i][j] = m1_temp[i][j] + m2_temp[i][j];
            }
        }

        // C12 = Strassen(A11,B12) + Strassen(A12,B22)
        m1_temp = Strassen(A, B, a_rs, a_cs, b_rs, b_cs+n, n,origin_n);
        m2_temp = Strassen(A, B, a_rs, a_cs+n, b_rs+n, b_cs+n,n,origin_n);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                C[i][j+n] = m1_temp[i][j] + m2_temp[i][j];
            }
        }

        // C21 = Strassen(A21,B11) + Strassen(A22,B21)
        m1_temp = Strassen(A, B, a_rs+n, a_cs, b_rs, b_cs, n,origin_n);
        m2_temp = Strassen(A, B, a_rs+n, a_cs+n, b_rs+n, b_cs,n,origin_n);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                C[i+n][j] = m1_temp[i][j] + m2_temp[i][j];
            }
        }

        // C22 = Strassen(A21,B12) + Strassen(A22,B22)
        m1_temp = Strassen(A, B, a_rs+n, a_cs, b_rs, b_cs+n, n,origin_n);
        m2_temp = Strassen(A, B, a_rs+n, a_cs+n, b_rs+n, b_cs+n,n,origin_n);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                C[i+n][j+n] = m1_temp[i][j] + m2_temp[i][j];
            }
        }
    }

    return C;
}


void problem4_solution_test(){
    int A[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int B[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int** C = problem4_solution1((int**)A,4,4,(int**)B,4,4);
//    int** C = Strassen((int**)A,(int**)B,0,0,0,0,4,4);
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%d ", *(*C + i*4 + j));             // 知道分行寻址了？*(*C + i*4 + j)和*((int*)C + i*4 + j)有什么区别呢？
        }
    }
}