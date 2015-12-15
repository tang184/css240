#include <stdio.h>
#define MAXLINE 1023 //define a marco
#include <string.h>

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
return 0;
}
pattern = argv[1];
fileName = argv[2];
mygrep(fileName, pattern);
return 0;
}

void mygrep(char * fileName, char * pattern) {
FILE * fd = fopen(fileName,"r");
if (fd == NULL) {
printf("Cannot open file %s\n", fileName);
return ;
}
while(fgets(line, MAXLINE, fd)!= NULL) {
if (strstr(line,pattern)!=NULL) {
printf("%s", line);
}
}
fclose(fd);
}