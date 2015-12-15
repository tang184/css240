//
//  mystring.c
//  mystring
//
//  Created by tang184 on 15-8-31.
//  Copyright (c) 2015年 tang184. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystring.h"
#include <ctype.h>

// Type "man string" to see what every function expects.

int mystrlen(char * s) {
    int len = 0;
    while(*s != 0) {
        s++;
        len++;
    }
    return len;
}

char * mystrcpy(char * dest, char * src) {
    char*a = dest;
    while (*src != 0) {
        *a++ = *src++;
    }
    *a = 0;
    return dest;
    
}

char * mystrcat(char * dest, char * src) {
    if ((strlen(dest) + strlen(src)) > 20) {
        dest = realloc(dest, 200 * sizeof(char));
    }
    char *a = dest;
    char *b = src;
    while (*a) {
        a++;
    }
    
    while (*b) {
        *a = *b;
        a++;
        b++;
    }
    
    *a = '\0';
    return dest;
}

int mystrcmp(char * s1, char * s2) {
    char * a = char *s1;
    char * b = char *s2;
    while (*a != '\0' && *b != '\0') {
        if (*a > *b) {
            return 1;
        }
        if (*a < *b) {
            return -1;
        }
        a++;
        b++;
    }

    if (*a != '\0' && *b == '\0') {
        return 1;
    }

    if (*a == '\0' && *b != '\0') {
        return -1;
    }

    return 0;
}

char * mystrstr(char * hay, char * needle) {
    if (needle == NULL || hay == NULL) {
        return NULL;
    }
    int i = 0;
    while (hay[i] != '\0') {
        
        if (hay[i] == needle[0]) {
            int j = 0;
            while (needle[j] != '\0') {
                if (hay[i + j] != needle[j]) {
                    j++;
                    break;
                } else {
                    j++;
                }
            
            }
            if (needle[j] == '\0' && hay[i + j - 1] == needle[j - 1]) {
                return &hay[i];
            }
            
        }
        i++;
        
    }
    return "NULL";
}


char * mystrdup(char * s) {
    char * des;
    des = (char*)malloc(mystrlen(s) + 1);
    int i = 0;
    while (s[i] != '\0') {
        des[i] = s[i];
        i++;
    }
    des[i] = '\0';
    return (char*)des;
}

char * mymemcpy(char * dest, char * src, int count)
{
    if (dest!=NULL && src!=NULL) {
        char* tmp=dest;
        char* s=src;
        int i = 0;
        for(i=0;i < count;i++)
        {
            tmp[i]=s[i];
        }
        return dest;
    } else {
        return NULL;
    }
    
    
}

void reverse_str (char * str ) {
    char *a = str;
    int i = 0;
    while (*a != 0) {
        a++;
        i++;
    }
    a--;
    char *b = str;
    int j = 0;
    char m;
    char n;
    for (j = 0; j < i/2; j++) {
        m = *a;
        n = *b;
        *a = n;
        *b = m;
        a--;
        b++;
    }

    
}

int is_permutation(char *str, char* src) {
    if (strlen(str) != strlen(src)) {
        return 0;
    }
    
    char *a = str;
    char *b;
    int i = 0;
    while (*a != 0) {
        i = 0;
        b = src;
        while (*b != 0) {
            
            if (*b == *a) {
                i = 1;
            }
            b++;
        }
        if (i == 0) {
            return 0;
        }
        a++;
    }
    return i;
}

int my_strcspn(char *str, char* src) {
   int i = 0;
    int j = 0;
    char * a = str;
    while (*a != 0) {
        j = 0;
        char * b = src;
        while (*b != 0) {
            if (*a == *b) {
                j = 1;
            }
            b++;
        }
        if (j == 1) {
            return i;
        }
        i++;
        a++;
    }
    return 0;
    
}

char * ithword(char * str, int i) {
    char * a = str;
    char *t = malloc (50 * sizeof(char));
    char * m = t;
    int j = 0;
    while (*a != 0) {
        if (isalpha(*a) || isdigit(*a)) {
            a++;
        } else {
            while (!isalpha(*a) && !isdigit(*a)) {
                a++;
            }
            j++;
            
            if (j == i) {
                while (isalpha(*a) || isdigit(*a)) {
                    *m = *a;
                    m++;
                    a++;
                }
                break;
            }
        }
    }
    return t;
}