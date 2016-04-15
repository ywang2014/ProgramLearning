/**
	微软研究院笔试题目
*/

#include <stdio.h>

/*
FindSubString()中
	用到了“回文段落跳过” 
	*p1 == p1[1] - 1，即看该字符串是不是递增的，即x后面是y，y后面是z，然后用count记录
	*p1 == p1[1] + 1，即看该字符串是不是递减的，即z后面是y，y后面是x，然后用count2递减
	若回文则返回 回文子串长度，若不回文则返回0
	
	FindSubString函数查找对称的回文子串（例如CDC），返回count，若不是回文子串或者不对称则返回0
	
	FindSubString() 函数就是要找到一个先递增再递减且递增和递减的数量相等的回文序列，例如： ABCDCBA ，
	先是   后一项 = 前一项 ASCII 码 +1 ， 
	后是   后一项 = 前一项 ASCII 码 -1 ，才能返回回文子串的长度，否则返回 0 。
*/
int FindSubString( char* pch )
{
    int   count  = 0;
    char  * p1   = pch;
    while ( *p1 != '\0' )
    {
        if ( *p1 == p1[1] - 1 )
        {
            p1++;
            count++;
        }else  {
            break;
        }
    }
    int count2 = count;
    while ( *p1 != '\0' )
    {
        if ( *p1 == p1[1] + 1 )
        {
            p1++;
            count2--;
        }else  {
            break;
        }
    }
    if ( count2 == 0 )
        return(count);
    return(0);
}

/*
ModifyString()中
	过滤XY，找到第一个回文字段的开始，即BCDCB 中的B，然后跨过回文段
	到ABABA，进入FindSubString() 得 ABA，即count=1；
	sprintf( p2, "%i", count );把B换成1，即A1，然后 *p2++=*p1++  A1BAA
*/
void ModifyString( char* pText )
{
    char  * p1   = pText;
    char  * p2   = p1;
    while ( *p1 != '\0' )
    {
        int count = FindSubString( p1 );
        if ( count > 0 )
        {
            *p2++ = *p1;
            sprintf( p2, "%i", count );
            while ( *p2 != '\0' )
            {
                p2++;
            }
            p1 += count + count + 1;
        }else  {
            *p2++ = *p1++;
        }
    }
}

/*
当遇到 ABABA 中前一个 ABA 的时候，满足回文子串要求，此时 p1 指向 A BABA ， p2 指向 ABABA ； sprintf 重定向修改 ABABA ， B 变为 1 ，且跟随一个 ‘\0’ （该函数自动产生的） , 此时，字符串变为 A1‘\0’BA 。
经过    while ( *p2 != '\0' ) 循环之后， p2 指向 A1‘\0’BA ， p1 += count + count + 1 之后， p1 指向 A1‘\0’BA 。此时字符串已经被改动，之前的 ABABA 已经不存在，变为 A1‘\0’BA 。
再次进入 while ( *p1 != '\0' ) 循环之后，只能执行 else 部分的命令， p1 指向 p2 指向的元素的后一个，不断将 p1 指向的元素传给 p2 所指向的位置，将原数据覆盖。所以， A1‘\0’BA ，依次变为 A1BBA 、 A1BAA 。
即最终结果为 XYBCDCBA1BAA 。
*/
int main( void )	// C++ main必须返回int
{
    char text[32] = "XYBCDCBABABA";
    ModifyString( text );
    printf( text ); // XYBCDCBA1BAA

    return 0;
}
