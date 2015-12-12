/*
	Filename: cdeclaration.c 
	
	gcc cdecl.c -o cdecl 
	
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

/* max numTokens in declaration sentence */
const int MAX_TOKENS 50
/* max length of each token */
const int MAX_TOKEN_LEN 30

/* 标识符类型说明具名常量定义 */
enum type_tag
{
	IDENTIFER,	/* 标识符 */
	QUALIFIER,	/* 限定词 */
	TYPE		/* 类型 */
};

enum Boolean
{
	True,
	False = ! True
};

/* 标识符存储结构 */
struct token
{
	char type,
	char str[MAX_TOKEN_LEN];
};

typedef struct token t_token;	/* 重命名结构类型 */


/* 存储所有标识符，所维护的栈结构 */
t_token g_stack[MAX_TOKENS];

/* t_token g_this;	当前标识符 */
int g_top = -1;		/* 指向栈顶处的元素，开始栈空，则为-1 */

t_token pop_old(int *top)
{
	if (*top < 0)
	{
		return NULL;	/* 栈空，不能出栈操作 */
	}
	
	*top = *top - 1;
	return g_stack[*top + 1];
}

int push_old(int *top, const t_token var_token)
{
	if (*top == MAX_TOKENS)
	{
		return 0;	/* 栈满，添加失败 */
	}
	*top = *top + 1;
	g_stack[*top] = var_token;
	
	return 1;	/* 添加成功 */
}

t_token pop()
{
	if (g_top < 0)
	{
		return NULL;	/* 栈空，不能出栈操作 */
	}
	
	return g_stack[g_top--];
}

int push(const t_token var_token)
{
	if (g_top == (MAX_TOKENS - 1))
	{
		return 0;	/* 栈满，添加失败 */
	}
	
	g_stack[++g_top] = var_token;
	
	return 1;	/* 添加成功 */
}

t_token getTop()
{
	if (g_top < 0)
	{
		return NULL;	/* 栈空，没有数据 */
	}
	
	return g_stack[g_top];
}

int isEmpty()
{
	if (g_top < 0)
	{
		return 1;
	}
	
	return 0;
}

/* 推断标识符的类型 */
enum type_tag deduceTypeOfToken(char * const str)
{
	char *s = str;
	
	int is_type = strcmp(s, "void") * strcmp(s, "char") * strcmp(s, "signed") * strcmp(s, "unsigned") 
		* strcmp(s, "short") * strcmp(s, "int") * strcmp(s, "long") * strcmp(s, "float") * strcmp(s, "double") 
		* strcmp(s, "struct") * strcmp(s, "union") * strcmp(s, "enum");
	
	if (strcmp(s, "const") == 0)
	{
		strcpy(s, "read-only");	/* 参数不能为 const char * const p */
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

/* 读取标识符 处理输入函数 */
t_token getToken()
{
	t_token this;
	char *p = this.str;
	
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
		
		this.type = deduceTypeOfToken(this.str);
		
		return this;
	}
	
	if (ch == '*')
	{
		strcpy(this.str, "pointer to");
		this.type = '*';
		return this;
	}
	
	this.string[1] = '\0';
	this.type = ch;	/* ? 括号等 */
	return this;
}

t_token readFirstIdentifier()
{
	t_token current_token = getToken();
	while (current_token.type != IDENTIFER)
	{
		push(current_token);
		current_token = getToken();
	}
	
	printf("%s is ", current_token.str);
	
	return getToken();
}

void dealIsArray(const t_token this)
{
	t_token current_token;
	int array_size = 0;
	
	while (this.type == '[')
	{
		printf("array ");
		current_token = getToken();	/* 数字 或 ] */
		if (isdigit(current_token.str[0]))
		{
			sscanf(current_token, "%d", &array_size);	/* 字符串转化为整数 */
			
			printf("0..%d ", array_size-1);	/* 打印数组大小 */
			
			current_token = getToken();	/* ] */
		}
		
		current_token = getToken();	/* 读取数组后的标记，可能多维数组 */
		
		printf("of ");
	}
	
	/* 需要返回curr，如此看来还是g_this简单方便 */
}

void dealIsFunction(const t_token this)
{
	 /* 处理函数参数 */  
    while (this.type != ')')  
    {  
        gettoken();  
    }  
	
    gettoken();  
    printf("function returning ");  
}

void dealIsPointers()
{  
    while (getTop().type == '*')  
    {  
        printf("%s ", pop().str);  
    }  
}  


void dealDeclarator(const t_token this)  
{
	t_token current_token;

    /* 处理标识符之后可能存在的数组/函数 */  
    switch(this.type)  
    {  
        case '[':  
            dealIsArrays(this);  
            break;  
        case '(':  
            dealIsFunction(this);  
            break;  
    }  
	
    dealIsPointers();  
	
    /*处理在读入到标识符之前压入到堆栈的符号*/  
    while(! isEmpty())  
    {  
        if(getTop().type=='(')
		{  
            pop();  
            current_token = getToken();	/*读取')'之后的符号*/  
            dealDeclarator(current_token);  
        }  
        else  
        {  
            printf("%s ",pop().str);  
        }  
    }  
}  


int main()  
{
	t_token current_token;
	
    current_token = read_to_first_identifier();  
	
    dealDeclarator(current_token);  
	
    printf("\n");  
	
    return 0;  
}  

