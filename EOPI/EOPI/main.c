//
//  main.c
//  EOPI
//
//  Created by chakradhararao ayodhya on 12/5/18.
//  Copyright © 2018 chakri. All rights reserved.
//

#include <stdio.h>
#include "PrimtiveTypes.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int *src = (int *)0x80000001;
   // int  *dst = (int*)0x5;
    
    int a = ((int)src & 0xFFFFFFFC);
    int b = !a;
    printf("a:: 0x%x b:: 0x%x\n",a,b);
    printf("Hello, World!\n");
    
    printf ("Number of Bits Set %d\n", countBits(0xAA55AA55));
    printf ("digit Char to Integer %d\n" ,strToint( "" ,0));

    return 0;
}
