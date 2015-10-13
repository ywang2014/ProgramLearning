/*
* 测试 gcc 编译全过程
* 都在命令行下执行！

1.无选项编译链接
	用法：>gcc hello.c
	作用：将hello.c预处理、汇编、编译并链接形成可执行文件。未指定输出文件，默认输出为a.exe(Linux: a.out)。

2.选项-o
	用法：>gcc hello.c -o hello
	作用：-o选项用来指定输出文件的文件名。

3.选项-E
	用法：>gcc -E hello.c -o hello.i	// 必须指定输出文件，且有文件后缀名 *.i，否则在命令行输出结果
	作用：将hello.c只进行预处理，输出hello.i文件。

4.选项-S
	用法：>gcc -S hello.i -o / gcc -S hello.c	// 必须指定输出文件，且有文件后缀名 *.s，否则没有输出结果
	作用：将预处理输出文件hello.i汇编成hello.s文件。

5.选项-c
	用法：>gcc -c hello.s
	作用：将汇编输出文件hello.s编译输出hello.o文件。

6.无选项链接
	用法：>gcc hello.o -o hello
	作用：将编译输出文件hello.o链接成最终可执行文件hello。

7.选项-O
	用法：>gcc -O1 hello.c -o hello
	作用：使用编译优化级别1编译程序。级别为1~3，级别越大优化效果越好，但编译时间越长。

1.多个文件一起编译
	用法：>gcc hellofun.c hello.c -o hello
	作用：将hellofun.c和hello.c分别编译后链接成hello可执行文件。

2.分别编译各个源文件，之后对编译后输出的目标文件链接。
	用法：
		>gcc -c hellofun.c //将hellofun.c编译成hellofun.o
		>gcc -c hello.c    //将hello.c编译成hello.o
		>gcc -o hellofun.o hello.o -o hello //将hellofun.o和hello.o链接成hello

以上两种方法相比较，第一中方法编译时需要所有文件重新编译，而第二种方法可以只重新编译修改的文件，未修改的文件不用重新编译。

8.选项-M
	用法：>gcc hello.o -o hello
	作用：生成文件关联的信息，包含目标文件所依赖的所有源代码。结果输出在命令行！

9.选项-MD
	用法：>gcc -MD hello.c
	作用：将将-M生成的关联信息，输出到文件hello.d。
*/

#include <stdio.h>

int main()
{
	printf("Hello Boys\n");
	
	return 0;
}