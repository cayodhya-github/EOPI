//
//  stack.h
//  EOPI
//
//  Created by chakri on 2/17/19.
//  Copyright © 2019 chakri. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>


typedef int stackElementT;

typedef struct {
    stackElementT *stack_contents;
    int top;
    int max_size;
}stackT;


void StackPush(stackT *stackP, stackElementT data);
void StackPop(stackT *stackP, stackElementT *data);
int  StackIsEmpty(stackT *stackP);

int StackIsFull(stackT *stack);



void StackInit(stackT *stackP, int maxSize);
#endif /* stack_h */
