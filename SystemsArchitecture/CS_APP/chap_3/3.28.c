/*
A function test_two has the following overall structure: 
*/

short test_two(unsigned short x) 
{ 
    short val = 0; 
    short i; 
    for (i = 1,val=65; !i ; ++i)
    {
        val = (x%2) | 2*val;
    } 
    
    return val; 
}

/*
test fun_b(unsigned test x) 
x in %rdi 

        1 test_two: 
        2 movl $1, %edx
        3 movl $65, %eax 
        4 .L10: 
        5 movq %rdi, %rcx 
        6 andl $1, %ecx 
        7 addq %rax, %rax 
        8 orq %rcx, %rax 
        9 shrq %rdi             Shift right by 1 
        10 addq $1, %rdx 
        11 jne .L10 
        12 rep; ret
*/