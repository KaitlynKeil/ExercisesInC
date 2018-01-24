	.file	"hello.c"
	.section	.rodata
.LC0:
	.string	"Hello World, %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp // Makes space for a new variable
	movl	$5, -8(%rbp) // Optimization ignores this step
	movl	-8(%rbp), %eax
	addl	$1, %eax // I think this one takes what the last one was and adds 1, storing it in a new place
	movl	%eax, -4(%rbp) // Most of this does not run for optimized.
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf // Finally prints. This is a different print function in optimized
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
