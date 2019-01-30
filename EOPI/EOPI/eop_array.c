//
//  eop_array.c
//  EOPI
//
//  Created by chakradhararao ayodhya on 1/20/19.
//  Copyright © 2019 chakri. All rights reserved.
//

#include "eop_array.h"
#include "stdlib.h"
#include <string.h>


void swap(int *right, int *left)
{
    int temp = *right;
    *right = *left;
    *left = temp;
    
}

int strLengthLocal(char *str)
{
    int rc=0;
    while(str[rc])
        rc++;
    return rc;
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

/*
 Since we have interger overflows we go two basic school algo for multiplication.
 we need to check whether we have sign for any of two nubers,
 based on that we need to adjust the starting size.
 
 Out arrary size should be sum of sizes of two arrays + 1;
 in same loop, we will do multiplications
 1. check whether we have carry , if yes we will add to towards left
 and update current with modulo of 10.
 
 so we will have about m products so time complexity will be aroubd 0(mn)
 
 */


int* muliplicationofNumbers(int *nOne, int nOneSize, int *nTwo, int nTwoSize)
{
    int product[6] ={0};
    int i=0, j=0;
    {
        for(i=nOneSize-1; i>=0;i--)
        {
            for(j=nTwoSize-1;j>=0;j--)
            {
                product[i+j+1] +=nOne[i] * nTwo[j];
                product [i+j] += product[i+j+1]/10;
                product[i+j+1] %=10;
            }
        }
        
        
    }
 //   return (product);
    return (NULL);
    
}

/*
    int rc=0;
 43. Multiply Strings
 
 */
char* multiply(char* num1, char* num2) {
    int nOneSize,nTwoSize=0;
    nOneSize = strLengthLocal(num1);
    nTwoSize = strLengthLocal(num2);
    int i=0, j=0;
    char *retProduct;
    char *product = malloc(sizeof(char) * ( nOneSize +nTwoSize ) );
   // char product[6] = {0};
    if ( ((nOneSize == 1 ) ||(nTwoSize ==1) ) && (( *num1 == '0') || (*num2 == '0' )) )
    {
        retProduct = "0";
        return (retProduct);
    }
    memset(product,0x0,( nOneSize +nTwoSize ) );
    {
        for(i=nOneSize-1; i>=0;i--)
        {
            for(j=nTwoSize-1;j>=0;j--)
            {
                int a =(num1[i] -'0');
                int b =(num2[j] -'0');
                product[i+j+1] += (b * a );
                product [i+j] += product[i+j+1]/10;
                product[i+j+1] %=10;
                product[i+j+1] %=10;
               // product[i+j+1] = product[i+j+1]+'0';
            }
        }
    }
    retProduct =product;
    for(i=0;i<(nOneSize+nTwoSize);i++)
    {
        *product +='0';
        product++;
    }
    product = '\0';
    
    while(*retProduct == '0')
        ++retProduct;
    return (retProduct);
    
}


