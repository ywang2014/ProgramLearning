#ifndef _READTXT_
#define _READTXT_

#include <stdio.h>
#include <io.h>     // #include <io.h>


/*
    #include <io.h>
    在<io.h>的头文件中:
        查找文件的类 struct _finddata_t结构体: 存储文件各种信息的
            unsigned atrrib：文件属性的存储位置。
            它存储一个unsigned单元，用于表示文件的属性。文件属性是用位表示的，主要有以下一些：
                _A_ARCH（存档）、_A_HIDDEN（隐藏）、_A_NORMAL（正常）、_A_RDONLY（只读）、_A_SUBDIR（文件夹）、_A_SYSTEM（系统）。
            这些都是在<io.h>中定义的宏，可以直接使用，而本身的意义其实是一个无符号整型（只不过这个整型应该是2的几次幂，从而保证只有一位为1，而其他位为0）。
            既然是位表示，那么当一个文件有多个属性时，它往往是通过位或的方式，来得到几个属性的综合。例如只读+隐藏+系统属性，应该为：
                _A_HIDDEN | _A_RDONLY | _A_SYSTEM

            time_t time_create：这里的time_t是一个变量类型，用来存储时间的

            time_t time_access：文件最后一次被访问的时间。

            time_t time_write：文件最后一次被修改的时间。

            _fsize_t size：文件的大小。这里的_fsize_t应该可以相当于unsigned整型，表示文件的字节数。

            char name[_MAX_FNAME]：文件的文件名。这里的_MAX_FNAME是一个常量宏，它在<stdlib.h>头文件中被定义，表示的是文件名的最大长度。

            struct _finddata_t
            {
                unsigned attrib;
                time_t time_create;
                time_t time_access;
                time_t time_write;
                _fsize_t size;
                char name[_MAX_FNAME];
            };

        函数:
        long _findfirst( char *filespec, struct _finddata_t *fileinfo )；
            返回值：如果查找成功的话，将返回一个long型的唯一的查找用的句柄（就是一个唯一编号）。这个句柄将在_findnext函数中被使用。若失败，则返回-1。
            参数：  filespec：标明文件的字符串，可支持通配符。比如：*.c，则表示当前文件夹下的所有后缀为C的文件。
                    fileinfo ：这里就是用来存放文件信息的结构体的指针。这个结构体必须在调用此函数前声明，不过不用初始化，只要分配了内存空间就可以了。函数成功后，函数会把找到的文件的信息放入这个结构体中。

        int _findnext( long handle, struct _finddata_t *fileinfo );
            返回值：若成功返回0，否则返回-1
            参数:   handle：即由_findfirst函数返回回来的句柄。
                    fileinfo：文件信息结构体的指针。找到文件后，函数将该文件信息放入此结构体中。

        int _findclose( long handle );
            返回值：成功返回0，失败返回-1。
            参数：  handle ：_findfirst函数返回回来的句柄。

        先用_findfirst查找第一个文件，若成功则用返回的句柄调用_findnext函数查找其他的文件，当查找完毕后用，用_findclose函数结束查找

    // gcc struct _finddata_t 未定义的解决办法
        codeblocks 使用 cygwin里面的gcc编译器
        偶然想着弄一个自动读取文件夹下面照片并自动显示的小程序
            然后就学习下读取文件夹里面文件的操作，百度一下，很多同样的问题
            找到了大牛的博客(http://blog.csdn.net/alsm168/article/details/6503434)，学习了下，讲得非常清晰具体，基本看了可以理解
            ps: 这样的博客很多，内容好像也是90%以上的相似度的。
            调试的时候，发现问题来了：storage size of 'fileinfo' isn't known，明显应该是struct _finddata_t属于未定义的
            继续百度，发现同样问题的同志很多，也有解决方法，这次就不靠谱了，还有很多问题贴应该是至今未解的。
            方法1：自己定义一个 struct _finddata_t 结构体
                struct _finddata_t
                {
                    unsigned attrib;
                    time_t time_create;
                    time_t time_access;
                    time_t time_write;
                    _fsize_t size;
                    char name[_MAX_FNAME];
                };

    没有io.h 头文件 (cygwin io.h 很奇怪！)
        cygwin/usr/include有，在/usr/include/sys下没有，但是”io.h"里面没有关于读取目录下文件的函数和结构定义！
        mingw/include 里面有"io.h"，也定义了struct _finddata32_t、struct _finddata64_t等数据结构，但是不知道怎么使用！如法连接动态库！

    解决办法，使用mingw的编译器，就可以正确的执行了，cygwin里面的mingw不知道如何直接使用，然后直接卸载了codeblocks安装了一个自带wingw的版本，

*/

/*
    读取同一文件夹下的所有txt文件
    这个文件的查找是在指定的路径中进行，如何遍历硬盘，在整个硬盘中查找文件，需要递归遍历

    找到则输出并返回0，否则返回-1
*/

int readtxt()
{
    struct _finddata_t fileinfo;  // _finddata32_t
    long fHandle;
    FILE *fp;
    fp = fopen("filelog.txt", "wb");

    const char *to_search = "D:\\Soft\\Cc++source\\DirectoryAndFile\\*.h"; // 目标查找文件，*通配符
    if ((fHandle = _findfirst(to_search, &fileinfo)) == -1L)
    {
        printf("There is no suitable file!\n");
        return -1;
    }
    printf("%s\n", fileinfo.name);  // 打印文件名

    while(! _findnext(fHandle, &fileinfo))
    {
        printf("%s\n", fileinfo.name);
        fprintf(fp, "%s\n", fileinfo.name);
    }

    _findclose(fHandle);
    fclose(fp);

    return 0;
}

#endif // _READTXT_



