//
//  stack.c
//  EOPI
//
//  Created by chakri on 2/17/19.
//  Copyright © 2019 chakri. All rights reserved.
//

#include <stdlib.h>
#include "stack.h"



void StackInit(stackT *stackP, int maxSize)
{
    stackElementT *newContents;
    
    /* Allocate a new array to hold the contents. */
    
    newContents = (stackElementT *)malloc(sizeof(stackElementT)
                                          * maxSize);
    
    if (newContents == NULL) {
        fprintf(stderr, "Insufficient memory to initialize stack.\n");
        return;
        
    }
    
    stackP->stack_contents = newContents;
    stackP->max_size = maxSize;
    stackP->top = -1;  /* I.e., empty */
}
int  StackIsEmpty(stackT *stackP)
{
    return (stackP->top == -1);
}

int StackIsFull(stackT *stackP)
{
    return (stackP->top == (stackP->max_size -1));

}

void StackPush(stackT *stackP, stackElementT data)
{
    if(!StackIsFull(stackP))
    {
        stackP->stack_contents[++stackP->top] = data;
    }
    
}
void StackPop(stackT *stackP, stackElementT *data)
{
    if(!StackIsEmpty(stackP))
        *data =stackP->stack_contents[stackP->top--];
    else
        *data = 0xDEADBEAF;
}

