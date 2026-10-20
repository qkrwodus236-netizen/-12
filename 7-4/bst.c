#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "bst.h"

// 이진 탐색 트리에서 키값이 x인 노드 탐색
treeNode* searchBST(treeNode* root, element x) {
    treeNode* p;
    p = root;

    while (p != NULL) {
        if (x < p->key)
            p = p->left;
        else if (x == p->key)
            return p;
        else
            p = p->right;
    }

    printf("\n찾는 키가 없습니다!");
    return p;
}

// 이진 탐색 트리에 노드 삽입
treeNode* insertBSTNode(treeNode* p, element x) {
    treeNode* newNode;

    if (p == NULL) {
        newNode = (treeNode*)malloc(sizeof(treeNode));

        if (newNode == NULL) {
            printf("메모리 할당 실패!\n");
            return NULL;
        }

        newNode->key = x;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    else if (x < p->key)
        p->left = insertBSTNode(p->left, x);

    else if (x > p->key)
        p->right = insertBSTNode(p->right, x);

    else
        printf("\n이미 같은 키가 있습니다!\n");

    return p;
}

// 이진 탐색 트리에서 노드 삭제
treeNode* deleteBSTNode(treeNode* root, element key) {
    treeNode* parent, *p, *succ, *succ_parent;
    treeNode* child;

    parent = NULL;
    p = root;

    // 삭제할 노드 탐색
    while ((p != NULL) && (p->key != key)) {
        parent = p;

        if (key < p->key)
            p = p->left;
        else
            p = p->right;
    }

    // 삭제할 노드가 없는 경우
    if (p == NULL) {
        printf("\n찾는 키가 이진 트리에 없습니다!!");
        return root;
    }

    // 삭제할 노드가 단말 노드인 경우
    if ((p->left == NULL) && (p->right == NULL)) {
        if (parent != NULL) {
            if (parent->left == p)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        else
            root = NULL;
    }

    // 삭제할 노드가 자식 노드를 한 개 가진 경우
    else if ((p->left == NULL) || (p->right == NULL)) {
        if (p->left != NULL)
            child = p->left;
        else
            child = p->right;

        if (parent != NULL) {
            if (parent->left == p)
                parent->left = child;
            else
                parent->right = child;
        }
        else
            root = child;
    }

    // 삭제할 노드가 자식 노드를 두 개 가진 경우
    else {
        succ_parent = p;
        succ = p->left;

        // 왼쪽 서브 트리에서 후계자 찾기
        while (succ->right != NULL) {
            succ_parent = succ;
            succ = succ->right;
        }

        if (succ_parent->left == succ)
            succ_parent->left = succ->left;
        else
            succ_parent->right = succ->left;

        p->key = succ->key;
        p = succ;
    }

    free(p);
    return root;
}
