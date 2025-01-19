#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cStrings() {
    char* s = "abc";
    // s is the address where'a' is
    // s + 1 is the address where 'b' is
    // s + 2 is the address where 'c' is
    // s + 3 is the address where '/0' (null terminator) is

    // this really is an array of 'a', 'b', 'c', '\0'

    printf("The NULL is %c\n", s[3]); // this prints NULL
}

void printAddress() {
    int hello = 5;
    int* ptr = &hello;
    printf("%p\n", ptr);
}

void arrayOfStrings() {
    char** arr = (char**) malloc(10 * sizeof(char*));
    for (int i = 0; i < 10; i++) {
        arr[i] = NULL;
    }
    char* str = "hello";
    arr[0] = (char*) malloc((strlen(str) + 1) * sizeof(char));
    strcpy(arr[0], str);

    for (int i = 0; i < 10; i++) {
        char* fmt = (i < 9) ? "%s, " : "%s\n";
        printf(fmt, arr[i]);
    }

    for (int i = 0; i < 10; i++) {
        free(arr[i]);
    }
    free(arr);
}

void arrays() {
    int arr[] = {5, 10, 2};
    arr[0] = 3;

    // note that defererncing the arr will give the first element
    // the pointer points to the first element!
    printf("%d\n", *arr);

    int arr2[10]; // an int array of size 10

    // not ethat {} is ONLY for initialization!!!! Cannot do assignment with it
}

void pointers() {
    int a = 42;
    int* p_a = &a;
    char* s = "abc"; // array of char
    *p_a = 43; // dereference p_a and put 43 into the value that p_a points to (which is a)
    printf("%d\n", a);
}

// we can manipulate a value outside a function from inside a function like this
void f(int* num) {
    *num = 10086;
}

// suppose we have:
void g(int num) {
    // do stuff
}
// calling g(43) will copy 43 to the local variable num. It's a COPY!!

void pointerToFunction() {
    int a = 52;

    f(&a);
    printf("%d\n", a);
}
// ^

void pointerArithmetic() {
    char* s = "programming in C until I go insane";
    printf("%c\n", *(s + 1)); // prints 'r'

    printf("%p\n", s + 2); // prints the address of 'o'
    printf("%c\n", *(s + 2)); // prints the value at s + 2, which is 'o'

    char* movePtr = s + 4; // prints the string 'ramming in C until I go insane'
    printf("%s\n", movePtr);

    int arr[] = {3, 4};
    // suppose that 3 is at address 2064
    
    printf("%p\n", arr + 1); // prints 2068 since int takes 4 bytes

    printf("%ld\n", arr); // %ld prints the address in decimals 
    printf("%ld\n", arr + 1);

    // something like arr[5] is really *(arr + 5);
}

void change_arr0(int* p_a) {
    *p_a = 43;
}

void constChar() {
    // char* s1 = "abc"; // warning; implicit conversion to char*
    //                     // not allowed to modify the contents of a const char*
    //                     // go to address s and modify the contents there
    // s1[0] = 'x'; // will compile, but might crash at runtime

    const char* s2 = "abc"; // s2 is the address of 'a'
                            // not allowed to modify contents as s2
                            // the compiler will yell at you
    s2 = "zbc"; // allowed: not changing the contents at s2. Instead, it just changes s2 entirely

    char s1[] = "abc"; // array of characters
    s1[0] = 'z';
    printf("%s\n", s1); // works

    // char* s3 = "abc"; // implicitly converted to a constant
    // s3[0] = 'd';
    // printf("%s\n", s3); // doesn't work

    const char* const str = "hello";
    // the first const means the content is constant
    // the second const means the address is constant
}

// void moreOnStrings() {
//     // 1. works fine
//     // 2. would not compile
//     // 3. undefined behaviour: might crash at runtime

//     // remember:
//     // the first const means the content is constant
//     // the second const means the address is constant

//     const int a = 5;
//     a = 6; // 2

//     char* s = "abc";
//     s = "def"; // 1

//     const char* s1 = "abc";
//     s1 = "def"; // 1. Modifying address is ok
//     s1[0] = 'x'; // 2. Modifying value is not ok

//     const char* const s2 = "abc";
//     s2 = "def"; // 2

//     char* const s3 = "abc";
//     s3 = "def"; // 2
//     s3[0] = 'x' // 1

// }

void changeNum(int* num) {
    *num = 10086;
}

void inClassPracticeJan15() {
    int a = 42;
    int* p_a = &a;
    *p_a = 43;

    int num = 43;
    p_a = &num;

    changeNum(&a);
    printf("%d\n", a);
}

void printing() {
    char* s1 = "abc";
    printf("%c\n", s1); // prints weird things
    printf("%c\n", *s1); // prints 'a'
    printf("%c\n", s1[0]); // prints 'a'
    printf("%s\n", s1 + 1); // prints "bc"
}

void dont_change_pa(int* p_a) {
    int i = 45;
    p_a = &i; // p_a got assigned a new address
}

int main() {
    cStrings();
    printAddress();
    arrayOfStrings();
    pointers();
    pointerToFunction();
    arrays();
    pointerArithmetic();

    int arr[3] = {5, 6, 7};
    change_arr0(arr); // this sends the pointer to the first element
    // arr is same as &(arr[0])
    // also the same as &(*arr)

    constChar();
    inClassPracticeJan15();
    printing();

    int a = 50;
    dont_change_pa(&a);

    return 0;
}
