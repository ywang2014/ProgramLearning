	.file	"namesp.cpp"
.lcomm __ZStL8__ioinit,1,1
	.section .rdata,"dr"
LC0:
	.ascii "Enter first name: \0"
LC1:
	.ascii "Enter last name: \0"
	.text
	.globl	__ZN4pers9getPersonERNS_6PersonE
	.def	__ZN4pers9getPersonERNS_6PersonE;	.scl	2;	.type	32;	.endef
__ZN4pers9getPersonERNS_6PersonE:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	8(%ebp), %eax
	addl	$4, %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E
	leave
	ret
	.section .rdata,"dr"
LC2:
	.ascii "First name: \0"
LC3:
	.ascii " Last name: \0"
	.text
	.globl	__ZN4pers10showPersonERKNS_6PersonE
	.def	__ZN4pers10showPersonERKNS_6PersonE;	.scl	2;	.type	32;	.endef
__ZN4pers10showPersonERKNS_6PersonE:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	movl	8(%ebp), %eax
	leal	4(%eax), %esi
	movl	8(%ebp), %ebx
	movl	$LC2, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	movl	$LC3, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%esi, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.section .rdata,"dr"
LC4:
	.ascii "Enter debt: \0"
	.text
	.globl	__ZN5debts7getDebtERNS_4DebtE
	.def	__ZN5debts7getDebtERNS_4DebtE;	.scl	2;	.type	32;	.endef
__ZN5debts7getDebtERNS_4DebtE:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN4pers9getPersonERNS_6PersonE
	movl	$LC4, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	8(%ebp), %eax
	addl	$8, %eax
	movl	%eax, (%esp)
	movl	$__ZSt3cin, %ecx
	call	__ZNSirsERd
	subl	$4, %esp
	leave
	ret
	.section .rdata,"dr"
LC5:
	.ascii ": $\0"
	.text
	.globl	__ZN5debts8showDebtERKNS_4DebtE
	.def	__ZN5debts8showDebtERKNS_4DebtE;	.scl	2;	.type	32;	.endef
__ZN5debts8showDebtERKNS_4DebtE:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZN4pers10showPersonERKNS_6PersonE
	movl	8(%ebp), %eax
	movl	8(%eax), %ebx
	movl	12(%eax), %esi
	movl	$LC5, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, (%esp)
	movl	%esi, 4(%esp)
	movl	%eax, %ecx
	call	__ZNSolsEd
	subl	$8, %esp
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	leal	-8(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.globl	__ZN5debts8sumDebtsEPKNS_4DebtEi
	.def	__ZN5debts8sumDebtsEPKNS_4DebtEi;	.scl	2;	.type	32;	.endef
__ZN5debts8sumDebtsEPKNS_4DebtEi:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$0, %eax
	movl	$0, %edx
	movl	%eax, -8(%ebp)
	movl	%edx, -4(%ebp)
	movl	$0, -12(%ebp)
	jmp	L6
L7:
	movl	-12(%ebp), %eax
	movl	%eax, %edx
	sall	$4, %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	fldl	8(%eax)
	fldl	-8(%ebp)
	faddp	%st, %st(1)
	fstpl	-8(%ebp)
	incl	-12(%ebp)
L6:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	setl	%al
	testb	%al, %al
	jne	L7
	movl	-8(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	fldl	-24(%ebp)
	leave
	ret
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	ret
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L10
	cmpl	$65535, 12(%ebp)
	jne	L10
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L10:
	leave
	ret
	.def	__GLOBAL__sub_I__ZN4pers9getPersonERNS_6PersonE;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__ZN4pers9getPersonERNS_6PersonE:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	ret
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__ZN4pers9getPersonERNS_6PersonE
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RSbIS4_S5_T1_E;	.scl	2;	.type	32;	.endef
	.def	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSirsERd;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEd;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
