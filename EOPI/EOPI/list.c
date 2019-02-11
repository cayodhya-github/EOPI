//
//  list.c
//  EOPI
//
//  Created by chakri on 2/3/19.
//  Copyright © 2019 chakri. All rights reserved.
//

#include "list.h"
#include "stdlib.h"

struct ListNode * addNodeToList(int data)
{
    struct ListNode *node = malloc(sizeof(struct ListNode ));
    if(node== NULL)
        return NULL;
    node->val = data;
    node->next = NULL;
    
    return node;
    
}

void printList(struct ListNode *head)
{
    int i=0;
    while(head){
        printf("Element %d, val %d\n", i++,head->val);
    head = head->next;
    }
}
struct ListNode *createList(int num_of_elements)
{
    
    struct ListNode *runner=NULL, *temp=NULL;
    
    while(num_of_elements)
    {
        if(runner == NULL) {
            runner =addNodeToList(num_of_elements);
            temp = runner;
        }
        else {
            runner->next =addNodeToList(num_of_elements);
            runner = runner->next;
        }
        num_of_elements--;
    }
    return temp;
}


void reverseList(struct ListNode **head)
{
    struct ListNode *temp = *head;
    struct ListNode *prev = NULL;
    struct ListNode *next;
    while(temp)
    {
        next = temp->next;
        temp->next = prev;
        prev=temp;
        temp=next;
    }
    *head = prev;
    
}


struct ListNode* reverseListLeetCode(struct ListNode* head) {
    
    struct ListNode * temp = head;
    struct ListNode * prev = NULL;
    struct ListNode *next;
    while(temp)
    {
        next = temp->next;
        temp->next = prev;
        prev=temp;
        temp=next;
    }
    return( prev);
    
}


void appendNode(struct ListNode **node , struct ListNode **tail)
{
    (*tail)->next = *node;
    *tail = *node;
    *node = (*node)->next;
}

//21. Merge Two Sorted Lists
//Idea here is using doule pointers to append and also increment the node
// which we alread appended.

struct ListNode * mergeToSortedLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode dummy_list;
    struct ListNode *tail =(struct ListNode *)&dummy_list;
    
    while(l1 && l2)
        appendNode((l1->val <= l2->val ? &l1:&l2), &tail);
    
    
    tail->next = l1 ? l1 : l2;
        
    return (dummy_list.next);
}
//92. Reverse Linked List II, we need to achieve the single pass
//same problem we have in EOPI


struct ListNode* reverseBetween(struct ListNode* head, int m, int n)
{
    struct ListNode* cur=head;
    struct ListNode* prev=NULL;
    struct ListNode* start;
    struct ListNode* tail;
    struct ListNode* nextNode = NULL;
    if(head == NULL)
        return head;
    
    while(m > 1)
    {
        prev = cur;
        cur= cur->next;
        m--;
        n--;
    }
    start= prev;
    tail = cur;
    while(n > 0)
    {
        nextNode = cur->next;
        cur->next = prev;
        prev=cur;
        cur = nextNode;
        n--;
    }
    if(start!= NULL)
        start->next = prev;
    else
        head = prev;
    
    tail->next = cur;
    return head;
    
}

//876. Middle of the Linked List

struct ListNode* middleNode(struct ListNode* head) {
    
    struct ListNode *fast=head,*slow = head;
    
    while(fast!= NULL && fast->next != NULL )
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast!=NULL && fast->next)
        return (slow->next);
    else
        return (slow);
    
}


//237. Delete Node in a Linked List

void deleteNode(struct ListNode* node) {
    struct ListNode* temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    temp->next = NULL;
    free(temp);
}
//83. Remove Duplicates from Sorted List
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current = head;
    struct ListNode* next;
    struct ListNode* temp;
    while(current!= NULL)
    {
        next = current->next;
        if( (next!= NULL) &&  ( current->val == next->val) )
        {
            temp = next;
            current->next = next->next;
            free(temp);
        }
        else
            current= current->next;
        
    }
    return (head);
}
//141. Linked List Cycle


int  hasCycle(struct ListNode *head) {
    struct ListNode *fast=head,*slow = head;
    
    while(fast!= NULL && fast->next != NULL )
    {
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast)
            return 1;
    }
    return 0;
    
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    
    struct ListNode dummy_node;
    struct ListNode* runner = &dummy_node;
    struct ListNode* temp;
    dummy_node.next = head;
    while(runner!=NULL && runner->next!= NULL)
    {
        if(runner->next->val == val)
        {
            
            temp = runner->next;
            runner->next = temp->next;
        }
        else
            runner = runner->next;
    }
    return dummy_node.next;
    
}

int  isPalindrome(struct ListNode* head) {
    
    struct ListNode*middle;
    struct ListNode*temp;
    if(head!=NULL)
    {
        struct ListNode *fast=head,*slow = head;
        
        while(fast!= NULL && fast->next != NULL )
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        temp = reverseListLeetCode(slow);
        while(head && temp)
        {
            if(head->val != temp->val)
                return 0;
            
            head = head->next;
            temp= temp->next;
        }
    }
    return 1;
    
}

//369. Plus One Linked List


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void addone(struct ListNode* head,struct ListNode* prev)
{
    if(!head)
    {
        prev->val+=1;
        return;
    }
    addone(head->next,head);
    if(head->val == 10)
    {
        head->val =0;
        prev->val+=1;
    }
    
}
struct ListNode* plusOne(struct ListNode* head)
{
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->next = head;
    node->val =0;
    if(head == NULL)
        return head;
    addone(head,node);
    if(node->val ==1)
        return node;
    else
        return node->next;
    
    
}


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//817. Linked List Components

int isNumberExits(int* G, int GSize,int number)
{
    
    while(GSize >= 0)
    {
        if(G[GSize--] == number)
            return 1;
        
    }
    
    return 0;
}

int numComponents(struct ListNode* head, int* G, int GSize) {
    
    int count=0;
    while(head )
    {
        if(isNumberExits(G,GSize-1,head->val))
        {
            count++;
            
            while( (head->next)  &&  (isNumberExits(G,GSize-1,(head->next->val))))
            {
                head = head->next;
            }
        }
        head = head->next;
    }
    return count;
}
