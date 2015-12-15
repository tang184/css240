//
//  main.c
//  abcd
//
//  Created by tang184 on 15-8-30.
//  Copyright (c) 2015年 tang184. All rights reserved.
//

#include <stdio.h>
#define MAXLINE 1023 //define a marco
char line[MAXLINE+1]; //global variable
void mygrep(char * fileName, char * pattern); //forward definition (prototype)
int main(int argc, char **argv)
{
    char * fileName;
    char * pattern;
    // Check that there are at least 2 arguments
    // mygrep file pattern
    // argv[0] argv[1] argv[2]
    // argc == 3
    if (argc<3) {
        printf("Usage: mygrep pattern file\n");
        exit(1);
    }
    pattern = argv[1];
    fileName = argv[2];
    mygrep(fileName, pattern);
    exit(0);
}

void mygrep(char * fileName, char * pattern) {
    FILE * fd = fopen(fileName,"r");
    if (fd == NULL) {
        printf("Cannot open file %s\n", fileName);
        exit(1);
    }
    while(fgets(line, MAXLINE, fd)!= NULL) {
        if (strstr(line,pattern)!=NULL) {
            printf("%s", line);
        }
    }
    fclose(fd);
}
