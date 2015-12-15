//
//  Addtion.c
//  Addtion
//
//  Created by tang184 on 15/12/13.
//  Copyright © 2015年 tang184. All rights reserved.
//

#include "Addtion.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void sumArray(int n, int elementSize, void * array, void * sum, Addition addition) {
    int i = 0;
    for ( i = 0; i < n; i++) {
        void *m = (void*) ((char*) array + i * elementSize);
        void *p = (void*) ((char*)  sum);
        sum = (void*) addition(m,p, sum);
        //printf("%p\n", sum);
        //printf("%d\n", *(int*)sum);
    }
    //printf("%d\n", *(int*)sum);
    //printf("%p\n", sum);
}

void PrintArray(int n, int elementSize, void * array, ToStringFunction toString) {
    int i;
    for ( i = 0; i < n; i++) {
        void *m = (void*) ((char*) array + i * elementSize);
        char * t = toString(m);
        printf("%s\n", t);
    }
}

void mysort(int n,                      // Number of elements
            int elementSize,            // Size of each element
            void * array,               // Pointer to an array
            int ascending,              // 0 -> descending; 1 -> ascending
            CompareFunction compFunc)   // Comparison function.
{
    void *tmp = malloc(elementSize);
    
    int j = 0;
    
    for (j = 0; j < n - 1; j++)
    {
        void *p1 = (void*)((char*)array+j*elementSize);
        
        int i;
        for (i = j + 1; i < n; i++)
        {
            
            void *p2 = (void*)((char*)array + i*elementSize);
            
            if (ascending)
            {
                if (compFunc(p1, p2) >= 0)
                {
                    memcpy(tmp, p1, elementSize);
                    memcpy(p1, p2, elementSize);
                    memcpy(p2, tmp, elementSize);
                    
                }
            }
            else
            {
                if (compFunc(p1, p2) <= 0)
                {
                    memcpy(tmp, p1, elementSize);
                    memcpy(p1, p2, elementSize);
                    memcpy(p2, tmp, elementSize);
                    
                }
            }
        }
    }
    
    free(tmp);
}