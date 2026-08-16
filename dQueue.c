#include<stdio.h>
#define MAX 100

void insertFront(int LA[], int *N, int ele) {
    if(*N >= MAX) {
        printf("Overflow \n");
        return;
    }
    for(int i=*N; i>0; i++) {
        LA[i] = LA[i-1];
    }
    LA[0] = ele;
    *N = *N + 1;
    printf("Element inserted ! ");
}

void insertRear(int LA[], int *N, int ele) {
    if(*N >= MAX) {
        printf("Overflow \n");
        return;
    }
    LA[*N] = ele;
    *N = *N + 1;
    printf("Element inserted ! ");
}

void deleteFront(int LA[], int *N) {
    if(*N == 0) {
        printf("Underflow \n");
        return;
    }
    int removed = LA[0];
    for(int i=0; i<*N-1; i++) {
        LA[i] = LA[i+1];
    }
    *N = *N - 1;
    printf("Element deleted");
}

void deleteRear(int LA[], int *N) {
    if(*N == 0) {
        printf("Overflow \n");
        return;
    }
    int removed = LA[*N - 1];
    *N = *N - 1;
    printf("Element deleted");
}