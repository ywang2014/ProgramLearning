/*
* codeblocks 不能输出中文，一直是乱码，网上各种教程弄了好久，硬是没有解决！
*   setting->editor 里面修改编码方式为：WINDOWS936
*   settings->compiler settings
*     -finput-charset = GBK(UTF-8)
*     -fexec-charset = GBK
*
* 想了很久，不知道原因，就卸载了codeblocks，装了一个自带MinGW的，结果还是没有解决
* 唯一的变化是乱码变了，但是还是无法正常识别。
*
* 卸载了cygwin，因为命令提示可以直接使用Linux命令，想着可能有影响，发现dos装口一直不能识别中文文件名，显示一堆???
* 设置字符默认值，chcp936等，都不没有作用，如此就卸载了。
*
* 然后果然好了！codeblocks可以正常输出正文，dos窗口也可以识别中文文件名了！

* 上次遇到cygwin的问题是，io.h头文件没有定义读取目录下文件的那些函数，如此看来cygwin和windows的兼容还是有很多缺陷的！
*
*/

#include <iostream>
#include <stdio.h>
#include <locale.h>

using namespace std;

int main()
{
    printf("我是中国remnant\n");    // UTF-8 乱码显示
    setlocale(LC_ALL, "GBK");
    /*
    * GBK 编码下，可以通过编译，但是无显示结果，两个空行！
    * UTF-8 无法通过编译：error: converting to execution character set: Illegal byte sequence|

    wchar_t s[] = L"我是中国、你、\n";
    wprintf(s);
    printf("%S", s);
    */
    cout << "我是中国人！\n";

    return 0;
}
