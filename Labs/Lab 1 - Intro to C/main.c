#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void changeNum(int* a) {
    *a = 10;
}

void fillCharArr(char* head) {
    for (int i = 0; i < 100; i++) {
        head[i] = 'a';
    }
}

void insertionSort(int* head, int length) {
    for (int i = 0; i < length; i++) {
        int currVal = head[i];
        int j = i - 1;
        while (j >= 0 && currVal <= head[j]) {
            head[j + 1] = head[j];
            j--;
        }
        head[j + 1] = currVal;
    }
}

void printIntArr(int* head, int length) {
    for (int i = 0; i < length; i++) {
        char* fmt = i == length - 1 ? "%d\n" : "%d, ";
        printf(fmt, head[i]);
    }
}

int getStringLength(char* head) {
    int count = 0;
    int i = 0;
    while (head[i] != '\0') {
        i++;
    }
    return i;
}

void seqReplace(int* arr1, unsigned long arr1Sz, int* arr2, unsigned long arr2Sz) {
    if (arr2Sz > arr1Sz) {
        return;
    }
    for (int i = 0; i < arr1Sz - arr2Sz + 1; i++) {
        if (arr1[i] == arr2[0]) {
            bool isContained = true;
            int j = i;
            while (j - i + 1 <= arr2Sz) {
                if (arr1[j] != arr2[j - i]) {
                    isContained = false;
                    break;
                }
                j++;
            }
            if (isContained) {
                for (int j = i; j < i + arr2Sz; j++) {
                    arr1[j] = 0;
                }
            }
        }
    }
}

int main() {
    int num = 5;
    changeNum(&num);
    printf("%d\n", num);

    char arr[100];
    fillCharArr(arr);

    int intArr[4] = {84, 43, 21, 62};
    insertionSort(intArr, 4);
    printIntArr(intArr, 4);

    char* str = "hello world!!!";
    printf("%d\n", getStringLength(str)); // O(n)

    int a[6] = {5, 6, 7, 8, 6, 7};
    int b[2] = {6, 7};
    seqReplace(a, 6, b, 2);
    printIntArr(a, 6);

    return 0;
}