#include <stdio.h>
#include "stackS.h"

int main(void) {
    element item;

    printf("\n*** 순차 스택 구현 ***\n");
    printStack();

    push(1); printStack(); 
    push(2); printStack();
    push(3); printStack();
    
    item = peek(); 
    printStack();
    printf("\npeek => %d\n", item); 
    
    item = pop(); 
    printf("pop => %d", item);     
    printStack();
    
    item = pop(); 
    printf("\npop => %d", item);
    printStack();
    
    item = pop(); 
    printf("\npop => %d\n", item);
    printStack();
    
    getchar(); 
    return 0;
}
