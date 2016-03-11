/*
笔试题目：

数据有效性检测
用户数据存储在 64KB 大小的块中，64KB的块划分为32个2KB的存储单元.
文件格式：
    1.第一字节：索引号，表示第几个存储单元，1 开始计数
    2.第二字节：状态，共3种，0xFF数据为空，0x3F数据正常，0x1F数据损坏
    3.最后一个字节：版本，从0开始递增
    4.倒数第二个、第三个字节为校验和(从第一字节至倒数第四个字节的累加和(忽略溢出，取低两个字节)，倒数第三字节存储高位)
    5.其余为用户数据

    在64KB的块里寻找最新有效数据，则返回对应的索引号，否则返回0xFF
    最新数据定义：
        1.状态为0x3F
        2.校验和匹配通过
        3.版本最大
*/

void GetData(char *buffer, int length, int index);

unsigned char getUserValidData(void)
{
    int i = 0;
    int index = -1;
    char maxVersion = '0';
    int length = 0xa00;
    char buffer[0xa00];
    int flag = 1;
    int j = 0;
    unsigned short sum = 0;
    unsigned short little = 0;
    unsigned short big = 0;

    unsigned char ret = '0';

    for (i = 1; i <= 32; i++)
    {
        GetData(buffer, length, i);

        for (j = 0; j < length - 3; j++)
        {
            sum += buffer[j];
        }
		
		// 数据校验码的思考可能存在大问题？？？？？？？？？？？
        little = buffer[j-2];
        big = buffer[j-3] * (1<<8);

        if (sum == (little + big))
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }

        if (buffer[1] == 0xff && flag == 1) // flag = 1 说明校验和通过
        {
            if (maxVersion < buffer[length - 1])
            {
                maxVersion = buffer[length - 1];
                index = i;
            }
        }
    }

    if (index == -1)
    {
        ret = 0xFF;
        return ret;
    }

    ret = index;
    return ret;
}
