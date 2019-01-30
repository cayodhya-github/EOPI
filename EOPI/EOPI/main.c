//
//  main.c
//  EOPI
//
//  Created by chakradhararao ayodhya on 12/5/18.
//  Copyright © 2018 chakri. All rights reserved.
//

#include <stdio.h>
#include "PrimtiveTypes.h"
#include "eop_array.h"



int main(int argc, const char * argv[]) {
    // insert code here...
  //  int data = {1,2,3,4,5,6,7,8,9,10};
    //int data[10] = {10,1,9,2,8,3,7,4,6,5};
    char *str1 = "1";
    char *str2 = "1";
//    sortColors(array, 3);
    char *ptr=NULL;
    ptr = multiply(str1,str2);
    printf("%s",ptr);

   while(1);
    //dutchFlagProblem(data,9,6);

    return 0;
}
