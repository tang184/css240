//
//  bit.c
//  mystring
//
//  Created by tang184 on 15/11/4.
//  Copyright © 2015年 tang184. All rights reserved.
//

#include "bit.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// It prints the bits in bitmap as 0s and 1s.
void printBits(unsigned int bitmap)
{
    int i;
    unsigned int b;
    for(i = 31;i>= 0 && (b=(1<<i)); i-- ) {
        if (bitmap & b) {
            printf("%c",'1');
        } else {
            printf ("%c", '0');
        }
    }
    printf("\n10987654321098765432109876543210\n");
}


// Sets the ith bit in *bitmap with the value in bitValue (0 or 1)
void setBitAt( unsigned int *bitmap, int i, int bitValue ) {
    unsigned int b = 1<<i;
    if (bitValue) {
        *bitmap = *bitmap | b;
    } else {
        *bitmap = *bitmap & ~b;
    }
}

// It returns the bit value (0 or 1) at bit i
int getBitAt( unsigned int bitmap, unsigned int i) {
    // Add your code here
    unsigned int mask=(1<<i);
    if (mask & bitmap) {
        return 1;
    } else {
        return 0;
    }
}

// It returns the number of bits with a value "bitValue".
// if bitValue is 0, it returns the number of 0s. If bitValue is 1, it returns the number of 1s.
int countBits( unsigned int bitmap, unsigned int bitValue) {
    // Add your code here
    int i;
    int m = 0;
    int n = 0;
    unsigned int b;
    for(i = 31;i>= 0 && (b=(1<<i)); i-- ) {
        if (bitmap & b) {
            m++;
        } else {
            n++;
        }
    }
    
    if (bitValue) {
        return m;
    } else {
        return n;
    }
    
}

// It returns the number of largest consecutive 1s in "bitmap".
// Set "*position" to the beginning bit index of the sequence.
int maxContinuousOnes(unsigned int bitmap, int * position) {
    // Add your code here
    unsigned int b;
    int i = 0;
    int max = 0;
    int j= 0;
    for (i = 0; i < 32 && (b = (1<<i)); i++ ) {
        if (b & bitmap) {
            j++;
        } else {
            if (j > max) {
                max = j;
                *position = i - j;
                j = 0;
            } else {
                j = 0;
            }
        }
    }
    
    
    return max;
    
}

unsigned int inverse_bits(unsigned int num) {
    unsigned int b;
    int i;
    int j = 0;
    for (i = 31; i>=0 && (b = (1<<i)); i--) {
        if (b & num) {
            j = 1;
        }
        
        
        if (j) {
            if (b & num) {
                *(&num) = *(&num) & ~b;
            } else {
                *(&num) = *(&num) | b;
            }
        }
    }
    return num;
    
    //return (num ^ (-1<<num));

}



int find_sequence(unsigned int num, unsigned int pattern) {
    unsigned int b;
    int i = 31;
    char *n = malloc(32 * sizeof(char));
    char *m = malloc(32 * sizeof(char));
    char * p = m;
    char * q = n;
    int f = 0;

    for (i = 31;i>= 0 && (b=(1<<i)); i-- ) {
        if (f || (num & b)) {
            f = 1;
            if (num & b) {
                *p = '1';
                p++;
            } else {
                *p = '0';
                p++;
            }
        }
        
        
    }
    
    f = 0;
    
    for (i = 31;i>= 0 && (b=(1<<i)); i-- ) {
        if (f || (pattern & b)) {
            f = 1;
            if (pattern & b) {
                *q = '1';
                q++;
            } else {
                *q = '0';
                q++;
            }
        }
        
        
    }
    
    puts(m);
    puts(n);
    
    int j;
    for (i = (int)strlen(m) - 1; i >= 0; i--) {
        int l = 0;
        if (m[i] != n[0]) {
            
        } else {
            for (j = 0; j < strlen(n); j++) {
                if (m[i + j] == n[j]) {
                    l = 1;
                } else {
                    l = 0;
                    break;
                }
            }
            
            if (l) {
                return (int)(strlen(m) - strlen(n) - i);
            }
        }
    }
    return -1;
    
    
}
