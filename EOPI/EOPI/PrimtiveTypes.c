//
//  PrimtiveTypes.c
//  EOPI
//
//  Created by chakradhararao ayodhya on 12/5/18.
//  Copyright © 2018 chakri. All rights reserved.
//

#include "PrimtiveTypes.h"


/* How to count number of ones in the given interger.*/

char countBits(unsigned int x)
{
    
    char numBitsSet =0;
    while (x)
    {
        numBitsSet += x & 0x1;
        x= x>>1;
    }
    return numBitsSet;
}

/*
 we need to consider the following conditions.
 1. Null string / len might be 0
 2. sign handling.
 3. if we have sign is first char, we need to adjust the length
 and also the start of the numbers.
 4. we need to conver char to number int first.( x - '0')
 
 */


int strToint( char *string , int len)
{
    int retIntval = 0;
    int signSet=0;
    char *stringPtr=0;
    int i=0;
    int newLength=0;
    
    if(0 != len )
    {
        if(string[0] == '-')
        {
            signSet =1;
            stringPtr =&string[1];
            newLength = len-1;
        }
        else{
            stringPtr =&string[0];
            newLength = len;
        }
        retIntval = (stringPtr[0] -'0');
        for(i=1;i< newLength;i++) {
            retIntval *= 10;
            retIntval +=(stringPtr[i] - '0');
        }
        
        if(signSet)
            retIntval *= -1;
        
        
    }
    return (retIntval);
    
}