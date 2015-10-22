/**
* 编写自己的预处理器：
*	直接使用预处理器来控制调试用的代码
*	C++
*/

#define DEBUG
// TODO
...

#if defined(DEBUG)	// #if DEBUG > 0
// debugging code
...

#endif

/*********************使用预处理宏来控制调试用的代码**************************/
#define DEBUG
#if defined(DEBUG)
#define DebugCode(code_fragment) {code_fragment}
#else
#define DebugCode(code_fragment)
#endif
...

DebugCode(
	statement 1;
	statement 2;
	...
	statement n;
);
...


