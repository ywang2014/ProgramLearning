/*
	Filename: cdeclaration.c

	gcc cdecl.c -o cdecl

	测试输入：int* (* p[10])(int* arg)

	代码大全建议：
		尽可能的封装原则
		少用全局变量
		少使用宏定义
		不要使用typedef 重定义 struct
			typedef struct name t_name;
		合理命名变量
		合理命名子程序

		维护全局变量列表

	Global object
		具名常量：
			MAX_TOKENS		声明中标识符最大个数
			MAX_TOKEN_LEN	标识符最大字符数

		枚举变量：
			IDENTIFER		标识符(变量名、函数名、指针名、数组名等)
			QUALIFIER		限定词(const、volatile)
			TYPE			数据类型(char int ...)

			True = 1        模拟布尔类型 真
			False = 0       模拟布尔类型 假

		结构类型：
			token			存储标识符内容和标识符类型

		全局变量
			g_stack			存储标识符的堆栈
			g_top 			栈顶标识

*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TOKENS 50
#define MAX_TOKEN_LEN 30

/* 标识符类型说明具名常量定义 */
enum Type_tag
{
	IDENTIFER,	/* 标识符 */
	QUALIFIER,	/* 限定词 */
	TYPE		/* 类型 */
};

enum Boolean
{
	True = 1,
	False = ! True
};

/* 标识符存储结构 */
struct token
{
	char type;
	char str[MAX_TOKEN_LEN];
};

typedef struct token t_token;	/* 重命名结构类型 */

t_token NULL_TOKEN = {'e', "\0"};  /* 自定义空值 e:error */


/* 存储所有标识符，所维护的栈结构 */
t_token g_stack[MAX_TOKENS];

t_token g_this;	    /* 当前标识符 */
int g_top = -1;		/* 指向栈顶处的元素，开始栈空，则为-1 */

/*
    栈操作基本子程序：

        empty()     判断栈是否为空，是则返回True
        full()      判断栈是否满，是则返回True
        pop()       出栈，返回出栈元素
        push()      入栈，返回是否操作成功
        top()       查看栈顶元素

*/

enum Boolean empty()
{
	if (g_top < 0)
	{
		return True;
	}

	return False;
}

enum Boolean full()
{
    if (g_top == (MAX_TOKENS - 1))
    {
        return True;
    }

    return False;
}

t_token pop()
{
	if (empty())
	{
		return NULL_TOKEN;	/* 栈空，不能出栈操作 */
	}

	return g_stack[g_top--];
}

enum Boolean push(t_token current_token)
{
	if (full())
	{
		return False;	/* 栈满，添加失败 */
	}

	g_stack[++g_top] = current_token;

	return True;	/* 添加成功 */
}

t_token top()
{
	if (empty())
	{
		return NULL_TOKEN;	/* 栈空，没有数据 */
	}

	return g_stack[g_top];
}


/* 推断标识符的类型 */
enum Type_tag deduceType(const t_token current_token)
{
	const char * const s = current_token.str;

	int is_type = strcmp(s, "void") * strcmp(s, "char") * strcmp(s, "signed") * strcmp(s, "unsigned")
		* strcmp(s, "short") * strcmp(s, "int") * strcmp(s, "long") * strcmp(s, "float") * strcmp(s, "double")
		* strcmp(s, "struct") * strcmp(s, "union") * strcmp(s, "enum");

	if (strcmp(s, "const") == 0)
	{
		/* strcpy(s, "read-only");	此处修改了参数 参数不能为 const */
		printf(" **read-only** ");
		return QUALIFIER;
	}
	else if (strcmp(s, "volatile") == 0)
	{
		return QUALIFIER;
	}
	else if (is_type == 0)
	{
		return TYPE;
	}
	else
	{
		return IDENTIFER;
	}
}


/*
    读取标识符 处理输入函数

    不使用全局变量，通过返回值，得到读取的数据

*/
t_token getToken_with_ret()
{
    t_token current_token;

	char *p = current_token.str;

	char ch;
	while ((ch = getchar()) == ' ')
	{
		continue;
	}

	if (isalnum(ch))	/* 判断字符变量是否是字母或数字，是则返回非0 */
	{
		*p = ch;
		while (isalnum(ch = getchar()))
		{
			p++;
			*p = ch;
		}

		ungetc(ch, stdin);	/* 将你读到的字符回退到输入流中 */

		*(++p) = '\0';

		current_token.type = deduceType(current_token);

		return current_token;
	}

	if (ch == '*')
	{
		strcpy(current_token.str, "pointer to");
		current_token.type = '*';
		return current_token;
	}

	current_token.str[1] = '\0';
    current_token.type = ch;	/* ? 括号等 */
	return current_token;
}

/*
    读取标识符 处理输入函数
    无返回值，直接读取数据到全局变量g_this

*/
void getToken()
{
	char *p = g_this.str;

	char ch;
	while ((ch = getchar()) == ' ')
	{
		continue;
	}

	if (isalnum(ch))	/* 判断字符变量是否是字母或数字，是则返回非0 */
	{
		*p = ch;
		while (isalnum(ch = getchar()))
		{
			p++;
			*p = ch;
		}

		ungetc(ch, stdin);	/* 将你读到的字符回退到输入流中 */

		*(++p) = '\0';

		g_this.type = deduceType(g_this);

	}

	if (ch == '*')
	{
		strcpy(g_this.str, "pointer to");
		g_this.type = '*';
	}

	g_this.str[1] = '\0';
    g_this.type = ch;	/* ? 括号等 */
}

void readFirstIdentifier()  /* 找到第一个标识符 */
{
	t_token current_token = getToken_with_ret();

	while (current_token.type != IDENTIFER)
	{
		push(current_token);

		current_token = getToken_with_ret();
	}

	printf("%s is ", current_token.str);

}

/* 处理数组类型 */
void dealIsArray()
{
	t_token current_token = g_this;     /* 验证当前的 */
	int array_size = 0;

	while (current_token.type == '[')
	{
		printf("array ");
		current_token = getToken_with_ret();	/* 数字 或 ] */
		if (isdigit(current_token.str[0]))
		{
			sscanf(current_token.str, "%d", &array_size);	/* 字符串转化为整数 */

			printf("0..%d ", array_size-1);	/* 打印数组大小 */

			current_token = getToken_with_ret();	/* ] */
		}

		current_token = getToken_with_ret();	/* 读取数组后的标记，可能多维数组 */

		printf("of ");
	}

	/* 需要返回curr，如此看来还是g_this简单方便 */
	g_this = current_token;
}

/* 处理函数类型 */
void dealIsFunction()
{
    t_token current_token = getToken_with_ret();    /* 读下一个 */

    printf("function  **arguments is: (");

    while (current_token.type != ')')
    {
        printf("%s ", current_token.str);
        current_token = getToken_with_ret();
    }

    printf(")** ");

    printf("function returning ");
}

void dealIsPointers()
{
    t_token current_token = top();
    while (current_token.type == '*')
    {
        printf("%s ", current_token.str);
        pop();
        current_token = top();
    }
}


void dealDeclarator(const t_token declarator)
{
    t_token current_token;

    /* 处理标识符之后可能存在的数组/函数 */
    switch(declarator.type)
    {
        case '[':
            dealIsArray();
            break;

        case '(':
            dealIsFunction();
            break;
    }

    dealIsPointers();

    /*处理在读入到标识符之前压入到堆栈的符号*/
    while(! empty())
    {
        if(top().type=='(')
		{
            pop();
            current_token = getToken_with_ret();	/*读取')'之后的符号*/
            dealDeclarator(current_token);
        }
        else
        {
            current_token = pop();
            printf("%s ", current_token.str);   /* pop().str 出错 */
        }
    }
}


int main()
{
    char ch = 'y';

    while (ch == 'y')
    {
        printf("Please input the declaration:\n");
        readFirstIdentifier();

        getToken();

        dealDeclarator(g_this);

        printf("\n If continue? y/n: ");

        while ((ch = getchar()) != '\n')
        {
            continue;
        }

        ch = getchar();
    }

    return 0;
}

/*
    int (*p)()      可以
    int (*p)[3]     不可以
    int ((*p)[3])() 不可以
    int (* p[3])()  可以

*/
