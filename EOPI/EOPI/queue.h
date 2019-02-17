//
//  queue.h
//  EOPI
//
//  Created by chakri on 2/17/19.
//  Copyright © 2019 chakri. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>


typedef struct  {
    
    struct ListNode *rear, *front;
}QueueT;

QueueT *createQueue();
void enQueue(QueueT*q, int k);

#endif /* queue_h */
