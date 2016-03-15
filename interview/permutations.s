	.file	"permutations.c"
	.comm	a,40,32
	.comm	book,10,8
	.comm	n,4,4
	.section	.rodata
.LC0:
	.string	"%3d"
	.text
	.globl	dfs
	.type	dfs, @function
dfs:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	n(%rip), %eax
	addl	$1, %eax
	cmpl	-20(%rbp), %eax
	jne	.L2
	movl	$0, -4(%rbp)
	jmp	.L3
.L4:
	movl	-4(%rbp), %eax
	cltq
	movl	a(,%rax,4), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
.L3:
	movl	-4(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L4
	movl	$10, %edi
	call	putchar
	jmp	.L9
.L2:
	movl	$1, -4(%rbp)
	jmp	.L6
.L8:
	movl	-4(%rbp), %eax
	cltq
	movzbl	book(%rax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	.L7
	movl	-4(%rbp), %eax
	cltq
	movb	$1, book(%rax)
	movl	-4(%rbp), %eax
	cltq
	movl	-20(%rbp), %edx
	movl	%edx, a(,%rax,4)
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %edi
	call	dfs
	movl	-4(%rbp), %eax
	cltq
	movb	$0, book(%rax)
.L7:
	addl	$1, -4(%rbp)
.L6:
	movl	n(%rip), %eax
	cmpl	%eax, -4(%rbp)
	jle	.L8
.L9:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	dfs, .-dfs
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$4, n(%rip)
	movl	$1, %edi
	call	dfs
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits
