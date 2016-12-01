	.file	"main.c"
	.text
	.globl	conectar_irc
	.type	conectar_irc, @function
conectar_irc:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	%rdx, -40(%rbp)
	leaq	-16(%rbp), %rax
	movl	$16, %esi
	movq	%rax, %rdi
	call	bzero
	movw	$2, -16(%rbp)
	movl	-28(%rbp), %eax
	movzwl	%ax, %eax
	movl	%eax, %edi
	call	htons
	movw	%ax, -14(%rbp)
	movl	$0, %edx
	movl	$1, %esi
	movl	$2, %edi
	call	socket
	movl	%eax, %edx
	movq	-40(%rbp), %rax
	movl	%edx, (%rax)
	movq	-40(%rbp), %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	jns	.L2
	movl	$0, %eax
	jmp	.L6
.L2:
	leaq	-16(%rbp), %rax
	leaq	4(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$2, %edi
	movl	$0, %eax
	call	inet_pton
	testl	%eax, %eax
	jg	.L4
	movl	$0, %eax
	jmp	.L6
.L4:
	movq	-40(%rbp), %rax
	movl	(%rax), %eax
	leaq	-16(%rbp), %rcx
	movl	$16, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	connect
	testl	%eax, %eax
	jns	.L5
	movl	$0, %eax
	jmp	.L6
.L5:
	movl	$1, %eax
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	conectar_irc, .-conectar_irc
	.section	.rodata
.LC0:
	.string	"fim"
	.text
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
	subq	$32, %rsp
	movl	$1, -4(%rbp)
	movabsq	$3543824061332075314, %rax
	movq	%rax, -32(%rbp)
	movl	$825111605, -24(%rbp)
	movw	$12854, -20(%rbp)
	movb	$0, -18(%rbp)
.L8:
	leaq	-8(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movl	$6667, %esi
	movq	%rax, %rdi
	call	conectar_irc
	testl	%eax, %eax
	jne	.L9
	movl	$5, %edi
	call	sleep
	jmp	.L8
.L9:
	movl	$.LC0, %edi
	call	puts
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (GNU) 6.1.1 20160802"
	.section	.note.GNU-stack,"",@progbits
