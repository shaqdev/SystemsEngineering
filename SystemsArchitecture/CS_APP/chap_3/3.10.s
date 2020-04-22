	.file	"3.10.c"
	.text
	.globl	arith3
	.type	arith3, @function
arith3:
.LFB0:
	.cfi_startproc
	orl	%esi, %edx
	sarw	$9, %dx
	notl	%edx
	movl	%esi, %eax
	subl	%edx, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	arith3, .-arith3
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
