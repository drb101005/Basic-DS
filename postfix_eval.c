#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX], top = -1;

void push(int item) { stack[++top] = item; }
int pop() { return (top == -1) ? -1 : stack[top--]; }

int evaluatePostfix(char* postfix) {
    int i = 0, op1, op2;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        } else {
            op2 = pop();
            op1 = pop();
            switch (postfix[i]) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
        i++;
    }
    return pop();
}

int main() {
    char postfix[MAX] = "23*42-/+";
    printf("Postfix: %s\nResult: %d\n", postfix, evaluatePostfix(postfix));
    return 0;
}