//
//  main.c
//  Addtion
//
//  Created by tang184 on 15/12/13.
//  Copyright © 2015年 tang184. All rights reserved.
//
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "Addtion.h"

int a[] = {45, 23, 78, 12, 100, 1, 100, 34, 90, 78 };


int* addInt( void * a, void * b , int *sum)
{
    //printf("%d\n", *(int*)a);
    //printf("%d\n", *(int*)b);
    *sum = *(int*)a + *(int*)b;
    return sum;
}

int compareInt( void * a, void * b )
{
    return *(int*)a - *(int*) b;
}

char * inttoString (void *a) {
    char * m = malloc(sizeof(int));
    sprintf(m, "%d", *(int*)a);
    return m;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    int i;
    int nelements = sizeof(a)/sizeof(int);
    
    printf("--- Numbers ----\n");
    for ( i = 0; i < nelements; i++ ) {
        //printf("a[%d]=%d\n", i, a[i] );
    }
    
    int *t = malloc(sizeof(int));
    *t = 0;
    
    sumArray( nelements, sizeof(int), a, t, addInt );
    printf("%p\n", t);
    printf("%d\n", *(int*)t);
    
    printf( "testWithint OK\n");
    
    
    nelements = sizeof(a)/sizeof(int);
    
    printf("--- Numbers ----\n");
    for ( i = 0; i < nelements; i++ ) {
        //printf("a[%d]=%d\n", i, a[i] );
    }
    
    PrintArray(nelements, sizeof(int), a, inttoString);
    
    mysort( nelements, sizeof(int), a, 1, compareInt );
    
    printf("---- Numbers after Sorting ----\n");
    for ( i = 0; i < nelements; i++ ) {
        printf("a[%d]=%d\n", i, a[i] );
    }
    
    // Test that numbers are ordered
    for ( i = 0; i < nelements -1 ; i++ ) {
        assert( a[i] <= a[i+1] );
    }
    
    printf( "testWithint OK\n");
    
    return 0;
}
