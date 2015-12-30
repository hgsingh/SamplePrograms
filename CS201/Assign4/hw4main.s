	.file	"hw4main.c"
	.text
.Ltext0:
	.globl	foo
	.type	foo, @function
foo:
.LFB40:
	.file 1 "hw4main.c"
	.loc 1 25 0
	.cfi_startproc
.LVL0:
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	pushl	%edi
	.cfi_def_cfa_offset 12
	.cfi_offset 7, -12
	pushl	%esi
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushl	%ebx
	.cfi_def_cfa_offset 20
	.cfi_offset 3, -20
	subl	$44, %esp
	.cfi_def_cfa_offset 64
	movl	64(%esp), %ebx
	movl	68(%esp), %eax
	movl	72(%esp), %edx
	movl	80(%esp), %ecx
	.loc 1 27 0
	testl	%ecx, %ecx
	jne	.L2
	.loc 1 28 0
	call	recover
.LVL1:
	.loc 1 29 0
	movl	%ebx, %eax
	jmp	.L3
.L2:
	.loc 1 32 0
	leal	1(%ebx,%ebx), %esi
	leal	(%ebx,%ebx), %edi
	testl	%ebx, %ebx
	cmovns	%edi, %esi
.LVL2:
	.loc 1 38 0
	movswl	%ax, %edi
	addl	%edi, %edi
	.loc 1 35 0
	testw	%ax, %ax
	jns	.L7
	.loc 1 36 0
	movswl	%ax, %edi
	leal	1(%edi,%edi), %edi
.LVL3:
.L7:
	.loc 1 42 0
	movsbl	%dl, %ebp
	addl	%ebp, %ebp
	.loc 1 39 0
	testb	%dl, %dl
	jns	.L9
	.loc 1 40 0
	movsbl	%dl, %ebp
	leal	1(%ebp,%ebp), %ebp
.LVL4:
.L9:
	.loc 1 46 0
	subl	$1, %ecx
	movl	%ecx, 16(%esp)
	movl	76(%esp), %ecx
	addl	$1, %ecx
	movl	%ecx, 12(%esp)
	.loc 1 45 0
	movl	%ebp, %ecx
	xorl	%ebx, %ecx
.LVL5:
	.loc 1 46 0
	movsbl	%cl, %ebp
	movl	%ebp, 8(%esp)
	.loc 1 44 0
	movsbl	%dl, %edx
	xorl	%edx, %edi
.LVL6:
	.loc 1 46 0
	movswl	%di, %edi
.LVL7:
	movl	%edi, 4(%esp)
	.loc 1 43 0
	cwtl
	xorl	%eax, %esi
.LVL8:
	.loc 1 46 0
	movl	%esi, (%esp)
	call	foo
.LVL9:
	addl	%ebx, %eax
.LVL10:
.L3:
	.loc 1 47 0
	addl	$44, %esp
	.cfi_def_cfa_offset 20
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 12
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 8
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE40:
	.size	foo, .-foo
	.section	.rodata.str1.4,"aMS",@progbits,1
	.align 4
.LC0:
	.string	"Usage: program <int> <int> <int> <int>"
	.align 4
.LC1:
	.string	"main called with a = %d, b = %d, c = %d, countDown = %d\n"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC2:
	.string	"foo returns %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB39:
	.loc 1 7 0
	.cfi_startproc
.LVL11:
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$32, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	movl	12(%ebp), %esi
	.loc 1 11 0
	cmpl	$5, 8(%ebp)
	je	.L12
.LVL12:
.LBB16:
.LBB17:
	.file 2 "/usr/include/bits/stdio2.h"
	.loc 2 104 0
	movl	$.LC0, (%esp)
	call	puts
.LVL13:
.LBE17:
.LBE16:
	.loc 1 13 0
	movl	$-1, (%esp)
	call	exit
.LVL14:
.L12:
.LBB18:
.LBB19:
	.file 3 "/usr/include/stdlib.h"
	.loc 3 280 0
	movl	$10, 8(%esp)
.LVL15:
	movl	$0, 4(%esp)
	movl	4(%esi), %eax
	movl	%eax, (%esp)
	call	strtol
.LVL16:
	movl	%eax, 28(%esp)
.LVL17:
.LBE19:
.LBE18:
.LBB20:
.LBB21:
	movl	$10, 8(%esp)
.LVL18:
	movl	$0, 4(%esp)
	movl	8(%esi), %eax
	movl	%eax, (%esp)
	call	strtol
.LVL19:
	movl	%eax, 24(%esp)
.LVL20:
.LBE21:
.LBE20:
.LBB22:
.LBB23:
	movl	$10, 8(%esp)
.LVL21:
	movl	$0, 4(%esp)
	movl	12(%esi), %eax
	movl	%eax, (%esp)
	call	strtol
.LVL22:
	movl	%eax, %ebx
.LVL23:
.LBE23:
.LBE22:
.LBB24:
.LBB25:
	movl	$10, 8(%esp)
.LVL24:
	movl	$0, 4(%esp)
	movl	16(%esi), %eax
	movl	%eax, (%esp)
	call	strtol
.LVL25:
	movl	%eax, %edi
.LBE25:
.LBE24:
	.loc 1 19 0
	movsbl	%bl, %esi
	movswl	24(%esp), %ebx
.LVL26:
.LBB26:
.LBB27:
	.loc 2 104 0
	movl	%eax, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	28(%esp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC1, 4(%esp)
	movl	$1, (%esp)
	call	__printf_chk
.LVL27:
.LBE27:
.LBE26:
	.loc 1 20 0
	movl	%edi, 16(%esp)
	movl	$0, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	28(%esp), %eax
	movl	%eax, (%esp)
	call	foo
.LVL28:
.LBB28:
.LBB29:
	.loc 2 104 0
	movl	%eax, 8(%esp)
	movl	$.LC2, 4(%esp)
	movl	$1, (%esp)
	call	__printf_chk
.LVL29:
.LBE29:
.LBE28:
	.loc 1 23 0
	movl	$0, %eax
	leal	-12(%ebp), %esp
.LVL30:
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
.LVL31:
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
.LVL32:
	ret
	.cfi_endproc
.LFE39:
	.size	main, .-main
.Letext0:
	.file 4 "/usr/lib/gcc/x86_64-linux-gnu/4.8/include/stddef.h"
	.file 5 "/usr/include/bits/types.h"
	.file 6 "/usr/include/libio.h"
	.file 7 "/usr/include/stdio.h"
	.file 8 "<built-in>"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x65a
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.long	.LASF64
	.byte	0x1
	.long	.LASF65
	.long	.LASF66
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF8
	.byte	0x4
	.byte	0xd4
	.long	0x30
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF0
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.long	.LASF1
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.long	.LASF2
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF3
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF4
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.long	.LASF5
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF6
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF7
	.uleb128 0x2
	.long	.LASF9
	.byte	0x5
	.byte	0x37
	.long	0x61
	.uleb128 0x2
	.long	.LASF10
	.byte	0x5
	.byte	0x83
	.long	0x85
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.long	.LASF11
	.uleb128 0x2
	.long	.LASF12
	.byte	0x5
	.byte	0x84
	.long	0x6f
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF13
	.uleb128 0x5
	.byte	0x4
	.uleb128 0x6
	.byte	0x4
	.long	0xa6
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF14
	.uleb128 0x7
	.long	.LASF44
	.byte	0x94
	.byte	0x6
	.byte	0xf5
	.long	0x22d
	.uleb128 0x8
	.long	.LASF15
	.byte	0x6
	.byte	0xf6
	.long	0x5a
	.byte	0
	.uleb128 0x8
	.long	.LASF16
	.byte	0x6
	.byte	0xfb
	.long	0xa0
	.byte	0x4
	.uleb128 0x8
	.long	.LASF17
	.byte	0x6
	.byte	0xfc
	.long	0xa0
	.byte	0x8
	.uleb128 0x8
	.long	.LASF18
	.byte	0x6
	.byte	0xfd
	.long	0xa0
	.byte	0xc
	.uleb128 0x8
	.long	.LASF19
	.byte	0x6
	.byte	0xfe
	.long	0xa0
	.byte	0x10
	.uleb128 0x8
	.long	.LASF20
	.byte	0x6
	.byte	0xff
	.long	0xa0
	.byte	0x14
	.uleb128 0x9
	.long	.LASF21
	.byte	0x6
	.value	0x100
	.long	0xa0
	.byte	0x18
	.uleb128 0x9
	.long	.LASF22
	.byte	0x6
	.value	0x101
	.long	0xa0
	.byte	0x1c
	.uleb128 0x9
	.long	.LASF23
	.byte	0x6
	.value	0x102
	.long	0xa0
	.byte	0x20
	.uleb128 0x9
	.long	.LASF24
	.byte	0x6
	.value	0x104
	.long	0xa0
	.byte	0x24
	.uleb128 0x9
	.long	.LASF25
	.byte	0x6
	.value	0x105
	.long	0xa0
	.byte	0x28
	.uleb128 0x9
	.long	.LASF26
	.byte	0x6
	.value	0x106
	.long	0xa0
	.byte	0x2c
	.uleb128 0x9
	.long	.LASF27
	.byte	0x6
	.value	0x108
	.long	0x265
	.byte	0x30
	.uleb128 0x9
	.long	.LASF28
	.byte	0x6
	.value	0x10a
	.long	0x26b
	.byte	0x34
	.uleb128 0x9
	.long	.LASF29
	.byte	0x6
	.value	0x10c
	.long	0x5a
	.byte	0x38
	.uleb128 0x9
	.long	.LASF30
	.byte	0x6
	.value	0x110
	.long	0x5a
	.byte	0x3c
	.uleb128 0x9
	.long	.LASF31
	.byte	0x6
	.value	0x112
	.long	0x7a
	.byte	0x40
	.uleb128 0x9
	.long	.LASF32
	.byte	0x6
	.value	0x116
	.long	0x3e
	.byte	0x44
	.uleb128 0x9
	.long	.LASF33
	.byte	0x6
	.value	0x117
	.long	0x4c
	.byte	0x46
	.uleb128 0x9
	.long	.LASF34
	.byte	0x6
	.value	0x118
	.long	0x271
	.byte	0x47
	.uleb128 0x9
	.long	.LASF35
	.byte	0x6
	.value	0x11c
	.long	0x281
	.byte	0x48
	.uleb128 0x9
	.long	.LASF36
	.byte	0x6
	.value	0x125
	.long	0x8c
	.byte	0x4c
	.uleb128 0x9
	.long	.LASF37
	.byte	0x6
	.value	0x12e
	.long	0x9e
	.byte	0x54
	.uleb128 0x9
	.long	.LASF38
	.byte	0x6
	.value	0x12f
	.long	0x9e
	.byte	0x58
	.uleb128 0x9
	.long	.LASF39
	.byte	0x6
	.value	0x130
	.long	0x9e
	.byte	0x5c
	.uleb128 0x9
	.long	.LASF40
	.byte	0x6
	.value	0x131
	.long	0x9e
	.byte	0x60
	.uleb128 0x9
	.long	.LASF41
	.byte	0x6
	.value	0x132
	.long	0x25
	.byte	0x64
	.uleb128 0x9
	.long	.LASF42
	.byte	0x6
	.value	0x134
	.long	0x5a
	.byte	0x68
	.uleb128 0x9
	.long	.LASF43
	.byte	0x6
	.value	0x136
	.long	0x287
	.byte	0x6c
	.byte	0
	.uleb128 0xa
	.long	.LASF67
	.byte	0x6
	.byte	0x9a
	.uleb128 0x7
	.long	.LASF45
	.byte	0xc
	.byte	0x6
	.byte	0xa0
	.long	0x265
	.uleb128 0x8
	.long	.LASF46
	.byte	0x6
	.byte	0xa1
	.long	0x265
	.byte	0
	.uleb128 0x8
	.long	.LASF47
	.byte	0x6
	.byte	0xa2
	.long	0x26b
	.byte	0x4
	.uleb128 0x8
	.long	.LASF48
	.byte	0x6
	.byte	0xa6
	.long	0x5a
	.byte	0x8
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.long	0x234
	.uleb128 0x6
	.byte	0x4
	.long	0xad
	.uleb128 0xb
	.long	0xa6
	.long	0x281
	.uleb128 0xc
	.long	0x97
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.long	0x22d
	.uleb128 0xb
	.long	0xa6
	.long	0x297
	.uleb128 0xc
	.long	0x97
	.byte	0x27
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.long	0x29d
	.uleb128 0xd
	.long	0xa6
	.uleb128 0xe
	.long	.LASF59
	.byte	0x2
	.byte	0x66
	.long	0x5a
	.byte	0x3
	.long	0x2bf
	.uleb128 0xf
	.long	.LASF49
	.byte	0x2
	.byte	0x66
	.long	0x297
	.uleb128 0x10
	.byte	0
	.uleb128 0x11
	.long	.LASF61
	.byte	0x3
	.value	0x116
	.long	0x5a
	.byte	0x3
	.long	0x2dd
	.uleb128 0x12
	.long	.LASF50
	.byte	0x3
	.value	0x116
	.long	0x297
	.byte	0
	.uleb128 0x13
	.string	"foo"
	.byte	0x1
	.byte	0x19
	.long	0x5a
	.long	.LFB40
	.long	.LFE40-.LFB40
	.uleb128 0x1
	.byte	0x9c
	.long	0x39a
	.uleb128 0x14
	.string	"a"
	.byte	0x1
	.byte	0x19
	.long	0x5a
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x14
	.string	"b"
	.byte	0x1
	.byte	0x19
	.long	0x53
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x14
	.string	"c"
	.byte	0x1
	.byte	0x19
	.long	0xa6
	.uleb128 0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x15
	.long	.LASF51
	.byte	0x1
	.byte	0x19
	.long	0x5a
	.uleb128 0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x15
	.long	.LASF52
	.byte	0x1
	.byte	0x19
	.long	0x5a
	.uleb128 0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x16
	.string	"x"
	.byte	0x1
	.byte	0x1a
	.long	0x5a
	.long	.LLST0
	.uleb128 0x16
	.string	"y"
	.byte	0x1
	.byte	0x1a
	.long	0x5a
	.long	.LLST1
	.uleb128 0x16
	.string	"z"
	.byte	0x1
	.byte	0x1a
	.long	0x5a
	.long	.LLST2
	.uleb128 0x17
	.long	.LVL1
	.long	0x5f5
	.uleb128 0x18
	.long	.LVL9
	.long	0x2dd
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.uleb128 0x2
	.byte	0x76
	.sleb128 0
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 4
	.uleb128 0x2
	.byte	0x77
	.sleb128 0
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 8
	.uleb128 0x2
	.byte	0x75
	.sleb128 0
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 12
	.uleb128 0x5
	.byte	0x91
	.sleb128 12
	.byte	0x6
	.byte	0x23
	.uleb128 0x1
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 16
	.uleb128 0x5
	.byte	0x91
	.sleb128 16
	.byte	0x6
	.byte	0x31
	.byte	0x1c
	.byte	0
	.byte	0
	.uleb128 0x1a
	.long	.LASF53
	.byte	0x1
	.byte	0x7
	.long	0x5a
	.long	.LFB39
	.long	.LFE39-.LFB39
	.uleb128 0x1
	.byte	0x9c
	.long	0x5d9
	.uleb128 0x15
	.long	.LASF54
	.byte	0x1
	.byte	0x7
	.long	0x5a
	.uleb128 0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x15
	.long	.LASF55
	.byte	0x1
	.byte	0x7
	.long	0x5d9
	.uleb128 0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x1b
	.string	"a"
	.byte	0x1
	.byte	0x8
	.long	0x5a
	.uleb128 0x1c
	.long	.LASF52
	.byte	0x1
	.byte	0x8
	.long	0x5a
	.uleb128 0x1d
	.long	.LASF56
	.byte	0x1
	.byte	0x8
	.long	0x5a
	.long	.LLST3
	.uleb128 0x16
	.string	"b"
	.byte	0x1
	.byte	0x9
	.long	0x53
	.long	.LLST4
	.uleb128 0x16
	.string	"c"
	.byte	0x1
	.byte	0xa
	.long	0xa6
	.long	.LLST5
	.uleb128 0x1e
	.long	0x2a2
	.long	.LBB16
	.long	.LBE16-.LBB16
	.byte	0x1
	.byte	0xc
	.long	0x439
	.uleb128 0x1f
	.long	0x2b2
	.uleb128 0x18
	.long	.LVL13
	.long	0x5fc
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.uleb128 0x5
	.byte	0x3
	.long	.LC0
	.byte	0
	.byte	0
	.uleb128 0x1e
	.long	0x2bf
	.long	.LBB18
	.long	.LBE18-.LBB18
	.byte	0x1
	.byte	0xf
	.long	0x46c
	.uleb128 0x20
	.long	0x2d0
	.long	.LLST7
	.uleb128 0x18
	.long	.LVL16
	.long	0x615
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 4
	.uleb128 0x1
	.byte	0x30
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 8
	.uleb128 0x1
	.byte	0x3a
	.byte	0
	.byte	0
	.uleb128 0x1e
	.long	0x2bf
	.long	.LBB20
	.long	.LBE20-.LBB20
	.byte	0x1
	.byte	0x10
	.long	0x49f
	.uleb128 0x20
	.long	0x2d0
	.long	.LLST8
	.uleb128 0x18
	.long	.LVL19
	.long	0x615
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 4
	.uleb128 0x1
	.byte	0x30
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 8
	.uleb128 0x1
	.byte	0x3a
	.byte	0
	.byte	0
	.uleb128 0x1e
	.long	0x2bf
	.long	.LBB22
	.long	.LBE22-.LBB22
	.byte	0x1
	.byte	0x11
	.long	0x4d2
	.uleb128 0x20
	.long	0x2d0
	.long	.LLST9
	.uleb128 0x18
	.long	.LVL22
	.long	0x615
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 4
	.uleb128 0x1
	.byte	0x30
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 8
	.uleb128 0x1
	.byte	0x3a
	.byte	0
	.byte	0
	.uleb128 0x1e
	.long	0x2bf
	.long	.LBB24
	.long	.LBE24-.LBB24
	.byte	0x1
	.byte	0x12
	.long	0x505
	.uleb128 0x20
	.long	0x2d0
	.long	.LLST10
	.uleb128 0x18
	.long	.LVL25
	.long	0x615
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 4
	.uleb128 0x1
	.byte	0x30
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 8
	.uleb128 0x1
	.byte	0x3a
	.byte	0
	.byte	0
	.uleb128 0x1e
	.long	0x2a2
	.long	.LBB26
	.long	.LBE26-.LBB26
	.byte	0x1
	.byte	0x13
	.long	0x55c
	.uleb128 0x21
	.long	0x2b2
	.uleb128 0x6
	.byte	0x3
	.long	.LC1
	.byte	0x9f
	.uleb128 0x18
	.long	.LVL27
	.long	0x634
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.uleb128 0x1
	.byte	0x31
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 4
	.uleb128 0x5
	.byte	0x3
	.long	.LC1
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 8
	.uleb128 0x3
	.byte	0x74
	.sleb128 28
	.byte	0x6
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 12
	.uleb128 0x2
	.byte	0x73
	.sleb128 0
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 16
	.uleb128 0x2
	.byte	0x76
	.sleb128 0
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 20
	.uleb128 0x2
	.byte	0x77
	.sleb128 0
	.byte	0
	.byte	0
	.uleb128 0x1e
	.long	0x2a2
	.long	.LBB28
	.long	.LBE28-.LBB28
	.byte	0x1
	.byte	0x15
	.long	0x596
	.uleb128 0x21
	.long	0x2b2
	.uleb128 0x6
	.byte	0x3
	.long	.LC2
	.byte	0x9f
	.uleb128 0x18
	.long	.LVL29
	.long	0x634
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.uleb128 0x1
	.byte	0x31
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 4
	.uleb128 0x5
	.byte	0x3
	.long	.LC2
	.byte	0
	.byte	0
	.uleb128 0x22
	.long	.LVL14
	.long	0x64f
	.long	0x5ab
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.uleb128 0x2
	.byte	0x9
	.byte	0xff
	.byte	0
	.uleb128 0x18
	.long	.LVL28
	.long	0x2dd
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.uleb128 0x3
	.byte	0x74
	.sleb128 28
	.byte	0x6
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 4
	.uleb128 0x2
	.byte	0x73
	.sleb128 0
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 8
	.uleb128 0x2
	.byte	0x76
	.sleb128 0
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 12
	.uleb128 0x1
	.byte	0x30
	.uleb128 0x19
	.uleb128 0x2
	.byte	0x74
	.sleb128 16
	.uleb128 0x2
	.byte	0x77
	.sleb128 0
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.long	0xa0
	.uleb128 0x23
	.long	.LASF57
	.byte	0x7
	.byte	0xa8
	.long	0x26b
	.uleb128 0x23
	.long	.LASF58
	.byte	0x7
	.byte	0xa9
	.long	0x26b
	.uleb128 0x24
	.long	.LASF68
	.byte	0x1
	.byte	0x5
	.uleb128 0x25
	.long	.LASF60
	.byte	0x8
	.byte	0
	.long	.LASF69
	.long	0x5a
	.long	0x615
	.uleb128 0x26
	.long	0x297
	.byte	0
	.uleb128 0x27
	.long	.LASF62
	.byte	0x3
	.byte	0xb7
	.long	0x85
	.long	0x634
	.uleb128 0x26
	.long	0x297
	.uleb128 0x26
	.long	0x5d9
	.uleb128 0x26
	.long	0x5a
	.byte	0
	.uleb128 0x27
	.long	.LASF63
	.byte	0x2
	.byte	0x57
	.long	0x5a
	.long	0x64f
	.uleb128 0x26
	.long	0x5a
	.uleb128 0x26
	.long	0x297
	.uleb128 0x10
	.byte	0
	.uleb128 0x28
	.long	.LASF70
	.byte	0x3
	.value	0x21f
	.uleb128 0x26
	.long	0x5a
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x20
	.uleb128 0xb
	.uleb128 0x34
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x20
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x4109
	.byte	0
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x410a
	.byte	0
	.uleb128 0x2
	.uleb128 0x18
	.uleb128 0x2111
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x1a
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1b
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1c
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1d
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x1e
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x6
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1f
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x20
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x21
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x22
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x23
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x24
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x25
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x26
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x27
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x28
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"",@progbits
.Ldebug_loc0:
.LLST0:
	.long	.LVL2-.Ltext0
	.long	.LVL4-.Ltext0
	.value	0x1
	.byte	0x56
	.long	.LVL4-.Ltext0
	.long	.LVL8-.Ltext0
	.value	0xa
	.byte	0x70
	.sleb128 0
	.byte	0x40
	.byte	0x24
	.byte	0x40
	.byte	0x26
	.byte	0x76
	.sleb128 0
	.byte	0x27
	.byte	0x9f
	.long	.LVL8-.Ltext0
	.long	.LVL10-.Ltext0
	.value	0x1
	.byte	0x56
	.long	0
	.long	0
.LLST1:
	.long	.LVL3-.Ltext0
	.long	.LVL4-.Ltext0
	.value	0x1
	.byte	0x57
	.long	.LVL4-.Ltext0
	.long	.LVL6-.Ltext0
	.value	0xa
	.byte	0x72
	.sleb128 0
	.byte	0x48
	.byte	0x24
	.byte	0x48
	.byte	0x26
	.byte	0x77
	.sleb128 0
	.byte	0x27
	.byte	0x9f
	.long	.LVL6-.Ltext0
	.long	.LVL7-.Ltext0
	.value	0x1
	.byte	0x57
	.long	0
	.long	0
.LLST2:
	.long	.LVL4-.Ltext0
	.long	.LVL5-.Ltext0
	.value	0x6
	.byte	0x75
	.sleb128 0
	.byte	0x73
	.sleb128 0
	.byte	0x27
	.byte	0x9f
	.long	.LVL5-.Ltext0
	.long	.LVL9-1-.Ltext0
	.value	0x1
	.byte	0x51
	.long	0
	.long	0
.LLST3:
	.long	.LVL28-.Ltext0
	.long	.LVL29-1-.Ltext0
	.value	0x1
	.byte	0x50
	.long	0
	.long	0
.LLST4:
	.long	.LVL20-.Ltext0
	.long	.LVL30-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 24
	.long	.LVL30-.Ltext0
	.long	.LVL32-.Ltext0
	.value	0x7
	.byte	0x75
	.sleb128 -12
	.byte	0x9
	.byte	0xf0
	.byte	0x1a
	.byte	0x38
	.byte	0x1c
	.long	.LVL32-.Ltext0
	.long	.LFE39-.Ltext0
	.value	0x7
	.byte	0x74
	.sleb128 -16
	.byte	0x9
	.byte	0xf0
	.byte	0x1a
	.byte	0x38
	.byte	0x1c
	.long	0
	.long	0
.LLST5:
	.long	.LVL23-.Ltext0
	.long	.LVL26-.Ltext0
	.value	0x1
	.byte	0x53
	.long	.LVL26-.Ltext0
	.long	.LVL31-.Ltext0
	.value	0x1
	.byte	0x56
	.long	0
	.long	0
.LLST7:
	.long	.LVL14-.Ltext0
	.long	.LVL15-.Ltext0
	.value	0x2
	.byte	0x76
	.sleb128 4
	.long	0
	.long	0
.LLST8:
	.long	.LVL17-.Ltext0
	.long	.LVL18-.Ltext0
	.value	0x2
	.byte	0x76
	.sleb128 8
	.long	0
	.long	0
.LLST9:
	.long	.LVL20-.Ltext0
	.long	.LVL21-.Ltext0
	.value	0x2
	.byte	0x76
	.sleb128 12
	.long	0
	.long	0
.LLST10:
	.long	.LVL23-.Ltext0
	.long	.LVL24-.Ltext0
	.value	0x2
	.byte	0x76
	.sleb128 16
	.long	0
	.long	0
	.section	.debug_aranges,"",@progbits
	.long	0x1c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x4
	.byte	0
	.value	0
	.value	0
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	0
	.long	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF59:
	.string	"printf"
.LASF10:
	.string	"__off_t"
.LASF16:
	.string	"_IO_read_ptr"
.LASF56:
	.string	"retVal"
.LASF28:
	.string	"_chain"
.LASF8:
	.string	"size_t"
.LASF34:
	.string	"_shortbuf"
.LASF22:
	.string	"_IO_buf_base"
.LASF7:
	.string	"long long unsigned int"
.LASF6:
	.string	"long long int"
.LASF4:
	.string	"signed char"
.LASF29:
	.string	"_fileno"
.LASF17:
	.string	"_IO_read_end"
.LASF11:
	.string	"long int"
.LASF62:
	.string	"strtol"
.LASF15:
	.string	"_flags"
.LASF23:
	.string	"_IO_buf_end"
.LASF32:
	.string	"_cur_column"
.LASF9:
	.string	"__quad_t"
.LASF63:
	.string	"__printf_chk"
.LASF31:
	.string	"_old_offset"
.LASF36:
	.string	"_offset"
.LASF45:
	.string	"_IO_marker"
.LASF57:
	.string	"stdin"
.LASF66:
	.string	"/u/harsukh/CS201/Assign4"
.LASF3:
	.string	"long unsigned int"
.LASF20:
	.string	"_IO_write_ptr"
.LASF47:
	.string	"_sbuf"
.LASF2:
	.string	"short unsigned int"
.LASF64:
	.string	"GNU C 4.8.2 -m32 -mtune=generic -march=i686 -g -O1 -fstack-protector"
.LASF35:
	.string	"_lock"
.LASF30:
	.string	"_flags2"
.LASF42:
	.string	"_mode"
.LASF60:
	.string	"__builtin_puts"
.LASF58:
	.string	"stdout"
.LASF69:
	.string	"puts"
.LASF13:
	.string	"sizetype"
.LASF24:
	.string	"_IO_save_base"
.LASF21:
	.string	"_IO_write_end"
.LASF67:
	.string	"_IO_lock_t"
.LASF51:
	.string	"countUp"
.LASF44:
	.string	"_IO_FILE"
.LASF50:
	.string	"__nptr"
.LASF48:
	.string	"_pos"
.LASF27:
	.string	"_markers"
.LASF61:
	.string	"atoi"
.LASF1:
	.string	"unsigned char"
.LASF5:
	.string	"short int"
.LASF33:
	.string	"_vtable_offset"
.LASF70:
	.string	"exit"
.LASF14:
	.string	"char"
.LASF0:
	.string	"unsigned int"
.LASF68:
	.string	"recover"
.LASF46:
	.string	"_next"
.LASF12:
	.string	"__off64_t"
.LASF18:
	.string	"_IO_read_base"
.LASF26:
	.string	"_IO_save_end"
.LASF49:
	.string	"__fmt"
.LASF37:
	.string	"__pad1"
.LASF38:
	.string	"__pad2"
.LASF39:
	.string	"__pad3"
.LASF40:
	.string	"__pad4"
.LASF41:
	.string	"__pad5"
.LASF43:
	.string	"_unused2"
.LASF55:
	.string	"argv"
.LASF52:
	.string	"countDown"
.LASF25:
	.string	"_IO_backup_base"
.LASF54:
	.string	"argc"
.LASF65:
	.string	"hw4main.c"
.LASF53:
	.string	"main"
.LASF19:
	.string	"_IO_write_base"
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
