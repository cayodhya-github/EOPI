//
//  eop_array.c
//  EOPI
//
//  Created by chakradhararao ayodhya on 1/20/19.
//  Copyright © 2019 chakri. All rights reserved.
//

#include "eop_array.h"

void swap(int *right, int *left)
{
    int temp = *right;
    *right = *left;
    *left = temp;
    
}


//    int data[10] = {10,1,9,2,8,3,7,4,6,5};


void dutchFlagProblem(int *data,int size, int pivot_data)
{
    int less=0, equal=0;
    int large = size;
    printf ( "less %d , equal %d large %d", less, equal, large);
    while(equal < large)
    {
            if(data[equal] < pivot_data)
            {
                swap(&data[less],&data[equal]);
                equal++;
                less++;
            }else if( data[equal] == pivot_data)
                equal++;
            else
            {
                swap(&data[equal],&data[large]);
                --large;
            }
    }
            
}

#define RED     0
#define WHITE   1
#define BLUE    2

/*Leet code 75 ::75. Sort Colors*/


void sortColors(int* nums, int numsSize)
{
    int red =0, white=0;
    int blue = numsSize-1;
    
    while(white <= blue)
    {
        if(nums[white] == RED)
        {
            swap(&nums[white],&nums[red]);
            white++;
            red++;
        }
        else if (nums[white] == WHITE)
        {
            white++;
        }
        else // case for blue.
        {
            swap(&nums[white],&nums[blue]);
            blue--;
        }
    }
}


/*5.2 Increment arbitratory precision integer.
 array{1,2,9} == array {130}
 
 we are assuming we will have space for extra carry.
 */

void addOne(int *nums, int numsSize)
{
    int carry=0,i=0;
    nums[numsSize-1] += 1;
    for(i=numsSize;i>=0;i--)
    {
        nums[i] += carry;
        if(nums[i] >= 10)
        {
            carry=1;
            nums[i] = nums[i] % 10;
        }
        else
           carry=0;
            
    }
}
