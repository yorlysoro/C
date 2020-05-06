	.file	"readwrite.c"
	.comm	mutex,32,32
	.comm	db,32,32
	.comm	rc,4,4
	.comm	ids,40,32
	.text
	.globl	start_thread
	.type	start_thread, @function
start_thread:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$80, %edi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, 64(%rax)
	movq	-8(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, 72(%rax)
	movq	-8(%rbp), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	call	pthread_attr_init@PLT
	movq	-8(%rbp), %rax
	movq	72(%rax), %rcx
	movq	-8(%rbp), %rax
	movq	64(%rax), %rdx
	movq	-8(%rbp), %rax
	leaq	8(%rax), %rsi
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	pthread_create@PLT
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	start_thread, .-start_thread
	.globl	down
	.type	down, @function
down:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	sem_wait@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	down, .-down
	.globl	up
	.type	up, @function
up:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	sem_post@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	up, .-up
	.section	.rodata
.LC0:
	.string	"Reader %d preparing to read\n"
.LC1:
	.string	"\tRead count is %d\n"
.LC2:
	.string	"Reader %d readin data\n"
.LC3:
	.string	"Reader %d using data read\n"
	.text
	.globl	reader
	.type	reader, @function
reader:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
.L8:
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	mutex(%rip), %rdi
	call	down
	movl	rc(%rip), %eax
	addl	$1, %eax
	movl	%eax, rc(%rip)
	movl	rc(%rip), %eax
	cmpl	$1, %eax
	jne	.L6
	leaq	db(%rip), %rdi
	call	down
.L6:
	movl	rc(%rip), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	mutex(%rip), %rdi
	call	up
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	call	rand@PLT
	movl	%eax, %ecx
	movl	$1431655766, %edx
	movl	%ecx, %eax
	imull	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	movl	%edx, %eax
	movl	%eax, %edi
	call	sleep@PLT
	leaq	mutex(%rip), %rdi
	call	down
	movl	rc(%rip), %eax
	subl	$1, %eax
	movl	%eax, rc(%rip)
	movl	rc(%rip), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	rc(%rip), %eax
	testl	%eax, %eax
	jne	.L7
	leaq	db(%rip), %rdi
	call	up
.L7:
	leaq	mutex(%rip), %rdi
	call	up
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	call	rand@PLT
	movl	%eax, %ecx
	movl	$1431655766, %edx
	movl	%ecx, %eax
	imull	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	movl	%edx, %eax
	movl	%eax, %edi
	call	sleep@PLT
	jmp	.L8
	.cfi_endproc
.LFE5:
	.size	reader, .-reader
	.section	.rodata
.LC4:
	.string	"Writer %d preparing to write\n"
.LC5:
	.string	"Writer %d is writing data\n"
	.align 8
.LC6:
	.string	"Writer %d has finished writing\n"
	.text
	.globl	writer
	.type	writer, @function
writer:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
.L10:
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	call	rand@PLT
	movl	%eax, %ecx
	movl	$1431655766, %edx
	movl	%ecx, %eax
	imull	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	movl	%edx, %eax
	movl	%eax, %edi
	call	sleep@PLT
	leaq	db(%rip), %rdi
	call	down
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	call	rand@PLT
	movl	%eax, %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	%edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	subl	%eax, %ecx
	movl	%ecx, %edx
	movl	%edx, %eax
	movl	%eax, %edi
	call	sleep@PLT
	leaq	db(%rip), %rdi
	call	up
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC6(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L10
	.cfi_endproc
.LFE6:
	.size	writer, .-writer
	.section	.rodata
.LC7:
	.string	"Main started"
.LC8:
	.string	"Main finished"
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	leaq	.LC7(%rip), %rdi
	call	puts@PLT
	movl	$0, -8(%rbp)
	movl	$0, -12(%rbp)
	movl	$0, rc(%rip)
	movl	$1, %edx
	movl	$0, %esi
	leaq	mutex(%rip), %rdi
	call	sem_init@PLT
	movl	$1, %edx
	movl	$0, %esi
	leaq	db(%rip), %rdi
	call	sem_init@PLT
	movl	$0, -4(%rbp)
	jmp	.L12
.L15:
	movl	-4(%rbp), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	.L13
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	leaq	ids(%rip), %rax
	movl	-12(%rbp), %edx
	movl	%edx, (%rcx,%rax)
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	ids(%rip), %rax
	addq	%rdx, %rax
	movq	%rax, %rsi
	leaq	reader(%rip), %rdi
	call	start_thread
	addl	$1, -12(%rbp)
	jmp	.L14
.L13:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	leaq	ids(%rip), %rax
	movl	-8(%rbp), %edx
	movl	%edx, (%rcx,%rax)
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	ids(%rip), %rax
	addq	%rdx, %rax
	movq	%rax, %rsi
	leaq	writer(%rip), %rdi
	call	start_thread
	addl	$1, -8(%rbp)
.L14:
	addl	$1, -4(%rbp)
.L12:
	cmpl	$9, -4(%rbp)
	jle	.L15
	movl	$10, %edi
	call	sleep@PLT
	leaq	.LC8(%rip), %rdi
	call	puts@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.ident	"GCC: (Debian 6.2.1-5) 6.2.1 20161124"
	.section	.note.GNU-stack,"",@progbits
