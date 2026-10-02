#include <stdio.h>
#include "stackS.h"

int top = -1;	// top 변수를 -1로 초기화 (공백 스택 상태)

// 스택이 공백 상태인지 확인하는 연산
int isStackEmpty(void) {
	if (top == -1) return 1;
	else return 0;
}

// 스택이 포화 상태인지 확인하는 연산
int isStackFull(void) {
	if (top == STACK_SIZE - 1) return 1;
	else return 0;
}

// 스택의 top에 요소를 삽입하는 연산
void push(element item) {
	if (isStackFull()) {	// 스택이 포화 상태인 경우
		printf("\n\n Stack is Full!\n");
		return;
	}
	else stack[++top] = item;	// top을 1 증가시킨 후 item 저장
}

// 스택의 top에서 요소를 삭제하고 반환하는 연산
element pop(void) {
	if (isStackEmpty()) {	// 스택이 공백 상태인 경우
		printf("\n\n Stack is Empty!!\n");
		return 0;
	}
	else return stack[top--];	// 현재 top의 요소를 반환한 후 top을 1 감소
}

// 스택의 top 요소를 확인하는 연산 (삭제X)
element peek(void) {
	if (isStackEmpty()) {
		printf("\n\n Stack is Empty!\n");
		return 0;
	}
	else return stack[top];
}

// 스택의 모든 요소를 출력하는 연산
void printStack(void) {
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++)
		printf("%d ", stack[i]);
	printf("]");
}
