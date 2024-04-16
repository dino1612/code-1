#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 5

struct Stack {
    int items[MAX_SIZE];
    int top;
};

typedef struct Stack Stack;

void initialize(Stack* s) {
    s->top = -1;
}

int isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push %d\n", value);
        return;
    }
    s->items[++s->top] = value;
    printf("Pushed %d\n", value);
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop\n");
        return -1;
    }
    printf("Popped %d\n", s->items[s->top]);
    return s->items[s->top--];
}

int main() {
    srand(time(NULL));
    Stack s;
    initialize(&s);
    int i;
    for (i = 0; i < 30; i++) {
        int random_num = rand() % 100 + 1;
        if (random_num % 2 == 0) {
            push(&s, random_num);
        }
        else {
            pop(&s);
        }
    }
    return 0;
}
