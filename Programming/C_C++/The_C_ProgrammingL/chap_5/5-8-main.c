#include <stdio.h>


int main(int argc, char *argv[]) {
    // default initialization of an array
    // We have to iterate over the array and initialize each element
    // No concept of List initialization in 'C'
    int size=5, i;
    int arr[size];
    // while((i = (5-size--)) < 5)
    //     printf("Value at %d: %d\n", i, arr[i]);

    // Initializing pointer arrays
    // This will initialize the array pointers with pointers to the character strings
    // The actual character strings will be stored somewhere else
    char *ptr[5] = {"khaleel", "is", "a", "good", "boy"};
    while((i = (5-size--)) < 5)
        printf("Value at %d: %p\n", i, ptr[i]);    
return 0;
}