	.file	"stack_size_check.c"
	.text
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.text
	.p2align 4,,15
	.globl	proc
	.type	proc, @function
proc:
.LFB24:
	.cfi_startproc
	movq	16(%rsp), %rax
	addq	%rdi, (%rsi)
	addl	%edx, (%rcx)
	movl	8(%rsp), %edx
	addw	%r8w, (%r9)
	addb	%dl, (%rax)
	ret
	.cfi_endproc
.LFE24:
	.size	proc, .-proc
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
