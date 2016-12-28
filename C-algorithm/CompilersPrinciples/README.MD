# Compilers Principles -- Alfred(赵建华等译)
大名鼎鼎的龙书，专门讲编译原理，编译器的设计和实现。

#### 第1章 引论
	
	编译器：将源语言程序翻译成目标语言程序
	解释器：不翻译源程序，而是边解释边执行源程序
	预处理器：把源程序聚合在一起，宏展开
	汇编器：将汇编语言程序生成可重定位的机器码
	链接器：解决外部内存地址问题，将多个目标文件和库文件链接到一起
	加载器：把所有的可执行目标文件放到内存中执行
	
	1.1.1：解释器是一条一条的解释执行源语言；编译器是把源代码整个编译成目标代码，执行时不在需要编译器，直接在支持目标代码的平台上运行
	1.1.2：执行效率高；错误诊断更优
	1.1.3：汇编语言更容易调试、检查bug。跨平台，可移植性强
	1.1.4：C语言小巧灵活，通用性高，执行效率高
	1.1.5：将汇编程序，翻译成机器指令
	
	词法分析：
	语法分析：
	语义分析：
	代码优化：
	代码生成：
	
	1.3.1：
		强制式的语言：C C++ Java
		声明式的语言：ML Haskell Prolog
		冯诺依曼式语言：Fortran C 
		面向对象的语言：C++ Java C# Smalltalk Ruby
		函数式的语言：ML Haskell scheme
		第三代语言：Fortran Gobol Lisp C C++ C# Java VB
		第四代语言：NOMAD SQL PostScript
		脚本语言：Awk JavaScript Perl PHP Python Ruby
		
	高性能系统：并行性(指令级并行、处理器级并行)和内存层次结构(cache)
			
	静态和动态：多态
	作用域：public、private、protected
	参数传递机制：传值、传引用、传名(类似宏)  
	别名
	1.6.1：w = 13, x = 11, y = 13, z = 11
	1.6.2：w = 9, x = 7, y = 13, 11 
	1.6.3：		w1: B1-B3-B4
				x1: B1-B2-B4
				y1: B1-B5
				z1: B1-B2-B5
				x2: B2-B3
				z2: B2
				w3: B3 
				x3: B3 
				w4: B4
				x4: B4 
				y5: B5
				z5: B5 
	1.6.4：3\n 2\n 
		
#### 第2章

	语法分析：上下文无关文法--->产生式
	2.2.1：1.S-->SS*-->(S)S*-->(SS+)S*-->(aS+)S*-->aa+a*	S-->SS*-->(S)a*-->(SS+)a*-->(Sa+)a*-->aa+a*	
		2.				S
						|
				S		S 	*
				|		|
			S 	S 	+	a
			|	|
			a 	a 
		3.文法生成的语言是以a为基本运算因子(factor)的+和*运算符表达式的后缀形式
	2.2.2:(1).(0)^n(1)^n 	(2).基于a的前缀表达式	(3).对称括号对的串	
		(4).ab个数相等的字符串	(5).以a为factor的字符串，有+、*、()等符号
	2.2.3：1、2无二义		3、4、5有二义
	2.2.4：(1).S-->SS+|SS-|SS*|SS/|a	(2).S-->S,id|id 	(3).S-->id,S|id 
			(4).expr-->expr+expr|expr-expr|expr*expr|expr/expr|id|digit
			(5).expr-->expr+expr|expr-expr|expr*expr|expr/expr|id|digit|+expr|-expr 
	2.2.5：(11)=3，(1001)=9，(num 0)=(num)*2，(num num)=(num)*2*2+(11)|(num)*16+(1001)。显然文法生成的所有的数字，都可以被3整数.(x0=3, x1=9, fnx=2x|4x+3|16x+9)
			不能生成所有的：3,6,9,12,15,18,24,27
	2.2.6： RomanNum --> Thousands Hundreds Tens Ones
			Ones --> LowOnes|IV|V LowOnes|IX
			LowOnes --> epsilon|I|II|III
			Tens --> LowTens|XL|L LowTens|XC
			LowTens --> epsilon|X|XX|XXX
			Hundreds --> LowHundreds|CD|D LowHundreds|CM
			LowHundreds -->epsilon|C|CC|CCC
			Thousands --> M Thousands|epsilon
	语法分析树：语义动作，后序遍历
	2.3.1：S-->S1+S2  S.t='+'||S1.t||S2.t
			S-->S1-S2  S.t='-'||S1.t||S2.t
	2.3.2：S-->S1S2+  S.t=S1.t||'+'||S2.t
			S-->S1S2-  S.t=S1.t||'-'||S2.t
	2.3.3： u -> u + u | pn | n
			p -> 1 | 10 | 100
			n -> 1 | 5 | 10 | 50 | 100 | 500 | 1000
			1 -> I
			5 -> V
			10 -> X
			50 -> L
			100 -> C
			500 -> M
			1000 -> D
	2.3.4：2.3.3相反的过程 
	2.3.5：S-->S1S2+  S.t='+'||S1.t||S2.t
			S-->S1S2-  S.t='-'||S1.t||S2.t
	向前看符号、预测分析器
	左递归、右递归
	2.4.1：
	(1)	void S(){
			switch(lookhead){
				case '+':
					match('+');
					S();
					S();
					break;
				case '-':
					match('-');
					S();
					S();
					break;
				case 'a':
					match('a');
					break;
				default:
					report("syntax error");
			}
		}
		
		void match(Terminal t){
			if (lookhead == t){
				lookhead = nextTerminal;
			}
			else{
				report("syntax error");
			}
		}
	(2).	void S(){
				if (lookhead == '('){
					S();
					match('(');
					S();
					match(')');
					S();
				}
				// epsilon
			}
	(3).	void S(){
				switch (lookhead){
					case '0':
						match('0');
						S();
						match('1');
						break;
					case '1':
						break;
					default:
						report("syntax error");
				}
			}
	词法分析：忽略空白符和换行符、抽取token(数字和标识符)
	2.6.1： 
	2.6.2：
	2.6.3： 
			
#### 第3章


#### 第4章


#### 第5章


#### 第6章


#### 第7章


#### 第8章


#### 第9章


#### 第10章


#### 第11章


#### 第12章





**Start Date：2016-12-22**

**End Date: **