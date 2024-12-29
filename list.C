#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define 我靠 printf("It's ok\n");

struct Node {
    void* val;
    struct Node* next;
};

void print(struct Node* head, char* type) {
    printf("[");
    while (head) {
        if (strcmp(type, "char") == 0) {
            printf("%c", *(char*)head->val);
        } else if (strcmp(type, "int") == 0) {
            printf("%d", *(int*)head->val);
        } else if (strcmp(type, "float") == 0 || strcmp(type, "double") == 0) {
            printf("%f", *(float*)head->val);
        } else if (strcmp(type, "long") == 0) {
            printf("%ld", *(long*)head->val);
        } else if (strcmp(type, "long long") == 0) {
            printf("%lld", *(long long*)head->val);
        } else if (strcmp(type, "unsigned int") == 0) {
            printf("%u", *(unsigned int*)head->val);
        } else if (strcmp(type, "unsigned long") == 0) {
            printf("%lu", *(unsigned long*)head->val);
        } else if (strcmp(type, "string") == 0) {
            printf("%s", (char*)head->val);
        } else {
            printf("ERROR: Unsupported type\n");
            return;
        }
        if (head->next) {
            printf(", ");
        } 
        head = head->next;
    }
    printf("]\n");
}

void append(struct Node** head, void* newVal, size_t valSize) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->val = malloc(valSize);
    memcpy(newNode->val, newVal, valSize);
    newNode->next = NULL;
    if (!(*head)) {
        (*head) = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int len(struct Node* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

void* pop(struct Node** head, int targetIndex) {
    // return value of NULL means exiting with error
    if (*head == NULL) {
        printf("ERROR: Empty list\n");
        return NULL;
    }

    int length = len(*head);
    void* targetVal;
    struct Node* temp;
    if (targetIndex >= length) {
        printf("ERROR: List index out of range\n");
        return NULL;
    }
    if (targetIndex == 0) {
        targetVal = (*head)->val;
        temp = *head;
        *head = (*head)->next;
        free(temp->val);
        free(temp);
        return targetVal;
    }
    int i = 1;
    struct Node* prevNode = *head;
    struct Node* currNode = (*head)->next;
    while (currNode) {
        if (i == targetIndex) {
            targetVal = currNode->val;
            temp = currNode;
            prevNode->next = currNode->next;
            free(temp->val);
            free(temp);
            return targetVal;
        }
        prevNode = currNode;
        currNode = currNode->next;
        i++;
    }
    return NULL; // by default, return the NULL pointer
}

bool match(void* a, void* b, char* type) {
    if (strcmp(type, "char") == 0) {
        return *(char*) a == *(char*) b;
    } else if (strcmp(type, "int") == 0) {
        return *(int*) a == *(int*) b;
    } else if (strcmp(type, "float") == 0 || strcmp(type, "double") == 0) {
        return *(float*) a == *(float*) b;
    } else if (strcmp(type, "long") == 0) {
        return *(long*) a == *(long*) b;
    } else if (strcmp(type, "long long") == 0) {
        return *(long long*) a == *(long long*) b;
    } else if (strcmp(type, "unsigned int") == 0) {
        return *(unsigned int*) a == *(unsigned int*) b;
    } else if (strcmp(type, "unsigned long") == 0) {
        return *(unsigned long*) a == *(unsigned long*) b;
    } else if (strcmp(type, "string") == 0) {
        return strcmp((char*) a, (char*) b) == 0;
    }
    printf("ERROR: Unsupported type\n");
    return false;
}

bool in(struct Node* head, void* target, char* type) {
    while (head) {
        if (match(head->val, target, type)) {
            return true;
        }
        head = head->next;
    }
    return false;
}

int indexOf(struct Node* head, void* target, char* type) {
    int i = 0;
    while (head) {
        if (match(head->val, target, type)) {
            return i;
        }
        i++;
        head = head->next;
    }
    return -1; // not found
}

int count(struct Node* head, void* target, char* type) {
    int tot = 0;
    while (head) {
        if (match(head->val, target, type)) {
            tot++;
        }
        head = head->next;
    }
    return tot;
}

void* get(struct Node* head, int index) {
    if (head == NULL) {
        printf("ERROR: Empty list\n");
        return NULL;
    }
    int i = 0;
    while (head) {
        if (i == index) {
            return head->val;
        }
        i++;
        head = head->next;
    }
    printf("ERROR: List index out of range\n"); // not found
    return NULL;
}

int main() {
    // testing
    我靠;
    struct Node* head = NULL;
    int toAdd = 5;
    append(&head, (void*) &toAdd, sizeof(toAdd));
    append(&head, (void*) &toAdd, sizeof(toAdd));
    toAdd = 123;
    append(&head, (void*) &toAdd, sizeof(toAdd));
    int lastVal = *((int*) pop(&head, len(head) - 1));
    print(head, "int");
    printf("%d\n", lastVal);
    printf("%d\n", count(head, (void*) &toAdd, "int"));
    toAdd = 5;
    printf("%d\n", count(head, (void*) &toAdd, "int"));

    struct Node* stringHead = NULL;
    char* str = "hello world";
    append(&stringHead, (void*) str, strlen(str) + 1);
    str = "goodbye world lol";
    append(&stringHead, (void*) str, strlen(str) + 1);
    print(stringHead, "string");
    bool check = in(stringHead, (void*) str, "string");
    for (int i = 0; i < 10; i++) {
        append(&stringHead, (void*) str, strlen(str) + 1);
    }
    printf("%d\n", count(stringHead, (void*) str, "string"));
    我靠;
    return 0;
}
