#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char exp[100];
    fgets(exp, sizeof(exp), stdin);

    char *token = strtok(exp, " ");

    while (token != NULL) {

        if (isdigit(token[0])) {
            push(atoi(token));
        }
        else {
            int op2 = pop();
            int op1 = pop();
            int res;

            switch (token[0]) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op1 / op2; break;
            }

            push(res);
        }

        token = strtok(NULL, " ");
    }

    printf("%d\n", pop());

    return 0;
}