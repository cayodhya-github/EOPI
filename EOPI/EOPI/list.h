//
//  list.h
//  EOPI
//
//  Created by chakri on 2/3/19.
//  Copyright © 2019 chakri. All rights reserved.
//

#ifndef list_h
#define list_h

#include <stdio.h>


/**
 * Definition for singly-linked list.
 * tyepdef struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *createList(int num_of_elements);
struct ListNode * addNodeToList(int data);
void printList(struct ListNode *head);
void reverseList(struct ListNode **head);
struct ListNode * mergeToSortedLists(struct ListNode *l1, struct ListNode *l2);
struct ListNode* reverseBetween(struct ListNode* head, int m, int n);




#endif /* list_h */
