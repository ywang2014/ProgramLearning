# 编译器开发过程总结
来自知乎大牛分享

这个编译器，(GitHub - wgtdkp/wgtcc: a tiny C compiler in C++) 一方面是为了学习 C11, 一方面为了练习C++。
在约11k代码中实现了：

	几乎完整的C11语法解析(除去变长数组);
	语义与类型检查(仿gcc的错误提示)
	预处理器
	x86-64汇编代码生成， 多谢@RednaxelaFX的回答寄存器分配问题？编译器，把我从无休止的手动优化中拯救回来
	精简的x86-64 ABI

C11 中有一些非常实用或者好玩的新特性，如 compound literal. 一个典型的用途是当我们想获得一个数据的另一种表示的时候， 我们可能会这么做：
	
	float f = 1.5;
	int i = *(int*)&f;

然而gcc 在开 -O2 时会报 break strict-aliasing rules 的warning。 有了 compound literal， 我们可以这么做：
	#define CAST(s_t, d_t, sv) \
		(union {s_t sv; d_t dv;}){sv}.dv
	float f = 1.5;
	int i = CAST(float, int, f);

C11 也支持在identifier 中使用unicode字符了，中文编程很exciting：
	
	#define 整型    int
	#define 输出    printf
	#define 面函数  main
	#define 返回    return
	#define 定义    typedef
	#define 不可变  const
	#define 字符    char
	#define 指针    *
	#define 为

	定义 不可变 字符 指针 为 字面值;

	整型 面函数() {
		字面值 蛤蛤 = "\u82df\u5229\u56fd\u5bb6\u751f\u6b7b\u4ee5\uff0c"
					 "\u5c82\u56e0\u7978\u798f\u907f\u8d8b\u4e4b";
		输出("%s\n", 蛤蛤);
		返回 0;
	}
	
写这个小编译器总结的方法吧：
1.以最快的速度做到能够解析下面这段代码：
	int main(int argc, char** argv) {
		int i;
		return 0;
	}
在此之前可以写一个简单的scanner，能够达到解析常见的token就行。
2.以最快的速度看到hello，world。
3.开始对照语言标准一个一个实现特性，并同步做单元测试。因为已经看到hello world,这一步虽然工作量有点大，但是因为有了前面的经验，可以很快。
4.解析声明是最复杂的，所以先写解析声明。
5.龙书是必需的，一个好的参考也非常重要（如GitHub - rui314/8cc: A Small C Compiler）。
6.尝试自举(因为我用的C++，所以没法自举)。


写一个编译器的坏处是，以后写一段代码都试图在脑子里面翻译成汇编。。。

1.初始状态，你必须有一本第二版的龙书。其它的答案可能会推荐《编译器实现》或者《编程语言实现模式》。《编译器实现》因为中文翻译的比较生硬，读了几章，发现还是龙书比较好，后来基本没有看《编译器实现》了。如果你是直接读原版，那么还是推荐龙书，毕竟都有决心读原版了，干脆彻底一点读龙书原版好了^_^。其实龙书并没有那么难，公式记不住，不理解，跳过就好了。《编程语言实现模式》其实很好的，各种实现方法都有所涉及。唯一不足的是，作者没有向《代码大全》的作者那样，对我耳提面命 ----- 直接告诉我怎么做就好了(相信这是新手最需要的...)。

2. 你必须有C11 standard。open-std 上面的draft就够了(http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1548.pdf)。(如果是其他语言的编译器，对应之。如果是自己设计，那么应该学着standard那样，将grammar，constraints等写下来)

3.一个简单的不带优化的编译器，基本只需要3个步骤：词法分析，语法分析，代码生成；对应到代码里面，就是3个class：Scanner, Parser, Generator; 

4.对于C语言编译器，支持预处理器，相当于又支持了一门新的简单语言了。所以一开始不必去支持预处理器。在测试时，只使用不包含预处理器的代码就好了。或者，用gcc进行预处理，将其输出作为你的编译器的输入。

5.在真的动手开始写Scanner之前，有必要读n1548的5.1节，对个C源程序的编译步骤有基本的了解。其实ad-hoc的词法解析一点也不比写一个split()函数更复杂，尤其是开始的时候不必去记录 Source Location(当然后面如果写错误提示，可以再加进来)。实现的时候，也不要吝惜内存了，直接将所有的token一次解析掉存起来就好。因为这对于后面Parser要回溯的时候会方便一点。

6. 已经得到Token List之后，就可以开始做Parser部分了。暂时不做错误恢复，即遇到错误即exit。这里有一个很实用的设计建议：准备好下面这四个函数：
	
	a. Peek() 返回下一个Token(只测试该Token，不向前移动Token List的offset指针)
	b. Next() 消费下一个Token
	c. Expect(expectedToken) , 这代替了下面的这段错误处理：
	   if (Peek() != expectedToken) {
		   Error("expect %s, but got %s\n", expectedToken, Peek());
	   }
	d. Try(expectedToken), 这代替了下面这段代码：
	   if (Peek() == expectedToken) {
			Next(); // 消费之
       }
	这很有用，因为Parser里面可能会有上百个这段代码，在我的Parser里面，有84个Expect()调用，81个Peek()(Peek和Test), 39个Next()，62个Try()。相信我，这4个函数会让你的代码干净一倍。

7. C的语言组成，大致可以分为 Expression, Declaration, Statement and Block 三个部分。这里面Statement and Block是最简单的，Declaration难一点。按照我前面的心得体验，应该从简单的入手，但是我们非先做Declaration不可。因为Statements都是在函数内的啊，不搞定Declaration就没法继续了呢～ 其实，Declaration也好做，对着n1548的7.A.2.2节一个一个将grammar翻译为Parser里面的逻辑就好了(是的，除去语义和类型检查，Parser就是真么简单)。做完Declaration，你还没有往AST上添加任何node，是的，仅仅是Declaration，是没有一行代码需要生成的。所有的成就都在符号表里面。这里又有tip：暂时不要做Initializer，它有一点烦人的(C标准把它搞得好繁琐)。

8. struct/union 类型；如果只是支持一个小小的子集，那么大可以跳过这一部分不做。struct会引入一些工作量，一方面，需要为tag(tag 和普通的identifier不在同一个命名空间)另开一个符号表(我使用一个小trick避免了这个麻烦)；另一方面，它也是使Initalizer变复杂的原因之一，尤其是匿名struct/union。tip：对struct/union的支持步骤是：普通嵌套的结构，匿名无tag的 struct成员，位域，union；这里把union放到最后是因为，它和struct除去存储布局之外，别无二致(所以你甚至不必区分这两个类型)；你也可以在任何一步就开始支持union ^_^

9. 数组和函数；除去作为sizeof关键字的操作数，数组总是会被cast成一个指针；你一定写过这样的代码：
typedef void (*func_t)(void);
func_t f = func;
f(); // 难道不应该是 (*f)(); ?
其实函数也是被cast成指针了，所以上面的调用方式都对，更微妙的是，任何一个函数调用都会被先cast成指针，再解引用(至少我的实现是这样的)；

10. storage 和 linkage；起初只实现所有的对象分配在栈空间；这会大大简化代码生成部分，因此对于“以最快速度看到hello world”是非常重要的；linkage对于前向声明是重要的，如果你没有打算支持，那么也可以跳过，等你看到hello world再回来支持，或者等你的函数和标准库的冲突了^_^

11. expression；这个最简单，该怎么样就怎么样=-=。tip：联合赋值运算符：
	a *= 5;
	a = a * 5;
是不是总是被告知效果和下面那行效果相等？那么不要害羞，就这么翻译！(嗯，这么做是会产生bug（如果左值表达式有副作用），但是可以通过额外的检查规避掉；对于带优化的编译器，这根本不是问题，因为它们怎么会对公共子表达式求两遍值呢？)

12.statement；这是我最喜欢的部分，不仅仅是因为它简单，而且让我明白那些控制语句是怎么生成到汇编代码的(对应请看龙书6.6和6.7节)；如最简单的while循环的展开：
	/*
	 * while (expression) statement
	 * 展开后：
	 * cond: 
	 *       if (expression) then
	 *           empty
	 *       else
	 *           goto end
	 *	 statement
	 *	 goto cond
	 * end:
	 */
这里，我将 if 语句保留为基本的翻译单元，因为将其他的控制结构翻译为 if 语句会带来很大的便利。tip:支持顺序：if-else, while/do-while, for, switch-case; 

这些基本是一个C语言Parser的动手步骤了，现在你可以parse这段代码了：
int main() {
    puts("hello world\n");
    return 0;
}
你可以手动将puts插入到符号表以应付过去(某些builtin的函数还真就是这么干的)，或者你就要实现对struct/union的支持， 不然是没有办法 #include <stdio.h> 的了。这里没有使用 printf，因为暂时没有必要实现变参函数。
这样，你与hello world只有一步之遥了：汇编代码生成。
// TODO(wgtdkp): 汇编代码生成
// End of update_1

// Update_2
// Date: 09/21/2016
因为按照"以最快的速度看到hello world"来做的话，语义检查和类型检查可以暂且放一放，或者只是实现parse过程中必不可少的一部分。下面是以x86-64 汇编代码生成为例，说说代码生成。这里又可以跳过中间代码生成，直接由AST生成汇编代码～

1. intel x86-64手册；显然这是必需的，虽然我拿到这3000多页的手册时，也是虎躯一震的。不过，实实在在地讲，我只看了大概30页的内容；更多的时候，我是对照着gcc生成的汇编代码照虎画猫; tip：对于某些指令，如乘除法，移位，对照gcc进行翻译是非常有效的；但你不应该企图生成像gcc那么高效的代码！(具体方法见下面)

2. System V x64 ABI；你必须至少看chapter 3(chapter 3就够用了， 不过只有30多页，放心吧^_^)；至少掌握stack frame的结构和对齐。注意x86-64的调用规约会稍微复杂一点，不过你可以做一些大胆的简化：
	a. scalar type (除去struct/union,剩下的都是)按照 ABI里面的就好；
	b. struct/union 是比较复杂的，这是可以直接按照stack传参(而不是寄存器传参去做)，毕竟又有多少代码会直接传递struct/union 呢？^_^,等到你决意要做一个full featured的编译器时，再来考虑它吧
可以参考这里Introduction to X86-64 Assembly for Compiler Writers

3. visitor 模式；相信这个不必赘述，取决于怎么使用它，可以有很多作用；比如Parser中会需要做常量表达式求值，我们会用到它；获得一个表达式的左值地址时，我们又需要用到它；(考虑你该如何翻译赋值表达式)

4.数据类型；在代码生成这一步，我们的数据类型只有3种：整型，浮点型，struct/union(集合)；我将能够用通用寄存器存储的数据称为整型，包括指针；struct/union的处理比较特殊，对于一个类型为struct/union的表达式，visit该表达式，总是得到此struct/union对象的地址值(存储于%rax寄存器中)；只要我们在所有代码中遵守这一规则，那么它确实很管用，即使会有一些冗余的拷贝；

5. 翻译函数定义；一个函数的翻译可以分为下面几个步骤：
	1.保存栈指针；
	2.确定函数参数的位置(在哪个寄存器或者stack上的位置)，将它们复制到当前stack frame的上，更新每个参数(object)的offset成员(object的地址)。更新当前stack frame的偏移量；
	3.确定当前作用域内的object的地址， 这只需要扫描当前scope内的所有object，并线性地分配到stack frame上面就好；注意不包括内层scope内的定义的object。这是一种优化，能够充分利用栈空间，而且实现更简单。更新当前的stack frame偏移量。
	4.翻译函数体；
	5.在return 语句和函数结尾处，恢复栈指针并退出函数；

6. 翻译函数调用；也可以分为下面几个步骤：
	1.确定函数地址；这可能是函数的名字，也可能是一个寄存器；这里就需要一个能够计算表达式左值地址的Evaluator了^_^（后面会讲到)；
	2.对函数参数求值，暂存之(push到stack上)；
	3.确定函数参数的位置，即，应该在哪个寄存器或stack的位置；拷贝参数值到对应位置；
	4.调整栈指针以正确地对齐(这个很重要，不然会有segment fault的，都是泪)；
	5.调用之～

7. 翻译赋值表达式；对左值表达式的赋值，需要获得左值表达式的地址，而不是值；因此我们需要一个 LValGenerator 来取得左值表达式的地址，然后将右操作数的值load到该地址中；

8. 翻译表达式；建议采用1-TOSCA方法，不懂的可以看看R大的回答寄存器分配问题？ - 编译器；这里的tip：不要被gcc生成的各种高效代码蛊惑了而去做大量的手动优化，那是一个很大的坑，尤其是我们没有生成中间代码，是做不到全局寄存器分配的效果的。

如果是用 Haskell 的话，三篇文章足矣。
prerequisite: 懂 state monad就行了

第一篇，《How to build a monadic interpreter in one day》http://citeseerx.ist.psu.edu/viewdoc/summary?doi=10.1.1.368.2522

跟着做，可以完成一个简单的backend， 也就是架构基本的AST 并执行的步骤。

然后到frontend， 也就是parser的部分你就会发现你看不懂了， 这个时候看第二篇。（因为该文的 parser 部分其实是 第二篇 的一个浓缩版，所以不看第二篇基本很难看懂这个部分）

第二篇，《Monadic Parser Combinator》 ，http://www.cs.nott.ac.uk/~pszgmh/monparsing.pdf

看了也就能对照第一篇，把 parser 写出来了， 然后就能和之前的backend 组合，完成一个基本的，完全由自己手写的，monadic的解释器（parser 和 backend 分别由一个自定义的 state monad 实现）。顺便加深对 monad 的理解。

看第二篇的时候，回过头对照第一篇看效果会更高，虽然逻辑一样，但第二篇是用 monad comprehension 的形式来写， 第一篇是用 do notation 来写。有的复杂的地方你两种方式对照看一下，会有茅塞顿开的效果。

第三篇，llvm的haskell 教程， Implementing a JIT Compiler with Haskell and LLVM ( Stephen Diehl ) ， 把你的backend 换成llvm. （注：事先对 llvm 不熟的话，可以和 hackage 上面 llvm-general, llvm-general-pure 这两个库的 wiki, 以及 LLVM Language Reference Manual对照着看）

至于frontend， 可以换成Parsec之类，但也可以就不断扩充之前自己写的版本。
