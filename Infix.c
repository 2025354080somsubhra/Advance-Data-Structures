#include <stdio.h>
#include <ctype.h>

#define MAX 100

void push(char stack[], int *N, char ele) {
    if (*N >= MAX) {
        printf("Stack Overflow\n");
        return;
    }

    stack[*N] = ele;
    *N = *N + 1;
}

char pop(char stack[], int *N) {
    if (*N == 0) {
        printf("Stack Underflow\n");
        return '\0';
    }

    *N = *N - 1;
    return stack[*N];
}

char peek(char stack[], int N) {
    if (N == 0) {
        return '\0';
    }

    return stack[N - 1];
}

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[]) {
    char stack[MAX];
    char postfix[MAX];

    int N = 0;
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {

        // Operand
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        // Opening bracket
        else if (infix[i] == '(') {
            push(stack, &N, infix[i]);
        }

        // Closing bracket
        else if (infix[i] == ')') {
            while (N != 0 && peek(stack, N) != '(') {
                postfix[j++] = pop(stack, &N);
            }

            pop(stack, &N);   // remove '('
        }

        // Operator
        else {
            while (N != 0 &&
                   peek(stack, N) != '(' &&
                   precedence(peek(stack, N)) >= precedence(infix[i])) {

                postfix[j++] = pop(stack, &N);
            }

            push(stack, &N, infix[i]);
        }
    }

    // Pop remaining operators
    while (N != 0) {
        postfix[j++] = pop(stack, &N);
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}