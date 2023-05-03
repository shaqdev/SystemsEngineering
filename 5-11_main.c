//NEED TO FIX THE CODE: OUTPUT IS NOT CORRECT.

// Readlines from terminal
// Sort them using qsort ascending order
// Print sorted lines 

#include <stdio.h>
#include <string.h>

#define MAXLINES 10
#define MAXLENGTH 100

char *linesptr[MAXLINES];

char sLines[MAXLINES * MAXLENGTH];

int getlines(char *line, int maxlength) {
    int i = 0;
    char c;
    for (i = 0; (i < maxlength-1) && (c = getchar()) != EOF && (c != '\n'); i++) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i++] = 'c';
    }
    line[i] = '\0';
    
    return i;
}

int readlines(char *ptr[]) {
    int nlines = 0, len = 0, pos = 0, i=0;
    char line[MAXLENGTH], *sptr;
    while ((len = getlines(line, MAXLENGTH)) > 0) {
        sptr = strcpy(sLines+pos, line);
        sLines[len-1] = '\0';
        pos += len;
        linesptr[i++] = sptr;
    }
    return i;
}

void swap(int left, int right) {
    char *temp;
    temp = linesptr[left];
    linesptr[left] = linesptr[right];
    linesptr[right] = temp;
}

// It works on the principle of partition and sort
// Choose the pivot 
// Find the last position of pivot in every recursion
void qsort(char *lptr[], int left, int right) {
    // This will break the recurion: Check if there is only one element to sort
    if (left >= right)
        return;
    
    // Choose the middle element as pivot and move the pivot value to 0th place
    swap(left, (left + right)/2);
    
    // Now let's find the last position of the pivot
    int last = left;
    for (int i = left+1; i < right; i++) {
        if (strcmp(lptr[i], lptr[left]) < 0) {
            swap(i, ++last);    // Always retain the last index with the last known smallest value
        }
    }
    swap(left, last);
    qsort(lptr, left, last-1);
    qsort(lptr, last+1, right);
}

void writelines(char *lptr[], int lim) {
    while(--lim>=0)
        printf("%s\n",lptr[lim]);
}

int main(int argc, char *argv[]) {

    int nlines = readlines(linesptr);
    printf("Read %d lines\n",nlines);
    qsort(linesptr, 0, nlines-1);
    writelines(linesptr, nlines);

    return 0;
}