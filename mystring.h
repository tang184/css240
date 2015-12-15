//
//  mystring.h
//  mystring
//
//  Created by tang184 on 15-8-31.
//  Copyright (c) 2015年 tang184. All rights reserved.
//

#if !defined MYSTRING_H
#define MYSTRING_H

int mystrlen(char * s);
char * mystrcpy(char * dest, char * src);
char * mystrcat(char * dest, char * src);
int mystrcmp(char * s1, char * s2);
char * mystrstr(char * hay, char * needle);
char * mystrdup(char * s);
char * mymemcpy(char * dest, char * src, int n);
void reverse_str (char * str );
int is_permutation ( char * str1, char * str2 );
int my_strcspn( char * str, char * reject );
char * ithword(char * str, int i);
#endif

