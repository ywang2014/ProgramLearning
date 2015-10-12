#ifndef _CREATEFILE_
#define _CREATEFILE_

#include <stdio.h>

/*
* 在自己的指定路径下，创建c语言文件
* 输入的路径必须是有效的，否则无法成功
*   eg：输入 Soft\\Csource\\test
        结果就会在 D:\\Soft\\Csource文件夹(必须是已经有的文件夹)下面创建一个test.c文件
*/
void createfile()
{
    char dirName[50];
    char path[50];
    FILE *fp;

    printf("Please input the directory name: ");
    scanf("%s", dirName);
    sprintf(path, "D:\\%s.c", dirName); // create a file path
    fp = fopen(path, "wb");     // 此文件不存在时，自动创建！
    fwrite("#include <stdio.h> \n", 1, 20, fp); // 长度必须为 20， 21就有多余字符！
    fwrite("I am a test file!\n", 1, 30, fp);

    fclose(fp);
}


#endif // _CREATEFILE_
