#include <stdio.h>
#include <stdlib.h>
#include "bst2.h"

treeNode* searchBST(treeNode* root, element x) {
    treeNode* p;
    int count = 0;
    p = root;

    while (p != NULL) {
        count++;

        if (x < p->key)
            p = p->left;
        else if (x == p->key) {
            printf("%3d번째에 탐색 성공", count);
            return p;
        }
        else
            p = p->right;
    }

    count++;
    printf("%3d번째에 탐색 실패! 찾는 키가 없습니다!", count);
    return p;
}

treeNode* insertBSTNode(treeNode* p, element x) {
    treeNode* newNode;

    if (p == NULL) {
        newNode = (treeNode*)malloc(sizeof(treeNode));
        newNode->key = x;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (x < p->key)
        p->left = insertBSTNode(p->left, x);
    else if (x > p->key)
        p->right = insertBSTNode(p->right, x);

    return p;
}

void deleteBSTNode(treeNode* root, element key) {
    // 이번 예제에서는 삭제 연산을 사용하지 않음
}

