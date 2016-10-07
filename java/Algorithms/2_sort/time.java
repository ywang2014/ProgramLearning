public static double time(String alg, Comparable[] a){
	Stopwatch timer = new Stopwatch();
	if (alg.equals("Insertion")){
		Insertion.sort(a);
	}
	else if (alg.equals("Selection")){
		Selection.sort(a);
	}
	else if (alg.equals("Shell")){
		Shell.sort(a);
	} 
	else if (alg.equals("Merge")){
		Merge.sort(a);
	}
	else if (alg.equals("Quick")){
		Quick.sort(a);
	}
	else if (alg.equals("Heap")){
		Heap.sort(a);
	}
	
	return timer.elapsedTime();
}