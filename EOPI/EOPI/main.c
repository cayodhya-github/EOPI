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
    printf("Hello, World!\n");
    
    printf ("Number of Bits Set %d\n", countBits(0xAA55AA55));
    printf ("digit Char to Integer %d\n" ,strToint( "" ,0));

    return 0;
}
