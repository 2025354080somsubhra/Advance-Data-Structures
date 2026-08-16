#include<stdio.h>
#define MAX 100

void enqueue(int LA[], int *N, int ele) {
    if(*N >= MAX) {
        printf("Stack Overflow");
    }
    LA[*N] = ele;
    *N = *N + 1;
    printf("Element entered");
}

void dequeue(int LA[], int *N) {
    if(*N == 0) {
        printf("Stack Underflow");
    }
    int removed = LA[0];
    for(int i=0; i<*N-1; i++) {
        LA[i] = LA[i+1];
    }
    *N = *N - 1;
    printf("Element is deleted !");
}