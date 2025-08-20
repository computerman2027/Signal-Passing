	.file	"p4.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"\nReceived SIGUSR1 signal! Continuing..."
	.text
	.globl	handle_sigusr1
	.type	handle_sigusr1, @function
handle_sigusr1:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	handle_sigusr1, .-handle_sigusr1
	.section	.rodata
	.align 8
.LC1:
	.string	"\nReceived SIGINT signal! Continuing..."
	.text
	.globl	handle_sigint
	.type	handle_sigint, @function
handle_sigint:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	handle_sigint, .-handle_sigint
	.section	.rodata
	.align 8
.LC2:
	.string	"\nKilling the process by SIGKILL"
	.text
	.globl	handle_sigkill
	.type	handle_sigkill, @function
handle_sigkill:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %edi
	call	exit@PLT
	.cfi_endproc
.LFE8:
	.size	handle_sigkill, .-handle_sigkill
	.section	.rodata
.LC3:
	.string	"Process Id : %d\n"
.LC4:
	.string	"Thank You"
.LC5:
	.string	"\r                      "
.LC6:
	.string	"\r%s"
	.text
	.globl	main
	.type	main, @function
main:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	leaq	handle_sigusr1(%rip), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	signal@PLT
	leaq	handle_sigint(%rip), %rax
	movq	%rax, %rsi
	movl	$2, %edi
	call	signal@PLT
	leaq	handle_sigkill(%rip), %rax
	movq	%rax, %rsi
	movl	$9, %edi
	call	signal@PLT
	call	getpid@PLT
	movl	%eax, %esi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC4(%rip), %rax
	movq	%rax, -16(%rbp)
.L7:
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	stdout(%rip), %rax
	movq	%rax, %rdi
	call	fflush@PLT
	movl	$1, %edi
	call	sleep@PLT
	movl	$0, -4(%rbp)
	jmp	.L5
.L6:
	movl	$46, %edi
	call	putchar@PLT
	movq	stdout(%rip), %rax
	movq	%rax, %rdi
	call	fflush@PLT
	movl	$1, %edi
	call	sleep@PLT
	addl	$1, -4(%rbp)
.L5:
	cmpl	$2, -4(%rbp)
	jle	.L6
	jmp	.L7
	.cfi_endproc
.LFE9:
	.size	main, .-main
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
