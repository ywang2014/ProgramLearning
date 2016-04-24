/**
	计时脚手架
	
*/

while read(algrum, n, numtests)
	for (i = 0; i < n; i++){
		x[i] = i;
	}
	starttime = clock();
	for (testnum = 0; testnum < numtests; testnum++){
		for (i = 0; i < n; i++){
			switch (algnum){
				case 1:
					assert(binarysearch1(i) == i);
					break;
				case 2:
					assert(binarysearch2(i) == i);
			}
		}
	}
	clicks = clock() - starttime;
	print algnum, n, numtests, clicks, clicks/(1e9 * CLOCKS_PER_SEC * n * numtests)