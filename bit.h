//
//  bit.h
//  mystring
//
//  Created by tang184 on 15/11/4.
//  Copyright © 2015年 tang184. All rights reserved.
//

#if !defined(BITS_H)
#define BITS_H
extern void setBitAt( unsigned int * bitmap, int i, int bitValue);
extern int getBitAt( unsigned int bitmap, unsigned int i);
extern int countBits( unsigned int bitmap, unsigned int bitValue);
extern int maxContinuousOnes(unsigned int bitmap, int * position);
extern void printBits(unsigned int bitmap);
extern unsigned int inverse_bits (unsigned int num);
extern int find_sequence (unsigned int num, unsigned int pattern);

#endif
 /* bit_h */
