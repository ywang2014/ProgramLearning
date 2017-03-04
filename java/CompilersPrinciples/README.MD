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
		
#### 第2章 语法制导翻译器

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
	2.6.1： 2.6.2：2.6.3： 
	public Token scan() throws IOException, SyntaxException{    
		for( ; ; peek = (char)stream.read()){
			if(peek == ' ' || peek == '\t'){        
				continue;      	
			}
			else if(peek == '\n'){
				line = line + 1;      
			}
			else{        
				break;      
			}    
		}
		
		// handle comment    
		if(peek == '/'){      
			peek = (char) stream.read();      
			if(peek == '/'){        // single line comment        
				for( ; ; peek = (char)stream.read()){          
					if(peek == '\n'){
						break;          
					}        
				}      
			}
			else if(peek == '*'){        // block comment        
				char prevPeek = ' ';        
				for( ; ; prevPeek = peek, peek = (char)stream.read()){
					if(prevPeek == '*' && peek == '/'){            
						break;          
					}        
				}
			}
			else{
				throw new SyntaxException();      
			}    
		}   
		
		// handle relation sign    
		if("<=!>".indexOf(peek) > -1){      
			StringBuffer b = new StringBuffer();      
			b.append(peek);      \
			peek = (char)stream.read();      
			if(peek == '='){        
				b.append(peek);      
			}      
			return new Rel(b.toString());    
		}
		
		// handle number, no type sensitive    
		if(Character.isDigit(peek) || peek == '.'){      
			Boolean isDotExist = false;      
			StringBuffer b = new StringBuffer();      
			do{
				if(peek == '.'){          
					isDotExist = true;        
				}        
				b.append(peek);        
				peek = (char)stream.read();      
			} while (isDotExist == true ? Character.isDigit(peek) : Character.isDigit(peek) || peek == '.');      
			
			return new Num(new Float(b.toString()));    
		}      
		
		// handle word
		if(Character.isLetter(peek)){      
			StringBuffer b = new StringBuffer();      
			do{        
				b.append(peek);        
				peek = (char)stream.read();      
			} while (Character.isLetterOrDigit(peek));
			
			String s = b.toString();      
			Word w = words.get(s);      
			if(w == null){        
				w = new Word(Tag.ID, s);        
				words.put(s, w);      
			}      
			return w;    
		}      
		
		Token t = new Token(peek);    
		peek = ' ';    
		return t;  
	} 		
	
	中间代码：抽象语法树、三地址代码
	类型检查、自动类型转换
	2.8.1：	class For extends Stmt{
				Expr e1;
				Expr e2;
				Expr e3;
				Stmt s;
				
				public For(Expr expr1, Expr expr2, Expr expr3, Stmt stmt){
					e1 = expr1;
					e2 = expr2;
					e3 = expr3;
					s = stmt;
				}
				
				public void gen(){
					e1.gen();
					Label start = new Label();
					Label end = new Label();
					emit("ifFalse " + e2.rvalue().toString() + " goto " + end);
					s.gen();
					e3.gen();
					emit("goto " + start);
					emit(end + " ");
				}
			}
	2.8.2： emit("isFalse " + E.rvalue().toString() + " goto " + after); 
			emit("ifNotEqual " + E.rvalue().toString() + " 0 goto " + after); 
		OR	emit("isNotEqualZero " + E.rvalue().toString() + " goto " + after);
	
#### 第3章 词法分析 

	正则表达式 --> 不确定有穷状态自动机 --> 确定有穷状态自动机
	词法分析器：读入源程序的字符串，将源程序中的字符组成一个个词素，生成对应的词法单元
	3.1.1：
	3.1.2：
	正则表达式：* + ? [a-z]
	3.3.1： 
		C：ASCII，标识符只能是(字母|下划线)开头的，(字母|下划线|数字)组成的字符串
		C++：Unicode，标识符只能是(字母|下划线)开头的，(字母|下划线|数字)组成的字符串
		C#：
		Fortran：
		Java：Unicode，标识符只能是(字母|下划线)开头的，(字母|下划线|数字)组成的字符串
		Lisp：
		SQL：
	3.3.2： 
		(1).由a开头和结尾，中间有n个a或b构成的字符串
		(2).由b或者ab一起构成的字符串
		(3).ab构成的字符串，倒数第三位是a，其他位a|b 
		(4).有ab构成的字符串，有且仅有三个b
		(5).有偶数个a和偶数个b构成的字符串
	3.3.3： n+1, n+1, n-1, (n-1)(n-2)/2+2, 2^n
	3.3.4：(select) --> [sS][eE][lL][eE][cC][tT]
		大小写可以混合使用，说明大写字母和小写字母之间的关系是可选择的，但是必须选择其一。
	3.3.5：
		(1).(a)+(e)+(i)+(o)+(u)+		uv=[b-df-hj-np-tv-z] uv*auv*euv*iuv*ouv*uuv*
		(2).(a)+(b)+...(y)+(z)+			a*b*c*....y*z*
	3.3.6:
		(1).[a-jA-J]
		(2).[b-df-hj-np-tv-z]
		(3).[0-9a-f]
		(4).[,.!?]
	3.3.7：
	3.3.8：
	3.3.9：
	3.3.10：
	3.3.11：
	3.3.12：
	状态转换图：词法分析
	3.4.1： 
	3.4.2：
	3.4.3：
		(1).0 0 1 2 3 4 5 1 2
		(2).0 1 2 3 4 5
		(3).0 0 0 1 1 2 3
	3.4.4： 
	3.4.5： 
	3.4.6：(1)是的，(2)不是的
	3.4.7：
	3.4.8：
	3.4.9：
	3.4.10：
	3.4.11：
	3.4.12：
	词法分析器生成工具Lex
	3.5.1： 
		(1).while {return(WHILE);}
	3.5.2： 
	3.5.3： 
	3.5.4： 
	3.5.5： 
	NFA 和 DFA：词法分析器，实际模拟的都是DFA
	3.6.1：
	3.6.2：
	3.6.3：
		(1).0-->(a)-->1-->(a)-->2-->(b)-->2-->b-->3   accept
		(2).0-->(a)-->0-->(a)-->0-->(b)-->0-->b-->0   no
		(3).0-->(a)-->0-->(a)-->1-->(b)-->1-->b-->1   no
		(4).0-->(a)-->1-->(a)-->2-->(b)-->2-->b-->2   no
		(5).0-->(a)-->1-->(a)-->2-->0-->(b)-->0-->b-->0   no
		(6).0-->(a)-->1-->(a)-->2-->(b)-->2-->0-->b-->0   no
	3.6.4：
		(1).0-->(a)-->1-->0-->(a)-->1-->(b)-->2-->(b)-->3   accept
		(2).0-->(a)-->1-->0-->(a)-->1-->(b)-->2-->1-->(b)-->2   no
		(3).0-->(a)-->1-->0-->(a)-->1-->0-->3-->2-->(b)-->3-->2-->(b)-->3   accept
		(3).0-->(a)-->1-->0-->(a)-->1-->0-->3-->2-->1-->(b)-->2-->(b)-->3   accept
		(4).0-->(a)-->1-->0-->(a)-->1-->0-->3-->2-->1-->(b)-->2-->1-->(b)-->2   no
		(5).0-->(a)-->1-->0-->(a)-->1-->0-->3-->2-->(b)-->3-->2-->1-->(b)-->2   no
		(6).0-->3-->(a)-->0-->3-->(a)-->0-->3-->2-->(b)-->3-->2-->1-->(b)-->2   no
		(7).0-->3-->(a)-->0-->3-->(a)-->0-->3-->2-->1-->(b)-->2-->(b)-->3   accept
		...
	3.6.5：
	正则表达式 --> NFA --> DFA 
	3.7.1：
	3.7.2：
	3.7.3：
	3.8.1：0-->(i)-->1-->(f)-->((2))	0-->(epsilon)-->3-->(letter)-->((3))
	3.8.2：0-->(epsilon)-->1-->(letter)-->2-->(letter|number)-->((2))
	3.8.3：
	3.8.4：
	模式匹配器的优化：
		1.正则表达式直接生成DFA：Dstates, Dtransition
		2.DFA状态数量最小化：分组合并
		3.生成更加紧凑的转换表：矩阵、链表、四个数组base、default、next、check
	3.9.1：
	3.9.2：
	3.9.3：
	3.9.4：
	3.9.5：
	DFA 和 NFA区别：
		1.任何一个状态对与任何一个输入符号，有且只有一个转换; 2.不存在epsilon的转换
		2.DFA类似于状态转换图

	词法分析器的实现理论，特别是词法分析器自动生成工具Lex
		
#### 第4章
	
	语法分析器
	上下文无关文法：简称文法，由终结符号、非终结符号、开始符号、产生式组成
	错误处理和错误恢复：
	上下文无关语言：可由文法生成的语言
	二义性：文法中的句子有多棵语法分析树
	有穷自动机不能计数：{((a^n)(b^n))|n>=1}不能使用正则表达式表示
	4.2.1：(1).S-->SS*-->SS+S*-->aS+S*-->aa+S*-->aa+a* 
		(2).S-->SS*-->Sa*-->SS+a*-->Sa+a*-->aa+a* 
		(3).
		(4).没有二义性
		(5).后缀加法，后缀乘法，a为基本符号元
	4.2.2：(1)S-->0S1-->00S11-->000111	无二义性
	4.2.3：
	4.2.4：
	4.2.5：
	4.2.6：
	4.2.7：
	4.2.8：
	消除二义性
	消除左递归
	提取左公因子
	非上下文无关文法，均在语义分析阶段检查。
	4.3.1：
	4.3.2：
	4.3.3：
	LL(k)文法：L:从左向右扫描输入、L:表示产生最左推导、k:每一步需要向前看k个字符
	错误恢复：恐慌模式、短语层次的恢复
	4.4.1：
	4.4.2：
	4.4.3：
	4.4.4：
	4.4.5：
	4.4.6：
	4.4.7：
	4.4.8：
	4.4.9：
	4.4.10：
	4.4.11：
	4.4.12：
	移入-归约语法分析
	LR(k)文法 
	移入-归约语法分析冲突：移入/归约，归约/归约 
	4.5.1：
	4.5.2：
	4.5.3：
	LR(0)自动机
	SLR
	语法分析表：action goto 
	可行前缀
	4.6.1：
	4.6.2：
	4.6.3：
	4.6.4：
	4.6.5：
	4.6.6：
	4.6.7：
	4.6.8：
	4.6.9：
	LR(1)
	LALR：基于LR(0)，更加强大
	4.7.1：
	4.7.2：
	4.7.3：
	4.7.4：
	4.7.5：
	二义性文法：优先级、结合性
	错误恢复方法：恐慌模式、短语层次的恢复
	4.8.1：
	4.8.2：
	Yacc(yet another compiler-compiler)
	Lex与Yacc：(结合生成编译器前端)
		lex first.l 
		yacc second.y 
		cc y.tab.c -ly -ll
	4.9.1：
	4.9.2：
	4.9.3：
	4.9.4：

	语法分析器的实现理论，特别是词法分析器自动生成工具Yacc，文法分析如何实现，如何构建语法分析表等。
	action和goto函数
	
#### 第5章 语法制导的翻译

	L属性翻译方案(通用型)
	S属性翻译方案(综合型)
	SSD：注释语法树
	5.1.1：
	5.1.2：
	5.1.3：
	依赖图：语法分析树-->注释语法分析树(定义了一个节点求值顺序)
	SDD
		S属性：综合属性
		L属性：综合属性+继承属性(必须是左边的或者上方的，不能使用右边的节点)
	5.2.1：
	5.2.2：
	5.2.3：(1)L		(2)L 	(3)S L 	(4)L 
	5.2.4：
	5.2.5：
	5.2.6：
	Syntax Directed：类型检查、中间代码生成
	抽象语法分析树：继承属性、综合属性、epsilon产生式
	5.3.1：
	5.3.2：
	5.3.3：
	SDT(syntax directed translation)：语义动作(产生式中的程序片段)
	LR-->S属性的SDD		后缀翻译
	LL-->L属性的SDD
	SDD：语义规则；SDT：语义动作
	5.4.1：
	5.4.2：
	5.4.3：
	5.4.4：
	5.4.5：
	5.4.6：
	5.4.7：
	LL --> LR：自底向上的方式实现LL文法的L属性SDD(LR文法)
	5.5.1：
	5.5.2：
	5.5.3：
	5.5.4：
	5.5.5：
	5.5.6：

#### 第6章 中间代码生成
	
	DAG(directed acyclic graph)：值编码(散列表)
	6.1.1：
	6.1.2：
	三地址代码：四元式、三元式、间接三元式
	静态单赋值
	6.2.1：
	6.2.2：
	6.2.3：
	类型是有结构的-->类型表达式：
		类比：类、构造函数；类有结构，构造函数就相当于类型构造算子
	类型：类型检查、存储空间分配
	6.3.1：
	6.3.2：
	数组元素寻址：addr = base + n*width
	6.4.1:
	6.4.2:
	6.4.3:
	6.4.4:
	6.4.5:
	6.4.6：
	6.4.7：
	6.4.8：
	6.4.9：
	类型综合、类型推导
	类型转换：拓宽转换、窄化转换；自动类型转换、强制类型转换
	置换、合一
	6.5.1：
	6.5.2：
	布尔表达式：控制流跳转、布尔表达式求值
	短路代码--> 布尔表达式的短路求值(跳转指令)
	if False 优化
	6.6.1：
	6.6.2：
	6.6.3：
	6.6.4：
	6.6.5：
	6.6.6：
	6.6.7：
	6.6.8：
	回填：一趟遍历即可完成
	break、continue、goto
	6.7.1：
	6.7.2：
	6.7.3：
	switch、case
	6.8.1：
	函数调用中间代码
	过程调用参数、返回值、运行时

#### 第7章 运行时刻环境

	存储结构：代码区、静态区、堆、栈
	运行时刻栈
	活动树
	调用者、被调用者
	7.2.1：
	7.2.2：
	7.2.3：
	7.2.4：
	7.2.5：2*a = 2*(3+1+2) = 12
	7.2.6：3*c = 3*(4+1+2+3) = 30
	访问链
	显示表(哈希表原理)
	7.3.1：
	7.3.2：
	堆区内存管理
	存储管理器：分配、回收
	存储结构层次：程序局部性(时间局部性、空间局部性)
	碎片整理：best-fit next-fit first-fit
	内存泄漏、悬空指针
	7.4.1：(1)0, 14, 60, 50, 0, 20, 40
		   (2)80, 30, 60, 0, 0, 0, 8 
	垃圾回收
		类型安全：Java等，(C/C++语言属于类型不安全的，内存地址可以任意的被访问)
		引用计数：循环数据结构(交叉引用)、开销大
		跟踪对象的可达性
	7.5.1：
	7.5.2：
	基于跟踪的垃圾回收
		标记-清扫式垃圾回收
		Baker标记-清扫式垃圾回收 
		标记-压缩垃圾回收
		拷贝垃圾回收
	7.6.1：
	7.6.2：
	7.6.3：
	7.6.4：
	时间划分：增量式垃圾回收
	空间划分：部分垃圾回收
	世代垃圾回收法
	列车垃圾回收算法：单节车厢、恐慌模式
	7.7.1：
	7.7.2：
	7.7.3：
	7.7.4：
	7.7.5：
	并行：存在多个线程
	并发：同时执行多个程序
	C/C++语言垃圾回收：数据表记录分配的内存
	弱化引用
	7.8.1：
	
#### 第8章 代码生成 

	指令选择：RISC CISC
	寄存器分配和指派问题(NP)：哪些指令分配寄存器，某个指令使用哪个寄存器
	指令排序问题(NP)：最优的指令排序

	汇编语言：
		LD、ST、ADD SUB MUL、BR BLTZ
	8.2.1：
		1. LD R1, 1; ST x, R1
		2. LD R1, a; ST x, R1
		3. LD R1, a; ADD R1, R1, 1; ST x, R1 
		4. LD R1, a; LD R2, b; ADD R1, R1, R2; ST x, R1 
		5. LD R1, b; LD R2, c; MUL R1, R1, R2; LD R3, a; ADD R1, R1, R3; ST y, R1
	8.2.2： 
		1. LD R1, i; MUL R1, R1, 4; LD R2, a(R1); ST x, R2 
			LD R1, i; MUL R1, R1, 4; LD R2, x; ST a(R1), R2 
	8.2.3：
	8.2.4：
	8.2.5：
	8.2.6：2+2+1+2、2+1+2+2、2+2+1+2、
	静态分配，固定的绝对地址
	栈分配，SP寄存器控制的
	8.3.1：
	8.3.2：
	8.3.3：
	基本块、流图
	8.4.1：		
	8.4.2：		
	基本块的优化：
		1.消除公共子结点
		2.消除死代码
		3.常量求值替换
		4.代数恒等式的优化
	8.5.1：
	8.5.2：
	8.5.3：
	8.5.4：
	8.5.5：
	8.5.6：
	8.5.7：
	8.5.8：
	寄存器描述符、地址描述符  -->两张表记录寄存器和变量的地址信息
	getReg(I)：完成寄存器的选择和分配
	8.6.1：
	8.6.2：
	8.6.3：
	8.6.4：
	8.6.5：
	窥孔优化：
		1.消除冗余代码
		2.消除不可达代码
		3.控制流优化：尽量少采用无条件跳转
		4.代数化简、强度消减
		5.使用特殊机器指令
	8.7.1：
	8.7.2：
	8.7.3：
	寄存器分配和指派：图着色算法
	8.8.1：
	8.8.2：
	
		

#### 第9章


#### 第10章


#### 第11章


#### 第12章





**Start Date：2016-12-22**

**End Date: **