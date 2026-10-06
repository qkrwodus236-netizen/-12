#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "DoubleLinkedList.h"

// 공백 이중 연결 리스트 생성
linkedList_h* createLinkedList_h(void) {
    linkedList_h* DL = (linkedList_h*)malloc(sizeof(linkedList_h));
    DL->head = NULL;
    return DL;
}

// 이중 연결 리스트 출력
void printList(linkedList_h* DL) {
    listNode* p;
    printf("DL = (");
    p = DL->head;
    while (p != NULL) {
        printf("%s", p->data);
        p = p->rlink;
        if (p != NULL) printf(", ");
    }
    printf(")\n");
}

// 노드 삽입
void insertNode(linkedList_h* DL, listNode* pre, char* x) {
    listNode* newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode->data, x);

    if (DL->head == NULL) { // 리스트가 비어있는 경우
        newNode->llink = NULL;
        newNode->rlink = NULL;
        DL->head = newNode;
    }
    else if (pre == NULL) { // 맨 앞에 삽입하는 경우
        newNode->llink = NULL;
        newNode->rlink = DL->head;
        DL->head->llink = newNode;
        DL->head = newNode;
    }
    else { // pre 노드 다음에 삽입하는 경우
        newNode->llink = pre;
        newNode->rlink = pre->rlink;
        if (pre->rlink != NULL) {
            pre->rlink->llink = newNode;
        }
        pre->rlink = newNode;
    }
}

// 노드 삭제
void deleteNode(linkedList_h* DL, listNode* old) {
    if (DL->head == NULL || old == NULL) return;

    if (old == DL->head) { // 첫 번째 노드 삭제
        DL->head = old->rlink;
        if (DL->head != NULL) {
            DL->head->llink = NULL;
        }
    }
    else { // 중간 또는 마지막 노드 삭제
        old->llink->rlink = old->rlink;
        if (old->rlink != NULL) {
            old->rlink->llink = old->llink;
        }
    }
    free(old);
}

// 노드 탐색
listNode* searchNode(linkedList_h* DL, char* x) {
    listNode* temp = DL->head;
    while (temp != NULL) {
        if (strcmp(temp->data, x) == 0) return temp;
        temp = temp->rlink;
    }
    return NULL;
}
