	.file	"3.11.c"
	.text
	.globl	instruction_encode
	.type	instruction_encode, @function
instruction_encode:
.LFB0:
	.cfi_startproc
	movl	$0, %eax
	xorl 	%eax, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	instruction_encode, .-instruction_encode
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
