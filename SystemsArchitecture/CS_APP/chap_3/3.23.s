	.file	"3.23.c"
	.text
	.globl	dw_loop
	.type	dw_loop, @function
dw_loop:
.LFB0:
	.cfi_startproc
	movl	%edi, %eax
	movswl	%di, %ecx
	imull	$7282, %ecx, %ecx
	shrl	$16, %ecx
	movl	%edi, %edx
	sarw	$15, %dx
	subl	%edx, %ecx
	sall	$2, %edi
.L2:
	leal	5(%rcx,%rax), %eax
	leal	-2(%rdi), %edx
	movl	%edx, %edi
	testw	%dx, %dx
	jg	.L2
	rep ret
	.cfi_endproc
.LFE0:
	.size	dw_loop, .-dw_loop
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
