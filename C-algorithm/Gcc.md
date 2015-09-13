# GCC 编译命令
## 简单入门

gcc main.c			// 当前目录下生成可执行文件：Unix/Linux a.out    Windows a.exe

gcc main.c -o main	// -o 可以指定生成的可执行文件的名称

main				// 运行可执行文件

## 编译流程

	Pre-processing
	
	Compiling
	
	Assembling
	
	Linking
	
## 指令格式

	gcc [option] file [option] [object]
	
gcc -E main.c -o mian.id	// -E 让gcc在预处理结束后停止编译过程

	// xxx.i 文件为已经预处理过的C原始程序
	
	预处理过程：#include 包含头文件，将头文件和源代码组合成复合文件(main.i)用于编译
				
				#define 宏定义，文本替换

gcc -S main.i -o main.s		// -S 让gcc只进行编译而不进行汇编，生成汇编代码

	// xxx.s 汇编代码，可以查看汇编语言如何实现 c 程序的
	
	编译过程：检查代码规范性，语法错误等
	
gcc -c main.s -o main.o		// -c 汇编：让gcc生成目标文件(二进制代码)

	// xxx.o 二进制目标代码
	
gcc main.o -o main			// 让gcc生成可执行文件

	// xxx.out/xxx.exe	
	
	链接过程：链接函数库，实现库函数的成功调用
	
			头文件中，只有库函数的声明，没有定义函数的实现，实际定义在 glibc中
			(C++库：Cygwin\lib\gcc\i686-pc-cygwin\4.9.3\include\c++)
			
			静态库：编译链接时，把库文件的代码全部加入到可执行文件中，因此生成的文件比较大，但在运行时也就不再需要库文件了
			
			动态库：编译链接时并没有把库文件的代码加入到可执行文件中，而是在程序执行时由运行时链接文件加载库，这样可以节省系统的开销
			
			
## Options
	
	-E		只进行预处理
	
	-S		只进行编译不进行汇编处理
	
	-c		编译且汇编处理，不进行链接
	
	什么都没有时，全部进行，直接生成可执行程序
	
	-g 		在可执行程序中，包含标准调试信息
	
	-o file_name 自定义输出文件名称
	
	-v 		打印出编译器内部编译各过程的命令行信息和编译器的版本
	
	-l dir	在头文件的搜索路径列表中添加dir目录
	
	-L dir	在库文件的搜索路径列表中添加dir目录
	
	-static		链接静态库
	
	-llibrary	连接名为library的库文件
	
	-w		关闭所有警告
	
	-Wall	允许发出gcc的警告信息
	
	-werror	把警告信息转化为错误信息
	
	
## Gdb 调试

	gcc -g main.c -o main	// 编译的时候，加上 -g 
	
	gdb main
	
	gdb 命令：
		
		breakpoint	断点
		
		continue	继续
		
		run			允许
		
		...



