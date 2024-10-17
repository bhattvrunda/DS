#include <stdio.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;
int postfixIndex = 0;

void push(char value) {
    if (top == MAX - 1) {
        printf("Stack overflow! Unable to push %c\n", value);
    } else {
        stack[++top] = value;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack underflow! Unable to pop\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isOperand(ch)) {
            postfix[postfixIndex++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[postfixIndex++] = pop();
            }
            if (top != -1) {
                pop();
            }
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[postfixIndex++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[postfixIndex++] = pop();
    }
    postfix[postfixIndex] = '\0';
}

void main() {
    char infix[MAX], postfix[MAX];
    clrscr();
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    getch();
}

