#include <stdio.h>
#include <stdlib.h>

typedef long int sz_arr_t;

void printArr(int* arr, sz_arr_t sz) {
    for (int i = 0; i < sz; i++) {
        char* fmt = i == sz - 1 ? "%d\n" : "%d, ";
        printf(fmt, arr[i]);
    }
}

typedef struct student {
    char name[200];
    char number[11]; // why 11? Because the \0
    double GPA;
} student;

int main() {
    student s1 = {"John Doe", "1234567890", 3.3};
    printf("%s %f\n", s1.name, s1.GPA);

    student* p_s1 = &s1;
    printf("%s %f\n", (*p_s1).name, (*p_s1).GPA); // dereference and get the attributes
    printf("%s %f\n", p_s1->name, p_s1->GPA); // same as above. -> dereferences automatically. It is syntatic sugar to (*ptr).attr

    return 0;
}
