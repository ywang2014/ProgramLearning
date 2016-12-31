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