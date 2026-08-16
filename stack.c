#include<stdio.h>
#define MAX 100

void push(int LA[], int *N, int ele) {
    if(*N >= MAX) {
        printf("Stack Overflow \n");
    }
    LA[*N] = ele;
    *N = *N + 1;
    printf("Element Inserted");
}

void pop(int LA[], int *N) {
    if(*N == 0) {
        printf("Stack Underflow");
    }
    *N = *N - 1;
    printf("Element Deleted");
}

void peek(int LA[], int N) {
    if(N == 0) {
        printf("Stack Empty");
    }
    for(int i=0; i<N; i++) {
        printf("%d",LA[i]);
    }
    printf("\n");
}