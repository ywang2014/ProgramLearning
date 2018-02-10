/**
	ML语言风格的quicksort实现
*/
fun sort(inputFile, outputFile) = 
	let 
		val a = array(11, 0);
		fun readArray(inputFile) = ...
			... a ...;
		fun exchange(i, j) = 
			... a ...;
		fun quicksort(m, n) = 
			let
				val v = ...;
				fun partition(y, z) = 
					... a ... v ... exchange ...
			in 
				... a ... v ... partition ... quicksort
			end
	in
		... a ... readArray ... quicksort ...
	end;