//
//  Addtion.h
//  Addtion
//
//  Created by tang184 on 15/12/13.
//  Copyright © 2015年 tang184. All rights reserved.
//

#ifndef Addtion_h
#define Addtion_h

#include <stdio.h>

typedef int* (*Addition) (void *a, void *b, int *t);


void sumArray(int n, int elementSize, void * array, void * sum, Addition addition);

typedef int (*CompareFunction) (void *a, void *b);

typedef char* (*ToStringFunction) (void *a);


void PrintArray(int n, int elementSize, void * array, ToStringFunction toString);

void mysort( int n, int elementSize, void * array,
            int ascending, CompareFunction compFunc );


#endif /* Addtion_h */
