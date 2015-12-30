	.file	"hw4.c"
	.text
.Ltext0:
	.globl	printnum
	.type	printnum, @function
printnum:
.LFB40:
	.file 1 "hw4.c"
	.loc 1 44 0
	.cfi_startproc
.LVL0:
	pushl	%esi
	.cfi_def_cfa_offset 8
	.cfi_offset 6, -8
	pushl	%ebx
	.cfi_def_cfa_offset 12
	.cfi_offset 3, -12
	subl	$36, %esp
	.cfi_def_cfa_offset 48
	movl	48(%esp), %edx
	.loc 1 44 0
	movl	%gs:20, %eax
	movl	%eax, 28(%esp)
	xorl	%eax, %eax
.LVL1:
	.loc 1 47 0
	testl	%edx, %edx
	je	.L1
	leal	20(%esp), %ecx
	.loc 1 46 0
	movl	$0, %esi
.LVL2:
.L20:
.LBB19:
	.loc 1 49 0
	movl	%edx, %eax
	andl	$15, %eax
.LVL3:
	.loc 1 50 0
	shrl	$4, %edx
.LVL4:
	movl	%edx, %ebx
.LVL5:
	.loc 1 51 0
	cmpl	$15, %eax
	jne	.L3
	.loc 1 53 0
	movb	$102, (%ecx)
	jmp	.L4
.L3:
	.loc 1 55 0
	cmpl	$14, %eax
	jne	.L5
	.loc 1 57 0
	movb	$101, (%ecx)
	.p2align 4,,2
	jmp	.L4
.L5:
	.loc 1 59 0
	cmpl	$13, %eax
	.p2align 4,,2
	jne	.L6
	.loc 1 61 0
	movb	$100, (%ecx)
	.p2align 4,,2
	jmp	.L4
.L6:
	.loc 1 63 0
	cmpl	$12, %eax
	.p2align 4,,2
	jne	.L7
	.loc 1 65 0
	movb	$99, (%ecx)
	.p2align 4,,2
	jmp	.L4
.L7:
	.loc 1 67 0
	cmpl	$11, %eax
	.p2align 4,,2
	jne	.L8
	.loc 1 69 0
	movb	$98, (%ecx)
	.p2align 4,,2
	jmp	.L4
.L8:
	.loc 1 71 0
	cmpl	$10, %eax
	.p2align 4,,2
	jne	.L9
	.loc 1 73 0
	movb	$97, (%ecx)
	.p2align 4,,2
	jmp	.L4
.L9:
	.loc 1 75 0
	cmpl	$9, %eax
	.p2align 4,,2
	jne	.L10
	.loc 1 77 0
	movb	$57, (%ecx)
	.p2align 4,,2
	jmp	.L4
.L10:
	.loc 1 79 0
	cmpl	$8, %eax
	.p2align 4,,2
	jne	.L11
	.loc 1 81 0
	movb	$56, (%ecx)
	.p2align 4,,2
	jmp	.L4
.L11:
	.loc 1 83 0
	cmpl	$7, %eax
	.p2align 4,,2
	jne	.L12
	.loc 1 85 0
	movb	$55, (%ecx)
	.p2align 4,,2
	jmp	.L4
.L12:
	.loc 1 87 0
	cmpl	$6, %eax
	.p2align 4,,2
	jne	.L13
	.loc 1 89 0
	movb	$54, (%ecx)
	.p2align 4,,2
	jmp	.L4
.L13:
	.loc 1 91 0
	cmpl	$5, %eax
	.p2align 4,,2
	jne	.L14
	.loc 1 93 0
	movb	$53, (%ecx)
	.p2align 4,,2
	jmp	.L4
.L14:
	.loc 1 95 0
	cmpl	$4, %eax
	.p2align 4,,2
	jne	.L15
	.loc 1 97 0
	movb	$52, (%ecx)
	.p2align 4,,2
	jmp	.L4
.L15:
	.loc 1 99 0
	cmpl	$3, %eax
	.p2align 4,,2
	jne	.L16
	.loc 1 101 0
	movb	$51, (%ecx)
	.p2align 4,,2
	jmp	.L4
.L16:
	.loc 1 103 0
	cmpl	$2, %eax
	.p2align 4,,2
	jne	.L17
	.loc 1 105 0
	movb	$50, (%ecx)
	.p2align 4,,2
	jmp	.L4
.L17:
	.loc 1 107 0
	cmpl	$1, %eax
	.p2align 4,,2
	jne	.L18
	.loc 1 109 0
	movb	$49, (%ecx)
	.p2align 4,,2
	jmp	.L4
.L18:
	.loc 1 111 0
	testl	%eax, %eax
	.p2align 4,,3
	jne	.L4
	.loc 1 113 0
	movb	$48, (%ecx)
.L4:
	.loc 1 115 0
	leal	1(%esi), %eax
.LVL6:
	addl	$1, %ecx
.LBE19:
	.loc 1 47 0
	testl	%ebx, %ebx
	je	.L19
.LBB20:
	.loc 1 115 0
	movl	%eax, %esi
	jmp	.L20
.L19:
.LVL7:
.LBE20:
	.loc 1 118 0
	testl	%esi, %esi
	js	.L1
	leal	20(%esp,%esi), %ebx
	leal	19(%esp), %esi
.LVL8:
.L21:
.LBB21:
.LBB22:
	.file 2 "/usr/include/bits/stdio.h"
	.loc 2 81 0
	movl	stdout, %eax
	movl	%eax, 4(%esp)
.LVL9:
.LBE22:
.LBE21:
	.loc 1 120 0
	movsbl	(%ebx), %eax
	movl	%eax, (%esp)
.LBB24:
.LBB23:
	.loc 2 81 0
	call	_IO_putc
.LVL10:
	subl	$1, %ebx
.LVL11:
.LBE23:
.LBE24:
	.loc 1 118 0
	cmpl	%esi, %ebx
	jne	.L21
.LVL12:
.L1:
	.loc 1 123 0
	movl	28(%esp), %eax
	xorl	%gs:20, %eax
	je	.L22
	call	__stack_chk_fail
.LVL13:
.L22:
	addl	$36, %esp
	.cfi_def_cfa_offset 12
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 8
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 4
	.p2align 4,,1
	ret
	.cfi_endproc
.LFE40:
	.size	printnum, .-printnum
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"foo called with args"
.LC1:
	.string	"a: "
.LC2:
	.string	"b: "
.LC3:
	.string	"c :"
	.text
	.globl	recover
	.type	recover, @function
recover:
.LFB39:
	.loc 1 14 0
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subl	$32, %esp
	.cfi_def_cfa_offset 48
	.loc 1 16 0
	leal	112(%esp), %eax
	movl	%eax, 28(%esp)
	.loc 1 17 0
	movl	124(%esp), %edi
.LVL14:
	.loc 1 19 0
	movl	%edi, %ebx
	sall	$6, %ebx
	addl	%eax, %ebx
.LVL15:
	.loc 1 21 0
	addl	$1, %edi
.LVL16:
	testl	%edi, %edi
	jle	.L24
	.loc 1 20 0
	movl	$0, %esi
.LVL17:
.L26:
.LBB25:
.LBB26:
	.file 3 "/usr/include/bits/stdio2.h"
	.loc 3 104 0
	movl	$.LC0, (%esp)
	call	puts
.LVL18:
.LBE26:
.LBE25:
.LBB27:
.LBB28:
	movl	$.LC1, 4(%esp)
	movl	$1, (%esp)
	call	__printf_chk
.LVL19:
.LBE28:
.LBE27:
	.loc 1 25 0
	movl	(%ebx), %eax
	movl	%eax, (%esp)
	call	printnum
.LVL20:
.LBB29:
.LBB30:
	.loc 2 81 0
	movl	stdout, %eax
	movl	%eax, 4(%esp)
	movl	$10, (%esp)
	call	_IO_putc
.LVL21:
.LBE30:
.LBE29:
.LBB31:
.LBB32:
	.loc 3 104 0
	movl	$.LC2, 4(%esp)
	movl	$1, (%esp)
	call	__printf_chk
.LVL22:
.LBE32:
.LBE31:
	.loc 1 28 0
	movl	4(%ebx), %eax
	movl	%eax, (%esp)
	call	printnum
.LVL23:
.LBB33:
.LBB34:
	.loc 2 81 0
	movl	stdout, %eax
	movl	%eax, 4(%esp)
	movl	$10, (%esp)
	call	_IO_putc
.LVL24:
.LBE34:
.LBE33:
.LBB35:
.LBB36:
	.loc 3 104 0
	movl	$.LC3, 4(%esp)
	movl	$1, (%esp)
	call	__printf_chk
.LVL25:
.LBE36:
.LBE35:
	.loc 1 31 0
	movl	8(%ebx), %eax
	movl	%eax, (%esp)
	call	printnum
.LVL26:
.LBB37:
.LBB38:
	.loc 2 81 0
	movl	stdout, %eax
	movl	%eax, 4(%esp)
	movl	$10, (%esp)
	call	_IO_putc
.LVL27:
.LBE38:
.LBE37:
	.loc 1 33 0
	subl	$64, %ebx
.LVL28:
	.loc 1 21 0
	addl	$1, %esi
.LVL29:
	cmpl	%edi, %esi
	jne	.L26
.LVL30:
.L24:
	.loc 1 35 0
	addl	$32, %esp
	.cfi_def_cfa_offset 16
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
.LVL31:
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
.LVL32:
	ret
	.cfi_endproc
.LFE39:
	.size	recover, .-recover
.Letext0:
	.file 4 "/usr/lib/gcc/x86_64-linux-gnu/4.8/include/stddef.h"
	.file 5 "/usr/include/bits/types.h"
	.file 6 "/usr/include/libio.h"
	.file 7 "/usr/include/stdio.h"
	.file 8 "<built-in>"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x5b1
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.long	.LASF61
	.byte	0x1
	.long	.LASF62
	.long	.LASF63
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
	.long	.LASF64
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
	.uleb128 0xd
	.long	.LASF44
	.byte	0x6
	.value	0x13b
	.long	0xad
	.uleb128 0x6
	.byte	0x4
	.long	0x2a9
	.uleb128 0xe
	.long	0xa6
	.uleb128 0x6
	.byte	0x4
	.long	0x5a
	.uleb128 0xb
	.long	0xa6
	.long	0x2c4
	.uleb128 0xc
	.long	0x97
	.byte	0x7
	.byte	0
	.uleb128 0xf
	.long	.LASF58
	.byte	0x2
	.byte	0x4f
	.long	0x5a
	.byte	0x3
	.long	0x2e0
	.uleb128 0x10
	.string	"__c"
	.byte	0x2
	.byte	0x4f
	.long	0x5a
	.byte	0
	.uleb128 0x11
	.long	.LASF52
	.byte	0x3
	.byte	0x66
	.long	0x5a
	.byte	0x3
	.long	0x2fd
	.uleb128 0x12
	.long	.LASF49
	.byte	0x3
	.byte	0x66
	.long	0x2a3
	.uleb128 0x13
	.byte	0
	.uleb128 0x14
	.long	.LASF65
	.byte	0x1
	.byte	0x2b
	.long	.LFB40
	.long	.LFE40-.LFB40
	.uleb128 0x1
	.byte	0x9c
	.long	0x385
	.uleb128 0x15
	.string	"num"
	.byte	0x1
	.byte	0x2b
	.long	0x30
	.long	.LLST0
	.uleb128 0x16
	.long	.LASF50
	.byte	0x1
	.byte	0x2d
	.long	0x2b4
	.uleb128 0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x17
	.string	"i"
	.byte	0x1
	.byte	0x2e
	.long	0x5a
	.long	.LLST1
	.uleb128 0x18
	.long	.Ldebug_ranges0+0
	.long	0x355
	.uleb128 0x19
	.long	.LASF51
	.byte	0x1
	.byte	0x31
	.long	0x5a
	.long	.LLST2
	.byte	0
	.uleb128 0x1a
	.long	0x2c4
	.long	.LBB21
	.long	.Ldebug_ranges0+0x18
	.byte	0x1
	.byte	0x78
	.long	0x37b
	.uleb128 0x1b
	.long	0x2d4
	.long	.LLST3
	.uleb128 0x1c
	.long	.LVL10
	.long	0x55e
	.byte	0
	.uleb128 0x1c
	.long	.LVL13
	.long	0x57f
	.byte	0
	.uleb128 0x1d
	.long	.LASF53
	.byte	0x1
	.byte	0xd
	.long	.LFB39
	.long	.LFE39-.LFB39
	.uleb128 0x1
	.byte	0x9c
	.long	0x548
	.uleb128 0x16
	.long	.LASF54
	.byte	0x1
	.byte	0xf
	.long	0x2ae
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x19
	.long	.LASF55
	.byte	0x1
	.byte	0x11
	.long	0x5a
	.long	.LLST4
	.uleb128 0x17
	.string	"i"
	.byte	0x1
	.byte	0x12
	.long	0x5a
	.long	.LLST5
	.uleb128 0x17
	.string	"ptr"
	.byte	0x1
	.byte	0x13
	.long	0x2ae
	.long	.LLST6
	.uleb128 0x1e
	.long	0x2e0
	.long	.LBB25
	.long	.LBE25-.LBB25
	.byte	0x1
	.byte	0x17
	.long	0x400
	.uleb128 0x1f
	.long	0x2f0
	.uleb128 0x20
	.long	.LVL18
	.long	0x584
	.uleb128 0x21
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.uleb128 0x5
	.byte	0x3
	.long	.LC0
	.byte	0
	.byte	0
	.uleb128 0x1e
	.long	0x2e0
	.long	.LBB27
	.long	.LBE27-.LBB27
	.byte	0x1
	.byte	0x18
	.long	0x437
	.uleb128 0x1b
	.long	0x2f0
	.long	.LLST8
	.uleb128 0x20
	.long	.LVL19
	.long	0x59d
	.uleb128 0x21
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.uleb128 0x1
	.byte	0x31
	.uleb128 0x21
	.uleb128 0x2
	.byte	0x74
	.sleb128 4
	.uleb128 0x5
	.byte	0x3
	.long	.LC1
	.byte	0
	.byte	0
	.uleb128 0x1e
	.long	0x2c4
	.long	.LBB29
	.long	.LBE29-.LBB29
	.byte	0x1
	.byte	0x1a
	.long	0x464
	.uleb128 0x1b
	.long	0x2d4
	.long	.LLST9
	.uleb128 0x20
	.long	.LVL21
	.long	0x55e
	.uleb128 0x21
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.uleb128 0x1
	.byte	0x3a
	.byte	0
	.byte	0
	.uleb128 0x1e
	.long	0x2e0
	.long	.LBB31
	.long	.LBE31-.LBB31
	.byte	0x1
	.byte	0x1b
	.long	0x49b
	.uleb128 0x1b
	.long	0x2f0
	.long	.LLST10
	.uleb128 0x20
	.long	.LVL22
	.long	0x59d
	.uleb128 0x21
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.uleb128 0x1
	.byte	0x31
	.uleb128 0x21
	.uleb128 0x2
	.byte	0x74
	.sleb128 4
	.uleb128 0x5
	.byte	0x3
	.long	.LC2
	.byte	0
	.byte	0
	.uleb128 0x1e
	.long	0x2c4
	.long	.LBB33
	.long	.LBE33-.LBB33
	.byte	0x1
	.byte	0x1d
	.long	0x4c8
	.uleb128 0x1b
	.long	0x2d4
	.long	.LLST11
	.uleb128 0x20
	.long	.LVL24
	.long	0x55e
	.uleb128 0x21
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.uleb128 0x1
	.byte	0x3a
	.byte	0
	.byte	0
	.uleb128 0x1e
	.long	0x2e0
	.long	.LBB35
	.long	.LBE35-.LBB35
	.byte	0x1
	.byte	0x1e
	.long	0x4ff
	.uleb128 0x1b
	.long	0x2f0
	.long	.LLST12
	.uleb128 0x20
	.long	.LVL25
	.long	0x59d
	.uleb128 0x21
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.uleb128 0x1
	.byte	0x31
	.uleb128 0x21
	.uleb128 0x2
	.byte	0x74
	.sleb128 4
	.uleb128 0x5
	.byte	0x3
	.long	.LC3
	.byte	0
	.byte	0
	.uleb128 0x1e
	.long	0x2c4
	.long	.LBB37
	.long	.LBE37-.LBB37
	.byte	0x1
	.byte	0x20
	.long	0x52c
	.uleb128 0x1b
	.long	0x2d4
	.long	.LLST13
	.uleb128 0x20
	.long	.LVL27
	.long	0x55e
	.uleb128 0x21
	.uleb128 0x2
	.byte	0x74
	.sleb128 0
	.uleb128 0x1
	.byte	0x3a
	.byte	0
	.byte	0
	.uleb128 0x1c
	.long	.LVL20
	.long	0x2fd
	.uleb128 0x1c
	.long	.LVL23
	.long	0x2fd
	.uleb128 0x1c
	.long	.LVL26
	.long	0x2fd
	.byte	0
	.uleb128 0x22
	.long	.LASF56
	.byte	0x7
	.byte	0xa8
	.long	0x26b
	.uleb128 0x22
	.long	.LASF57
	.byte	0x7
	.byte	0xa9
	.long	0x26b
	.uleb128 0x23
	.long	.LASF59
	.byte	0x6
	.value	0x1b3
	.long	0x5a
	.long	0x579
	.uleb128 0x24
	.long	0x5a
	.uleb128 0x24
	.long	0x579
	.byte	0
	.uleb128 0x6
	.byte	0x4
	.long	0x297
	.uleb128 0x25
	.long	.LASF66
	.uleb128 0x26
	.long	.LASF60
	.byte	0x8
	.byte	0
	.long	.LASF67
	.long	0x5a
	.long	0x59d
	.uleb128 0x24
	.long	0x2a3
	.byte	0
	.uleb128 0x27
	.long	.LASF68
	.byte	0x3
	.byte	0x57
	.long	0x5a
	.uleb128 0x24
	.long	0x5a
	.uleb128 0x24
	.long	0x2a3
	.uleb128 0x13
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
	.uleb128 0x16
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
	.uleb128 0xe
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xf
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
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
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
	.uleb128 0x12
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
	.uleb128 0x13
	.uleb128 0x18
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x14
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
	.uleb128 0x15
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
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x16
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
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x17
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
	.uleb128 0x18
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x19
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
	.uleb128 0x1a
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x52
	.uleb128 0x1
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1b
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x1c
	.uleb128 0x4109
	.byte	0
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1d
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
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x21
	.uleb128 0x410a
	.byte	0
	.uleb128 0x2
	.uleb128 0x18
	.uleb128 0x2111
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x22
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
	.uleb128 0x23
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
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x24
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x25
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x34
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x26
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
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"",@progbits
.Ldebug_loc0:
.LLST0:
	.long	.LVL0-.Ltext0
	.long	.LVL1-.Ltext0
	.value	0x2
	.byte	0x91
	.sleb128 0
	.long	.LVL1-.Ltext0
	.long	.LVL4-.Ltext0
	.value	0x1
	.byte	0x52
	.long	.LVL5-.Ltext0
	.long	.LVL8-.Ltext0
	.value	0x1
	.byte	0x52
	.long	0
	.long	0
.LLST1:
	.long	.LVL1-.Ltext0
	.long	.LVL2-.Ltext0
	.value	0x2
	.byte	0x30
	.byte	0x9f
	.long	.LVL2-.Ltext0
	.long	.LVL6-.Ltext0
	.value	0x1
	.byte	0x56
	.long	.LVL6-.Ltext0
	.long	.LVL7-.Ltext0
	.value	0x1
	.byte	0x50
	.long	.LVL7-.Ltext0
	.long	.LVL8-.Ltext0
	.value	0x1
	.byte	0x56
	.long	.LVL8-.Ltext0
	.long	.LVL10-.Ltext0
	.value	0x8
	.byte	0x73
	.sleb128 0
	.byte	0x91
	.sleb128 0
	.byte	0x1c
	.byte	0x23
	.uleb128 0x1c
	.byte	0x9f
	.long	.LVL10-.Ltext0
	.long	.LVL11-.Ltext0
	.value	0x8
	.byte	0x73
	.sleb128 0
	.byte	0x91
	.sleb128 0
	.byte	0x1c
	.byte	0x23
	.uleb128 0x1b
	.byte	0x9f
	.long	.LVL11-.Ltext0
	.long	.LVL12-.Ltext0
	.value	0x8
	.byte	0x73
	.sleb128 0
	.byte	0x91
	.sleb128 0
	.byte	0x1c
	.byte	0x23
	.uleb128 0x1c
	.byte	0x9f
	.long	0
	.long	0
.LLST2:
	.long	.LVL3-.Ltext0
	.long	.LVL6-.Ltext0
	.value	0x1
	.byte	0x50
	.long	0
	.long	0
.LLST3:
	.long	.LVL8-.Ltext0
	.long	.LVL9-.Ltext0
	.value	0x9
	.byte	0x73
	.sleb128 0
	.byte	0x94
	.byte	0x1
	.byte	0x48
	.byte	0x24
	.byte	0x48
	.byte	0x26
	.byte	0x9f
	.long	0
	.long	0
.LLST4:
	.long	.LVL14-.Ltext0
	.long	.LVL16-.Ltext0
	.value	0x1
	.byte	0x57
	.long	.LVL16-.Ltext0
	.long	.LVL17-.Ltext0
	.value	0x3
	.byte	0x91
	.sleb128 76
	.long	.LVL17-.Ltext0
	.long	.LVL32-.Ltext0
	.value	0x3
	.byte	0x77
	.sleb128 -1
	.byte	0x9f
	.long	0
	.long	0
.LLST5:
	.long	.LVL14-.Ltext0
	.long	.LVL17-.Ltext0
	.value	0x2
	.byte	0x30
	.byte	0x9f
	.long	.LVL17-.Ltext0
	.long	.LVL30-.Ltext0
	.value	0x1
	.byte	0x56
	.long	0
	.long	0
.LLST6:
	.long	.LVL15-.Ltext0
	.long	.LVL31-.Ltext0
	.value	0x1
	.byte	0x53
	.long	0
	.long	0
.LLST8:
	.long	.LVL18-.Ltext0
	.long	.LVL30-.Ltext0
	.value	0x6
	.byte	0x3
	.long	.LC1
	.byte	0x9f
	.long	0
	.long	0
.LLST9:
	.long	.LVL20-.Ltext0
	.long	.LVL30-.Ltext0
	.value	0x2
	.byte	0x3a
	.byte	0x9f
	.long	0
	.long	0
.LLST10:
	.long	.LVL21-.Ltext0
	.long	.LVL30-.Ltext0
	.value	0x6
	.byte	0x3
	.long	.LC2
	.byte	0x9f
	.long	0
	.long	0
.LLST11:
	.long	.LVL23-.Ltext0
	.long	.LVL30-.Ltext0
	.value	0x2
	.byte	0x3a
	.byte	0x9f
	.long	0
	.long	0
.LLST12:
	.long	.LVL24-.Ltext0
	.long	.LVL30-.Ltext0
	.value	0x6
	.byte	0x3
	.long	.LC3
	.byte	0x9f
	.long	0
	.long	0
.LLST13:
	.long	.LVL26-.Ltext0
	.long	.LVL30-.Ltext0
	.value	0x2
	.byte	0x3a
	.byte	0x9f
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
	.section	.debug_ranges,"",@progbits
.Ldebug_ranges0:
	.long	.LBB19-.Ltext0
	.long	.LBE19-.Ltext0
	.long	.LBB20-.Ltext0
	.long	.LBE20-.Ltext0
	.long	0
	.long	0
	.long	.LBB21-.Ltext0
	.long	.LBE21-.Ltext0
	.long	.LBB24-.Ltext0
	.long	.LBE24-.Ltext0
	.long	0
	.long	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF52:
	.string	"printf"
.LASF10:
	.string	"__off_t"
.LASF16:
	.string	"_IO_read_ptr"
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
.LASF64:
	.string	"_IO_lock_t"
.LASF11:
	.string	"long int"
.LASF51:
	.string	"check"
.LASF15:
	.string	"_flags"
.LASF23:
	.string	"_IO_buf_end"
.LASF32:
	.string	"_cur_column"
.LASF58:
	.string	"putchar"
.LASF9:
	.string	"__quad_t"
.LASF68:
	.string	"__printf_chk"
.LASF31:
	.string	"_old_offset"
.LASF36:
	.string	"_offset"
.LASF50:
	.string	"array"
.LASF59:
	.string	"_IO_putc"
.LASF45:
	.string	"_IO_marker"
.LASF56:
	.string	"stdin"
.LASF63:
	.string	"/u/harsukh/CS201/Assign4"
.LASF3:
	.string	"long unsigned int"
.LASF20:
	.string	"_IO_write_ptr"
.LASF47:
	.string	"_sbuf"
.LASF2:
	.string	"short unsigned int"
.LASF61:
	.string	"GNU C 4.8.2 -m32 -mtune=generic -march=i686 -g -O1 -fstack-protector"
.LASF35:
	.string	"_lock"
.LASF30:
	.string	"_flags2"
.LASF42:
	.string	"_mode"
.LASF60:
	.string	"__builtin_puts"
.LASF57:
	.string	"stdout"
.LASF67:
	.string	"puts"
.LASF13:
	.string	"sizetype"
.LASF24:
	.string	"_IO_save_base"
.LASF21:
	.string	"_IO_write_end"
.LASF62:
	.string	"hw4.c"
.LASF55:
	.string	"countUp"
.LASF44:
	.string	"_IO_FILE"
.LASF53:
	.string	"recover"
.LASF48:
	.string	"_pos"
.LASF27:
	.string	"_markers"
.LASF1:
	.string	"unsigned char"
.LASF54:
	.string	"last_ptr"
.LASF5:
	.string	"short int"
.LASF33:
	.string	"_vtable_offset"
.LASF66:
	.string	"__stack_chk_fail"
.LASF14:
	.string	"char"
.LASF0:
	.string	"unsigned int"
.LASF65:
	.string	"printnum"
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
.LASF25:
	.string	"_IO_backup_base"
.LASF19:
	.string	"_IO_write_base"
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
