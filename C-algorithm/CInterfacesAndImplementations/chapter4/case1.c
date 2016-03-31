/**
	异常优化样例程序
	
	找到所有的未处理的异常，并给出更有帮助的诊断信息
*/

#include <stdlib.h>
#include <stdio.h>
#include "except.h"

int main(int argc, char *argv[]){
	TRY
		edit(argc, argv);
	ELSE
		fprintf(stderr, "An internal error has occurred from which there is "
			"no recovery.\nPlease report this error to "
			"Technical Support at 800-777-1234.\nNote the "
			"following message, which will help our support "
			"staff\nfind the cause of this error.\n\n");
		RERAISE;
	END_TRY;
	return EXIT_SUCCESS;
}