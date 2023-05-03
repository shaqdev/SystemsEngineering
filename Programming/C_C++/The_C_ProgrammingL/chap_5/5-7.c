#include <stdio.h>
#include <string.h>

#define MAXLINES 10
#define MAXLENGTH 100

int getlines(char *, int);
int readlines(char lines[1000], char *linesptr[MAXLINES]);

int main() {
    int nlines;
    char lines[MAXLENGTH * MAXLINES], *linesptr[MAXLINES];
    nlines = readlines(lines, linesptr);
    printf("no. of lines are: %d\n", nlines);
return 0;
}

int getlines(char *line, int len) {
    char ch;
    int i;
    for (i = 0; i < len && (ch = getchar()) != EOF && ch != '\n'; i++){
        line[i] = ch;
    } 
    if (ch == '\n') {
        line[i++] = ch;
    }
    line[i] = '\0';
    return i;
}

int readlines(char lines[], char *linesptr[]) {
    int nlines = 0, len = 0, pos = 0, i = 0;
    char line[100];
    while ((len = getlines(line, 100)) > 0) {
        strcpy(lines+pos, line);
        lines[len] = '\n';
        linesptr[i++] = lines + pos;
        pos += len + 1;
    }
    
    return i;
}