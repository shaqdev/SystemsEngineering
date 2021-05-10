#include <stdio.h>

int main()
{
    int a = -5;
    // Switch performs multiway branching using integer index
    // Switch is implemented in machine code using a data structure
       // called JUMP TABLE 
    // GCC use jump table implementation of switch when there are four
        // or more cases and spanning a small range of values.
    switch(a)
    {
        case -4: // Do First 
                break;
        case -5: a *= 5;
                break;
        case -6: // Do Third
                break;
        case -7: //Do Fourth
                break;
        default: // Default case if none of the above happens
                // Default case cannot be empty
                ;

    }
    printf("'a' is %d\n",a);
    return 0;
}




