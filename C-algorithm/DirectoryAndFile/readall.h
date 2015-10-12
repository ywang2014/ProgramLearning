/*
* 命令行执行：dir c:\*.* /s/b > allfile.txt
    将c盘所有文件输出到了 allfile.txt中！

    c语言调用cmd 为 system（“cmd命令”）
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void readall()
{
    FILE *fp = NULL;
    char *fbuffer;
    int i, len;

    system("dir c:\\*.* /s/b > filelist.txt");          // 全部文件
    system("dir c:\\*.txt /b > filelist_curr.txt"); // 当前目录下的txt文件

    Sleep(100);
    fp = fopen("filelist.txt", "r");

    fseek(fp, 0, SEEK_END); // 将文件指针移动到文件结尾
    len = ftell(fp);    // 获取文件长度
    fbuffer = (char*)malloc(sizeof(char) * len);
    rewind(fp); // 复位文件指针

    fread(fbuffer, 1, len, fp); // while() fgets() fputs()

    for (i = 0; i < len; i++)
    {
        printf("%c", fbuffer[i]);
    }

    fclose(fp);
}
