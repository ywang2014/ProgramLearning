/**
	带有哨兵标记的forward指针移动算法
*/
switch(*forward++){
	case eof:
		if (isTailOfBufferA(forward)){
			LoadSecondBuffer();
			forward = bufferB;
		}
		else if (isTailOfBufferB(forward)){
			LoadFirstBuffer();
			forward = bufferA;
		}
		else{
			// 内部正常的eof标记，终止词法分析
			break;
		}
	case other:
		...
}