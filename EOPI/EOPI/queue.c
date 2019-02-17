//
//  queue.c
//  EOPI
//
//  Created by chakri on 2/17/19.
//  Copyright © 2019 chakri. All rights reserved.
//

#include "queue.h"
#include "list.h"


QueueT *createQueue()
{
    
    QueueT  *q = (QueueT *) malloc(sizeof(QueueT));
    q->front = q->rear = NULL;
    return q; 
}
void enQueue(QueueT*q, int k)
    {
        // Create a new LL node
        struct ListNode  *temp = addNodeToList(k);
        
        // If queue is empty, then new node is front and rear both
        if (q->rear == NULL)
        {
            q->front = q->rear = temp;
            return;
        }
        
        // Add the new node at the end of queue and change rear
        q->rear->next = temp;
        q->rear = temp;
    }
struct ListNode  *  deQueue(QueueT*q){
    struct ListNode  *temp;
    
    if(q->front == NULL)
        return NULL;
    
    temp =q->front;
    
    q->front = q->front->next;
    if(q->front == NULL)
        q->rear = q->front;
    return (temp);
        
    
}
