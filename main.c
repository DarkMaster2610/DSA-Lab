#include <stdio.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} stack;

void init(stack *s) {
    s->top = -1;
}

int isempty(stack *s) {
    return s->top == -1;
}

int isfull(stack *s) {
    return s->top == MAX - 1;
}

void push(stack *s, int value) {
    if (isfull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->arr[++(s->top)] = value;
    printf("Pushed %d\n", value);
}

int pop(stack *s) {
    if (isempty(s)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

int peek(stack *s) {
    if (isempty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}

int main() {
    stack s;
    init(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printf("Top element is %d\n", peek(&s));
    printf("Popped element is %d\n", pop(&s));
    printf("Popped element is %d\n", pop(&s));
    if (isempty(&s)) {
        printf("Stack is empty now\n");
    } else {
        printf("Stack is not empty\n");
    }
    return 0;
}
