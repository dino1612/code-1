#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define INITIAL_SIZE 5

// 스택 구조체 정의
typedef struct {
    int* items;
    int top;
    int size;
} Stack;

// 스택 초기화 함수
void initialize(Stack* stack) {
    stack->items = (int*)malloc(INITIAL_SIZE * sizeof(int));
    if (stack->items == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->top = -1;
    stack->size = INITIAL_SIZE;
}

// 스택이 비어있는지 확인하는 함수
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 스택이 가득 차있는지 확인하는 함수
bool isFull(Stack* stack) {
    return stack->top == stack->size - 1;
}

// 스택에 요소를 추가하는 함수(push)
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        // 스택이 가득 찼을 때 크기를 두 배로 확장
        stack->size *= 2;
        stack->items = (int*)realloc(stack->items, stack->size * sizeof(int));
        if (stack->items == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    stack->top++;
    stack->items[stack->top] = value;
    printf("Pushed: %d\n", value);
}

// 스택에서 요소를 제거하고 반환하는 함수(pop)
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    else {
        int popped = stack->items[stack->top];
        stack->top--;
        printf("Popped: %d\n", popped);
        return popped;
    }
}

int main() {
    // 시드값 설정을 위한 srand 호출
    srand(time(NULL));

    // 스택 구조체 선언 및 초기화
    Stack stack;
    initialize(&stack);

    // 30번의 반복 동안 난수를 생성하여 push 또는 pop 실행
    for (int i = 0; i < 30; i++) {
        int randomNumber = rand() % 100 + 1; // 1부터 100까지의 난수 생성
        if (randomNumber % 2 == 0) {
            push(&stack, randomNumber);
        }
        else {
            pop(&stack);
        }
    }

    // 동적으로 할당한 메모리 해제
    free(stack.items);

    return 0;
}
