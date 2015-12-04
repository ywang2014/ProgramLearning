	.file	"variadic.cpp"
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
.lcomm __ZStL8__ioinit,1,1
	.text
	.globl	__Z9show_listv
	.def	__Z9show_listv;	.scl	2;	.type	32;	.endef
__Z9show_listv:
	pushl	%ebp
	movl	%esp, %ebp
	popl	%ebp
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC1:
	.ascii "Hello, world!\0"
	.def	___gxx_personality_sj0;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Register;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Unregister;	.scl	2;	.type	32;	.endef
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	subl	$152, %esp
	movl	$___gxx_personality_sj0, -84(%ebp)
	movl	$LLSDA1116, -80(%ebp)
	leal	-76(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L8, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	call	___main
	movl	$1, -28(%ebp)
	movl	$1374389535, %eax
	movl	$1074339512, %edx
	movl	%eax, -40(%ebp)
	movl	%edx, -36(%ebp)
	movb	$1, -41(%ebp)
	leal	-49(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIcEC1Ev
	leal	-56(%ebp), %eax
	leal	-49(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	$LC1, (%esp)
	movl	$1, -104(%ebp)
	movl	%eax, %ecx
	call	__ZNSsC1EPKcRKSaIcE
	subl	$8, %esp
	leal	-49(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIcED1Ev
	movl	-40(%ebp), %eax
	movl	-36(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	$2, -104(%ebp)
	call	__Z9show_listIiIdEEvT_DpT0_
	leal	-48(%ebp), %eax
	leal	-56(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSsC1ERKSs
	subl	$4, %esp
	movzbl	-41(%ebp), %eax
	leal	-48(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	-40(%ebp), %eax
	movl	-36(%ebp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	$3, -104(%ebp)
	call	__Z9show_listIiIdbSsEEvT_DpT0_
	leal	-48(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSsD1Ev
	movl	$0, -112(%ebp)
	leal	-56(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSsD1Ev
	movl	-112(%ebp), %eax
	movl	%eax, -116(%ebp)
	jmp	L12
L8:
	leal	24(%ebp), %ebp
	movl	-100(%ebp), %edx
	movl	-104(%ebp), %eax
	cmpl	$1, %eax
	je	L10
	cmpl	$2, %eax
	je	L11
	testl	%eax, %eax
	je	L9
		.word	0x0b0f
L9:
	movl	%edx, -120(%ebp)
	leal	-49(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIcED1Ev
	movl	-120(%ebp), %eax
	jmp	L5
L11:
	movl	%edx, -128(%ebp)
	leal	-48(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSsD1Ev
	movl	-128(%ebp), %edx
	movl	%edx, -124(%ebp)
	jmp	L7
L10:
	movl	%edx, -124(%ebp)
L7:
	leal	-56(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSsD1Ev
	movl	-124(%ebp), %eax
L5:
	movl	%eax, (%esp)
	movl	$-1, -104(%ebp)
	call	__Unwind_SjLj_Resume
L12:
	leal	-108(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	movl	-116(%ebp), %eax
	leal	-16(%ebp), %esp
	popl	%ecx
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.section	.gcc_except_table,"w"
LLSDA1116:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1116-LLSDACSB1116
LLSDACSB1116:
	.uleb128 0
	.uleb128 0
	.uleb128 0x1
	.uleb128 0
	.uleb128 0x2
	.uleb128 0
LLSDACSE1116:
	.text
	.globl	__Z10show_list2v
	.def	__Z10show_list2v;	.scl	2;	.type	32;	.endef
__Z10show_list2v:
	pushl	%ebp
	movl	%esp, %ebp
	popl	%ebp
	ret
	.section .rdata,"dr"
LC2:
	.ascii ", \0"
	.section	.text$_Z9show_listIiIdEEvT_DpT0_,"x"
	.linkonce discard
	.globl	__Z9show_listIiIdEEvT_DpT0_
	.def	__Z9show_listIiIdEEvT_DpT0_;	.scl	2;	.type	32;	.endef
__Z9show_listIiIdEEvT_DpT0_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	12(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$__ZSt4cout, %ecx
	call	__ZNSolsEi
	subl	$4, %esp
	movl	$LC2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	__Z9show_listIdEvT_
	leave
	ret
	.weak	__Z9show_listIiJdEEvT_DpT0_
	.def	__Z9show_listIiJdEEvT_DpT0_;	.scl	2;	.type	32;	.endef
	.set	__Z9show_listIiJdEEvT_DpT0_,__Z9show_listIiIdEEvT_DpT0_
	.section	.text$_Z9show_listIiIdbSsEEvT_DpT0_,"x"
	.linkonce discard
	.globl	__Z9show_listIiIdbSsEEvT_DpT0_
	.def	__Z9show_listIiIdbSsEEvT_DpT0_;	.scl	2;	.type	32;	.endef
__Z9show_listIiIdbSsEEvT_DpT0_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$124, %esp
	movl	20(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, -48(%ebp)
	movl	16(%ebp), %edx
	movl	%edx, -44(%ebp)
	movb	%al, -52(%ebp)
	movl	$___gxx_personality_sj0, -80(%ebp)
	movl	$LLSDA1149, -76(%ebp)
	leal	-72(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L17, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-104(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -100(%ebp)
	movl	$__ZSt4cout, %ecx
	call	__ZNSolsEi
	subl	$4, %esp
	movl	$LC2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	-28(%ebp), %eax
	movl	24(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSsC1ERKSs
	subl	$4, %esp
	movzbl	-52(%ebp), %eax
	leal	-28(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	%eax, 8(%esp)
	movl	-48(%ebp), %eax
	movl	-44(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	movl	$1, -100(%ebp)
	call	__Z9show_listIdIbSsEEvT_DpT0_
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSsD1Ev
	jmp	L19
L17:
	leal	24(%ebp), %ebp
	movl	-96(%ebp), %eax
	movl	%eax, -108(%ebp)
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSsD1Ev
	movl	-108(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -100(%ebp)
	call	__Unwind_SjLj_Resume
L19:
	leal	-104(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"w"
LLSDA1149:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1149-LLSDACSB1149
LLSDACSB1149:
	.uleb128 0
	.uleb128 0
LLSDACSE1149:
	.section	.text$_Z9show_listIiIdbSsEEvT_DpT0_,"x"
	.linkonce discard
	.weak	__Z9show_listIiJdbSsEEvT_DpT0_
	.def	__Z9show_listIiJdbSsEEvT_DpT0_;	.scl	2;	.type	32;	.endef
	.set	__Z9show_listIiJdbSsEEvT_DpT0_,__Z9show_listIiIdbSsEEvT_DpT0_
	.section	.text$_Z9show_listIdEvT_,"x"
	.linkonce discard
	.globl	__Z9show_listIdEvT_
	.def	__Z9show_listIdEvT_;	.scl	2;	.type	32;	.endef
__Z9show_listIdEvT_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-16(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	movl	$__ZSt4cout, %ecx
	call	__ZNSolsEd
	subl	$8, %esp
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	leave
	ret
	.section	.text$_Z9show_listIdIbSsEEvT_DpT0_,"x"
	.linkonce discard
	.globl	__Z9show_listIdIbSsEEvT_DpT0_
	.def	__Z9show_listIdIbSsEEvT_DpT0_;	.scl	2;	.type	32;	.endef
__Z9show_listIdIbSsEEvT_DpT0_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$124, %esp
	movl	16(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, -48(%ebp)
	movl	12(%ebp), %edx
	movl	%edx, -44(%ebp)
	movb	%al, -52(%ebp)
	movl	$___gxx_personality_sj0, -80(%ebp)
	movl	$LLSDA1172, -76(%ebp)
	leal	-72(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L23, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-104(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	-48(%ebp), %eax
	movl	-44(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	movl	$-1, -100(%ebp)
	movl	$__ZSt4cout, %ecx
	call	__ZNSolsEd
	subl	$8, %esp
	movl	$LC2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	-28(%ebp), %eax
	movl	20(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSsC1ERKSs
	subl	$4, %esp
	movzbl	-52(%ebp), %eax
	leal	-28(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	movl	$1, -100(%ebp)
	call	__Z9show_listIbISsEEvT_DpT0_
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSsD1Ev
	jmp	L25
L23:
	leal	24(%ebp), %ebp
	movl	-96(%ebp), %eax
	movl	%eax, -108(%ebp)
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSsD1Ev
	movl	-108(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -100(%ebp)
	call	__Unwind_SjLj_Resume
L25:
	leal	-104(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"w"
LLSDA1172:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1172-LLSDACSB1172
LLSDACSB1172:
	.uleb128 0
	.uleb128 0
LLSDACSE1172:
	.section	.text$_Z9show_listIdIbSsEEvT_DpT0_,"x"
	.linkonce discard
	.weak	__Z9show_listIdJbSsEEvT_DpT0_
	.def	__Z9show_listIdJbSsEEvT_DpT0_;	.scl	2;	.type	32;	.endef
	.set	__Z9show_listIdJbSsEEvT_DpT0_,__Z9show_listIdIbSsEEvT_DpT0_
	.section	.text$_Z9show_listIbISsEEvT_DpT0_,"x"
	.linkonce discard
	.globl	__Z9show_listIbISsEEvT_DpT0_
	.def	__Z9show_listIbISsEEvT_DpT0_;	.scl	2;	.type	32;	.endef
__Z9show_listIbISsEEvT_DpT0_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$108, %esp
	movl	8(%ebp), %eax
	movb	%al, -44(%ebp)
	movl	$___gxx_personality_sj0, -72(%ebp)
	movl	$LLSDA1180, -68(%ebp)
	leal	-64(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, (%eax)
	movl	$L28, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movzbl	-44(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -92(%ebp)
	movl	$__ZSt4cout, %ecx
	call	__ZNSolsEb
	subl	$4, %esp
	movl	$LC2, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leal	-28(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSsC1ERKSs
	subl	$4, %esp
	leal	-28(%ebp), %eax
	movl	%eax, (%esp)
	movl	$1, -92(%ebp)
	call	__Z9show_listISsEvT_
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSsD1Ev
	jmp	L30
L28:
	leal	24(%ebp), %ebp
	movl	-88(%ebp), %eax
	movl	%eax, -100(%ebp)
	leal	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSsD1Ev
	movl	-100(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -92(%ebp)
	call	__Unwind_SjLj_Resume
L30:
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"w"
LLSDA1180:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1180-LLSDACSB1180
LLSDACSB1180:
	.uleb128 0
	.uleb128 0
LLSDACSE1180:
	.section	.text$_Z9show_listIbISsEEvT_DpT0_,"x"
	.linkonce discard
	.weak	__Z9show_listIbJSsEEvT_DpT0_
	.def	__Z9show_listIbJSsEEvT_DpT0_;	.scl	2;	.type	32;	.endef
	.set	__Z9show_listIbJSsEEvT_DpT0_,__Z9show_listIbISsEEvT_DpT0_
	.section	.text$_Z9show_listISsEvT_,"x"
	.linkonce discard
	.globl	__Z9show_listISsEvT_
	.def	__Z9show_listISsEvT_;	.scl	2;	.type	32;	.endef
__Z9show_listISsEvT_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	leave
	ret
	.text
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
	jne	L33
	cmpl	$65535, 12(%ebp)
	jne	L33
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L33:
	leave
	ret
	.def	__GLOBAL__sub_I__Z9show_listv;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z9show_listv:
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
	.long	__GLOBAL__sub_I__Z9show_listv
	.def	__Unwind_SjLj_Resume;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcEC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1EPKcRKSaIcE;	.scl	2;	.type	32;	.endef
	.def	__ZNSaIcED1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSsC1ERKSs;	.scl	2;	.type	32;	.endef
	.def	__ZNSsD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEd;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEb;	.scl	2;	.type	32;	.endef
	.def	__ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKSbIS4_S5_T1_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
