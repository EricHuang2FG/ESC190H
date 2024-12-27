#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define 我靠 printf("It's ok\n");

struct Node {
    int val;
    struct Node* next;
};

void print(struct Node* head) {
    printf("[");
    while (head) {
        if (!head->next) {
            printf("%d", head->val);
        } else {
            printf("%d, ", head->val);
        }
        head = head->next;
    }
    printf("]\n");
}

void append(struct Node** head, int num) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->val = num;
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

int pop(struct Node** head, int targetIndex) {
    // return value of -1 means exiting with error
    if (*head == NULL) {
        printf("ERROR: Empty list\n");
        return -1;
    }

    int length = len(*head);
    int targetVal;
    struct Node* temp;
    if (targetIndex >= length) {
        printf("ERROR: List index out of range\n");
        return -1;
    }
    if (targetIndex == 0) {
        targetVal = (*head)->val;
        temp = *head;
        *head = (*head)->next;
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
            free(temp);
            return targetVal;
        }
        prevNode = currNode;
        currNode = currNode->next;
        i++;
    }
    return -1; // by default, return an error code
}

bool in(struct Node* head, int target) {
    while (head) {
        if (head->val == target) {
            return true;
        }
        head = head->next;
    }
    return false;
}

int indexOf(struct Node* head, int target) {
    int i = 0;
    while (head) {
        if (head->val == target) {
            return i;
        }
        i++;
        head = head->next;
    }
    return -1; // not found
}

int count(struct Node* head, int target) {
    int tot = 0;
    while (head) {
        if (head->val == target) {
            tot++;
        }
        head = head->next;
    }
    return tot;
}

int main() {
    我靠;
    struct Node* head = NULL;
    append(&head, 5);
    append(&head, 100);
    print(head);
    int node = pop(&head, 1);
    print(head);
    printf("%d", node);
    我靠;
    return 0;
}