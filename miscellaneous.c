#include <stdio.h>

void cStrings() {
    char* s = "abc";
    // s is the address where'a' is
    // s + 1 is the address where 'b' is
    // s + 2 is the address where 'c' is
    // s + 3 is the address where '/0' (null terminator) is

    printf("The NULL is %c", s[3]); // this prints NULL
}

void printAddress() {
    int hello = 5;
    int* ptr = &hello;
    printf("%p", ptr);
}

int main() {
    cStrings();
    printAddress();
    return 0;
}